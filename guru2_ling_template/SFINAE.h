#pragma once

// SFINAE用于函数模板的不同实现选择
/**
 * 利用decltype指定模板参数的约束
 * 在decltype的开始处定义所有约束(转换为void防止逗号运算符重载)
 * 最后定义一个对象用于真实的返回类型
 */
template <typename T>
auto len(T const& t) -> decltype((void)(t.size()), T::size_type())
{
	return t.size();
}

/**
 * 四种基于编译期条件启动或禁用特定语句的技术
 * 1. 局部特化
 * 2. SFINAE
 * 3. std::enable_if
 * 4. if constexpr(...)
 */

/**
 * SFINAE原本只是函数重载匹配的一种机制，允许类型替换失败后选择其他重载版本
 * 也可用于编译期技术来检测特定类型或表达式是否有效: 类型是否有特定的成员、支持特定的操作
 * 1. SFINAE函数重载
 * 2. SFINAE局部特化
 */

/**
 * 1. SFINAE函数重载
 */
#include <type_traits>

template <typename T>
struct IsDefaultConstructible {
private:
	// must template for U, not directly T(如果使用T则T实例化时test函数同时实例化，构造无效时编译错误)
	template <typename U, typename = decltype(U())>	
	static char test(void*);

	template <typename>
	static long test(...);

public:
	static constexpr bool value = std::is_same<decltype(test<T>(nullptr)), char>::value;
};

template <typename T>
struct IsDefaultConstructible2 {
private:
	template <typename U, typename = decltype(U())>
	static std::true_type test(void*);

	template <typename>
	static std::false_type test(...);

public:
	using Type = decltype(test<T>(nullptr));
};

/**
 * 2. SFINAE局部特化
 */

// 适用于任意数量的模板参数
template <typename...> 
using VoidT = void; // std::void_t

template <typename, typename = VoidT<>>
struct IsDefaultConstructible3 : std::false_type
{
};

// VoidT<>可以容纳任意数目的编译期约束验证
template <typename T>
struct IsDefaultConstructible3<T, VoidT<decltype(T())>> : std::true_type
{ 
};

/**
 * SFINAE traits
 */
template <typename, typename, typename = std::void_t<>>
struct HasPlusT : std::false_type
{
};

template <typename T1, typename T2>
struct HasPlusT<T1, T2, std::void_t<decltype(std::declval<T1>() + std::declval<T2>())>>
	: std::true_type
{
};

template <typename T1, typename T2, bool = HasPlusT<T1, T2>::value>
struct PlusResultT {
	using Type = decltype(std::declval<T1>() + std::declval<T2>());
};

template <typename T1, typename T2>
struct PlusResultT<T1, T2, false>{
};