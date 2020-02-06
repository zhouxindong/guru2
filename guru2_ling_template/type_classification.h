#pragma once
#include <cstddef>
#include <type_traits>

template <typename T>
struct IsFundaT : std::false_type{ };

#define  MK_FUNDA_TYPE(T)		\
	template<> struct IsFundaT<T> : std::true_type { };

MK_FUNDA_TYPE(void)

MK_FUNDA_TYPE(bool)
MK_FUNDA_TYPE(char)
MK_FUNDA_TYPE(signed char)
MK_FUNDA_TYPE(unsigned char)
MK_FUNDA_TYPE(wchar_t)
MK_FUNDA_TYPE(char16_t)
MK_FUNDA_TYPE(char32_t)

MK_FUNDA_TYPE(signed short)
MK_FUNDA_TYPE(unsigned short)
MK_FUNDA_TYPE(signed int)
MK_FUNDA_TYPE(unsigned int)
MK_FUNDA_TYPE(signed long)
MK_FUNDA_TYPE(unsigned long)
MK_FUNDA_TYPE(signed long long)
MK_FUNDA_TYPE(unsigned long long)

MK_FUNDA_TYPE(float)
MK_FUNDA_TYPE(double)
MK_FUNDA_TYPE(long double)

MK_FUNDA_TYPE(std::nullptr_t)

#undef MK_FUNDA_TYPE

template <typename T>
struct IsPointerT : std::false_type {};

template <typename T>
struct IsPointerT<T*> : std::true_type {
	using BaseT = T;
};

template <typename T>
struct IsLValueReferenceT : std::false_type {};

template <typename T>
struct IsLValueReferenceT<T&> : std::true_type {
	using BaseT = T;
};

template <typename T>
struct IsRValueReference : std::false_type {};

template <typename T>
struct IsRValueReference<T&&> : std::true_type {
	using BaseT = T;
};

template <typename T>
struct IsArrayT : std::false_type {
};

template <typename T, std::size_t N>
struct IsArrayT<T[N]> : std::true_type {
	using BaseT = T;
	static constexpr std::size_t size = N;
};

template <typename T>
struct IsArrayT<T[]> : std::true_type {
	using BaseT = T;
	static constexpr std::size_t size = 0;
};

template <typename T>
struct IsPointerToMemberT : std::false_type {
};

template <typename T, typename C>
struct IsPointerToMemberT<T C::*> : std::true_type {
	using MemberT = T;
	using ClassT = C;
};

template <typename T>
struct IsFunctionT : std::false_type {
};

template <typename R, typename... Params>
struct IsFunctionT<R(Params...)> : std::true_type {
	using Type = R;
	using ParamsT = TypeList<Params...>;
};

template <typename T, typename = std::void_t<>>
struct IsClassT : std::false_type {
};

template <typename T>
struct IsClassT<T, std::void_t<int T::*>> : std::true_type {
};