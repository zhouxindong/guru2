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
 * ����trait��һ������: �ڱ������������ߵ����ͱ��ʽ���ᱻ���Թ���, ����ʧ�ܵ��±������
 * ��Ҫͨ�����岻ͬ�����ͺ��������Ӽ����������������
 */

template <typename T>
struct UnsignedT {
	using Type = IfThenElse<std::is_integral<T>::value && !std::is_same<T, bool>::value,
		typename std::make_unsigned<T>::type,
		T>;
};	// TrueType��FalseType������빹�죬�����������

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