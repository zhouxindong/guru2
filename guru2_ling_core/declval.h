#pragma once
/**
 * std::declval<>()函数模板用于一个特定类型的对象引用的占位符
 * 只能用于非求值运算符
 */

#include <utility>

template <
	typename T1, typename T2,
	typename RT = std::decay_t<decltype(true?std::declval<T1>():std::declval<T2>())>>
	RT max(T1 a, T2 b)
{
	return b < a ? a : b;
}
