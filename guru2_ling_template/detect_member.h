#pragma once
#include <type_traits>

/**
 * 检测T是否有size_type类型定义
 */
template <typename, typename = std::void_t<>>
struct HasSizeType : std::false_type
{
};

template <typename T>
struct HasSizeType<T, std::void_t<typename T::size_type>> : std::true_type
{
};

#define DEFINE_HAS_TYPE(MemType)														\
	template <typename, typename = std::void_t<>>										\
	struct HasTypeT_##MemType : std::false_type{};										\
	template <typename T>																\
	struct HasTypeT_##MemType<T, std::void_t<typename T::MemType>> : std::true_type{} //; intentionally skipped

DEFINE_HAS_TYPE(value_type);

// HasTypeT_value_type<int>::value; // false
// HasTypeT_value_type<std::vector>::value; // true

/**
 * single member(only one name)
 */
#define DEFINE_HAS_MEMBER(Member)		\
	template <typename, typename = std::void_t<>>	\
	struct HasMemberT_##Member : std::false_type{};	\
	template <typename T>				\
	struct HasMemberT_##Member<T, std::void_t<decltype(&T::Member)>> : std::true_type{} //; intentionally skipped

/**
 * can used for overload functions
 */
template <typename, typename = std::void_t<>>
struct HasBeginT : std::false_type
{
};

template <typename T>
struct HasBeginT<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type
{
};

template <typename, typename, typename = std::void_t<>>
struct HasLessT : std::false_type
{
};

template <typename T1, typename T2>
struct HasLessT<T1, T2, std::void_t<decltype(std::declval<T1>()
	< std::declval<T2>())>> : std::true_type
{
};