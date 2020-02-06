#pragma once
#include <type_traits>

template <bool, typename TrueType, typename FalseType>
struct IfThenElse {
	using Type = TrueType;
};

template <typename TrueType, typename FalseType>
struct IfThenElse<false, TrueType, FalseType> {
	using Type = FalseType;
};

/**
 * 上述trait有一个问题: 在编译期条件两边的类型表达式都会被尝试构造, 构造失败导致编译错误
 * 需要通过定义不同的类型函数以增加间接性来避免编译错误
 */

template <typename T>
struct UnsignedT {
	using Type = IfThenElse<std::is_integral<T>::value && !std::is_same<T, bool>::value,
		typename std::make_unsigned<T>::type,
		T>;
};	// TrueType和FalseType都会编译构造，引发编译错误

template <typename T>
struct IdentityT {
	using Type = T;
};

template <typename T>
struct MakeUnsignedT {
	using Type = typename std::make_unsigned<T>::type;
};

template <typename T>
struct UnsignedT {
	using Type = typename IfThenElse<std::is_integral<T>::value && !std::is_same<T, bool>::value,
		MakeUnsignedT<T>,
		IdentityT<T>>::Type;
};