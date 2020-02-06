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
class Front;

template <typename Head, typename... Tail>
class Front<Typelist<Head, Tail...>>
{
public:
	using Type = Head;
};

/**
 * PopFront
 */
template <typename List>
class PopFront;

template <typename Head, typename... Tail>
class PopFront<Typelist<Head, Tail...>> {
public:
	using Type = Typelist<Tail...>;
};

/**
 * PushFront
 */
template <typename List, typename NewElement>
class PushFront;

template <typename... Elements, typename NewElement>
class PushFront<Typelist<Elements...>, NewElement> {
public:
	using Type = Typelist<NewElement, Elements...>;
};

/**
 * NthElement
 */
// recursive case
template <typename List, unsigned N>
class NthElement : public NthElement<PopFront<List>, N - 1>
{
};

// basis case
template <typename List>
class NthElement<List, 0> : public Front<List>
{
};

/**
 * LargestType
 */
template <typename List>
class LargestType;

template <typename List>
class LargestType
{
private:
	using First = Front<List>;
	using Rest = typename LargestType<PopFront<List>>::Type;

public:
	using Type = std::conditional_t<(sizeof(First) >= sizeof(Rest)), First, Rest>;
};

template <>
class LargestType<Typelist<>>
{
public:
	using Type = char;
};

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
class PushBack;

template <typename... Elements, typename NewElement>
class PushBack<Typelist<Elements...>, NewElement>
{
public:
	using Type = Typelist<Elements..., NewElement>;
};
                                                                          
/**
 * Reverse
 */
template <typename List, bool Empty = IsEmpty<List>::value>
class Reverse;

template <typename List>
class Reverse<List, false> : public PushBack<Reverse<PopFront<List>>, Front<List>>
{
};

template <typename List>
class Reverse<List, true>
{
public:
	using Type = List;
};

/**
 * PopBack
 */
template <typename List>
class PopBack {
public:
	using Type = Reverse<PopFront<Reverse<List>>>;
};

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
