#pragma once
#include <type_traits>

template <typename... Types>
class Tuple;

template <typename Head, typename... Tail>
class Tuple<Head, Tail...>
{
private:
	Head head;
	Tuple<Tail...> tail;

public:
	Tuple() {
	}

	// Tuple<int, double, std::string> t(17, 3.14, "Hello");
	Tuple(Head const& head, Tuple<Tail...> const& tail)
		: head(head), tail(tail)
	{
	}

	template <typename VHead, typename... VTail,
		typename = std::enable_if_t<sizeof...(VTail) == sizeof...(Tail)>>
	Tuple(VHead&& vhead, VTail&&... vtail)
		: head(std::forward<VHead>(vhead)),
		tail(std::forward<VTail>(vtail)...)
	{
	}

	template <typename VHead, typename... VTail,
		typename = std::enable_if_t<sizeof...(VTail) == sizeof...(Tail)>>
	Tuple(Tuple<VHead, VTail...> const& other)
		: head(other.getHead()), tail(other.getTail())
	{
	}

	Head& getHead()
	{
		return head;
	}

	Head const& getHead() const
	{
		return head;
	}

	Tuple<Tail...>& getTail()
	{
		return tail;
	}

	Tuple<Tail...> const& getTail() const
	{
		return tail;
	}
};

template <>
class Tuple<> {
	// no storage required
};

/**
 * TupleGet
 */
template <unsigned N>
struct TupleGet {
	template <typename Head, typename... Tail>
	static auto apply(Tuple<Head, Tail...> const& t)
	{
		return TupleGet<N - 1>::apply(t.getTail());
	}
};

template <>
struct TupleGet<0>
{
	template <typename Head, typename... Tail>
	static Head const& apply(Tuple<Head, Tail...> const& t)
	{
		return t.getHead();
	}
};

/**
 * wrapper, so can parial specialization of function template
 */
template <unsigned N, typename... Types>
auto get(Tuple<Types...> const& t)
{
	return TupleGet<N>::apply(t);
}

template <typename... Types>
auto makeTuple(Types&&... elems)
{
	return Tuple<std::decay_t<Types>...>(std::forward<Types>(elems)...);
}

/**
 * basic Tuple operations
 */
bool operator == (Tuple<> const&, Tuple<> const&)
{
	return true;
}

template <typename Head1, typename... Tail1,
		  typename Head2, typename... Tail2,
		  typename = std::enable_if_t<sizeof...(Tail1) == sizeof...(Tail2)>>
	bool operator == (Tuple<Head1, Tail1...> const& lhs,
		Tuple<Head2, Tail2...> const& rhs)
{
	return lhs.getHead() == rhs.getHead() &&
		lhs.getTail() == rhs.getTail();
}

/**
 * Output
 */
#include <iostream>
void printTuple(std::ostream& strm, Tuple<> const&, bool isFirst = true)
{
	strm << (isFirst ? '(' : ')');
}

template <typename Head, typename... Tail>
void printTuple(std::ostream& strm, Tuple<Head, Tail...> const& t,
	bool isFirst = true)
{
	strm << (isFirst ? "(" : ", ");
	strm << t.getHead();
	printTuple(strm, t.getTail(), false);
}

template <typename... Types>
std::ostream& operator << (std::ostream& strm, Tuple<Types...> const& t)
{
	printTuple(strm, t);
	return strm;
}

/**
 * algorithm
 */
#include "type_list.h"

template <>
struct IsEmpty<Tuple<>> {
	static constexpr bool value = true;
};

template <typename Head, typename... Tail>
class Front<Tuple<Head, Tail...>> {
public:
	using Type = Head;
};

template <typename Head, typename... Tail>
class PopFront<Tuple<Head, Tail...>> {
public:
	using Type = Tuple<Tail...>;
};

template <typename... Types, typename Element>
class PushFront<Tuple<Types...>, Element> {
public:
	using Type = Tuple<Element, Types...>;
};

template <typename... Types, typename Element>
class PushBack<Tuple<Types...>, Element> {
public:
	using Type = Tuple<Types..., Element>;
};

/**
 * adding and removing from a Tuple
 */
//template <typename... Types, typename Element>
//using PushFrontT = typename PushFront<Tuple<Types...>, Element>::Type;

template <typename... Types, typename V>
typename PushFront<Tuple<Types...>, V>::Type pushFront(Tuple<Types...> const& tuple, V const& value)
{
	return typename PushFront<Tuple<Types...>, V>::Type(value, tuple);
}