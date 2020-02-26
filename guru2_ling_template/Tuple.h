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

	Tuple(Head const& head, Tuple<Tail...> const& tail)
		: head(head), tail(tail)
	{
	}

	Tuple(Head const& head, Tail const&... tail)
		: head(head), tail(tail...)
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
class FrontT<Tuple<Head, Tail...>> {
public:
	using Type = Head;
};

template <typename Head, typename... Tail>
class PopFrontT<Tuple<Head, Tail...>> {
public:
	using Type = Tuple<Tail...>;
};

template <typename... Types, typename Element>
class PushFrontT<Tuple<Types...>, Element> {
public:
	using Type = Tuple<Element, Types...>;
};

template <typename... Types, typename Element>
class PushBackT<Tuple<Types...>, Element> {
public:
	using Type = Tuple<Types..., Element>;
};

/**
 * adding and removing from a Tuple
 */
template <typename... Types, typename V>
PushFront<Tuple<Types...>, V> pushFront(Tuple<Types...> const& tuple, V const& value)
{
	return PushFront<Tuple<Types...>, V>(value, tuple);
}

template <typename V>
Tuple<V> pushBack(Tuple<> const&, V const& value)
{
	return Tuple<V>(value);
}

template <typename Head, typename... Tail, typename V>
Tuple<Head, Tail..., V>
pushBack(Tuple<Head, Tail...> const& tuple, V const& value)
{
	return Tuple<Head, Tail..., V>(tuple.getHead(),
		pushBack(tuple.getTail(), value));
}

template <typename... Types>
PopFront<Tuple<Types...>>
popFront(Tuple<Types...> const& tuple)
{
	return tuple.getTail();
}

/**
 * Reversing a Tuple
 */
Tuple<> reverse(Tuple<> const& t)
{
	return t;
}

template <typename Head, typename... Tail>
Reverse<Tuple<Head, Tail...>> reverse(Tuple<Head, Tail...> const& t)
{
	return pushBack(reverse(t.getTail()), t.getHead());
}

/**
 * 另一个定义方式
 */
template <typename... Elements> // 变长模板声明
class Tuple2;

template <typename Head, typename... Tail>
class Tuple2<Head, Tail...> : private Tuple2<Tail...> // 递归的偏特化定义
{
	Head head;
};

template <>	// 边界条件
class Tuple2<> {};