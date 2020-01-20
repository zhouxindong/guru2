#pragma once
// 1. by reference
/**
 * 实参与形参必须严格匹配
 */

// 2. by value
/**
 * decay: const或volatile忽略，引用转换为引用类型，数组或函数转换为相应的指针类型
 */

// 3. deducing the Return Type
template <typename T1, typename T2>
auto max(T1 a, T2 b)	// C++14
{
	return b < a ? a : b;
}

template <typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(b < a ? a : b)	// C++11
{
	return b < a ? a : b;
}