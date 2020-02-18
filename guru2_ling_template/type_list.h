#pragma once
#include <type_traits>

template <typename... Elements>
class Typelist
{
};

/**
 * Front
 */
template <typename List>
class FrontT;

template <typename Head, typename... Tail>
class FrontT<Typelist<Head, Tail...>>
{
public:
	using Type = Head;
};

template <typename List>
using Front = typename FrontT<List>::Type;

/**
 * PopFront
 */
template <typename List>
class PopFrontT;

template <typename Head, typename... Tail>
class PopFrontT<Typelist<Head, Tail...>> {
public:
	using Type = Typelist<Tail...>;
};

template <typename List>
using PopFront = typename PopFrontT<List>::Type;

/**
 * PushFront
 */
template <typename List, typename NewElement>
class PushFrontT;

template <typename... Elements, typename NewElement>
class PushFrontT<Typelist<Elements...>, NewElement> {
public:
	using Type = Typelist<NewElement, Elements...>;
};

template <typename List, typename NewElement>
using PushFront = typename PushFrontT<List, NewElement>::Type;

/**
 * NthElement
 */
// recursive case
template <typename List, unsigned N>
class NthElementT : public NthElementT<PopFront<List>, N - 1>
{
};

// basis case
template <typename List>
class NthElementT<List, 0> : public FrontT<List>
{
};

template <typename List, unsigned N>
using NthElement = typename NthElementT<List, N>::Type;

/**
 * LargestType
 */
template <typename List>
class LargestTypeT;

template <typename List>
class LargestTypeT
{
private:
	using First = Front<List>;
	using Rest = typename LargestTypeT<PopFront<List>>::Type;

public:
	using Type = std::conditional_t<(sizeof(First) >= sizeof(Rest)), First, Rest>;
};

template <>
class LargestTypeT<Typelist<>>
{
public:
	using Type = char;
};

template <typename List>
using LargestType = typename LargestTypeT<List>::Type;

/**
 * IsEmpty
 */
template <typename List>
class IsEmpty
{
public:
	static constexpr bool value = false;
};

template <>
class IsEmpty<Typelist<>> {
public:
	static constexpr bool value = true;
};

/**
 * PushBack
 */
template <typename List, typename NewElement>
class PushBackT;

template <typename... Elements, typename NewElement>
class PushBackT<Typelist<Elements...>, NewElement>
{
public:
	using Type = Typelist<Elements..., NewElement>;
};

template <typename List, typename NewElement>
using PushBack = typename PushBackT<List, NewElement>::Type;
                                                                          
/**
 * Reverse
 */
template <typename List, bool Empty = IsEmpty<List>::value>
class ReverseT;

template <typename List>
using Reverse = typename ReverseT<List>::Type;

template <typename List>
class ReverseT<List, false> : public PushBackT<Reverse<PopFront<List>>, Front<List>>
{
};

template <typename List>
class ReverseT<List, true>
{
public:
	using Type = List;
};

/**
 * PopBack
 */
template <typename List>
class PopBackT {
public:
	using Type = Reverse<PopFront<Reverse<List>>>;
};

template <typename List>
using PopBack = typename PopBackT<List>::Type;

/**
 * AddConst
 */
template <typename T>
struct AddConst {
	using Type = T const;
};

/**
 * Transform(like map)
 */
template <typename List, template <typename T> class MetaFunc,
	bool Empty = IsEmpty<List>::value>
	class Transform;

template <typename List, template <typename T> class MetaFunc>
class Transform<List, MetaFunc, false>
	: public PushFront<typename Transform<PopFront<List>, MetaFunc>::Type,
	typename MetaFunc<Front<List>>::Type>
{
};

template <typename List, template <typename T> class MetaFunc>
class Transform<List, MetaFunc, true>
{
public:
	using Type = List;
};

/**
 * Accumlate(like reduce)
 * F(F(F(...F(I, T1),T2),...,Tn-1),Tn)(I «≥ı º÷µ)
 */
template <
	typename List,
	template <typename X, typename Y> class F,
	typename I,
	bool = IsEmpty<List>::value>
	class Accumulate;

template <
	typename List,
	template <typename X, typename Y> class F,
	typename I>
	class Accumulate<List, F, I, false>
	: public Accumulate<PopFront<List>, F, typename F<I, Front<List>>::Type>
{
};

template <
	typename List,
	template <typename X, typename Y> class F,
	typename I>
	class Accumulate<List, F, I, true>
{
public:
	using Type = I;
};
