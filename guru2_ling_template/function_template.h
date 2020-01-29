#pragma once
#include <cstring>

// 1. pass by value or by reference?
// by value in general is often better
// if you want use reference, please use std::ref or std::cref

template <typename T>
T max(T a, T b)
{
	return b < a ? a : b;
}

template <typename T>
T* max(T* a, T* b)
{
	return *b < *a ? a : b;
}

char const* max(char const* a, char const* b)
{
	return std::strcmp(b, a) < 0 ? a : b;
}

/**
 * 从函数模板生成的函数永远不等于一个普通函数，即使拥有的类型和名称
 * 从函数模板生成的函数永远不会重写一个虚拟函数
 * 从构造函数模板生成的构造函数永远不能成为一个拷贝或移动构造函数
 * 从赋值函数模板生成的赋值函数也永远不能成为一个拷贝或移动赋值函数
 */

// 函数重载可以透明地对特定类型进行算法定制
template <typename T>
void quickExchange(T* a, T* b)
{
	T tmp(*a);
	*a = *b;
	*b = tmp;
}

template <typename T>
void quickExchange(Array<T>* a, Array<T>* b)
{
	a->exchangeWith(b);
}