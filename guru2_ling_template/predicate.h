#pragma once
template <bool val>
struct BoolConstant {
	using Type = BoolConstant<val>;
	static constexpr bool value = val;
};

using TrueType = BoolConstant<true>;
using FalseType = BoolConstant<false>;

template <typename T1, typename T2>
struct IsSame {
	static constexpr bool value = false;
};

template <typename T>
struct IsSame<T, T> {
	static constexpr bool value = true;
};

template <typename T1, typename T2>
struct IsSame2 : FalseType {
};

template <typename T>
struct IsSame2 : TrueType {
};