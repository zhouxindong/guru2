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

/**
 * 模板参数的推演中的类型转换只有:
 const忽略，数组和函数退化为相应的指针
 不会应用任何隐式的类型转换，或自定义的类型转换，而是直接推演为精确的类型
 */

/**
 * 
 */