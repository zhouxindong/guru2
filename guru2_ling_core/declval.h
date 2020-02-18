#pragma once
/**
 * std::declval<>()函数模板用于一个特定类型的对象引用的占位符
 * 只能用于非求值运算符(decltype, sizeof)
 */

#include <utility>
#include <type_traits>

template <
	typename T1, typename T2,
	typename RT = std::decay_t<decltype(true?std::declval<T1>():std::declval<T2>())>>
	RT max(T1 a, T2 b)
{
	return b < a ? a : b;
}

/**
 * declval()有意未给出定义，使得其只能用于decltype, sizeof等不需要定义的场合
 * 1. 对于引用类型，其返回类型为右值引用，这使得其可以用于无法正常从函数返回的情形，如抽象类类型或数组类型
 */
template <typename T>
std::add_rvalue_reference_t<T> declval2() noexcept;

template <typename T1, typename T2>
struct PlusResult {
	using Type = decltype(std::declval<T1>() + std::declval<T2>());
};

/**
 * std::declval<T>(): 产生一个对象(右值引用)，不调用任何构造函数或初始化
 可以在非求值表达式中用于处理任意类型的对象或函数
 template <typename T>
 add_rvalue_reference_t<T> declval() noexcept;
 1. 若T是普通类型或右值引用，结果为T&&
 2. 若T是左值引用，结果为T&
 3. 若T是void,，结果为void
 */

