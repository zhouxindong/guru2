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
 * 从函数模板生成的函数永远不等于一个普通函数，即使拥有的类型和名称相同
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

template <typename T>
int f(T)		// #1
{
	return 1;
}

template <typename T>
int f(T*)		// #2
{
	return 2;
}

template<> 
int f(int)		// specialization of #1
{
	return 3;
}

template<>
int f(int*)		// specialization of #2
{
	return 4;
}

/**
 * 两种类型的函数重载
 */
void f(int);
void f(char const*);

template <typename T> void f(T*);
template <typename T> void f(Array<T>);

/**
 * 使用右值引用的函数重载
 */
template <typename T>
void f(T&&); // 绑定到非const右值

template <typename T>
void f(const T&);	// 左值和const右值


/**
 * 利用特定类型的更多属性信息，通过重载实现更好的算法实现
 */
template <typename T>
void swap(T& x, T& y)
{
	T tmp(x);
	x = y;
	y = tmp;
}

template <typename T>
void swap(Array<T>& x, Array<T>& y)
{
	swap(x.ptr, y.ptr);
	swap(x.len, y.len);
	{
	default:
		break;
	}
}

/**
 * 对于那些无法以类型的属性形式表示的概念，如何实现特化? Tag Dispatching
 * 针对每个Tag，实现其算法。类型包含TAG类型成员
 */
template <typename Iterator, typename Distance>
void advanceIterImpl(Iterator& x, Distance n, std::input_iterator_tag)
{
	while (n > 0)
	{
		++x;
		--n;
	}
}

template <typename Iterator, typename Distance>
void advanceIterImpl(Iterator& x, Distance n, std::random_access_iterator_tag)
{
	x += n;
}

template <typename Iterator, typename Distance>
void advanceIter(Iterator& x, Distance n)
{
	advanceIterImpl(x, n, typename std::iterator_traits<Iterator>::iterator_category()); 
}

/**
 * 函数模板可以被另一个模板或普通函数重载，只要参数的类型或数量不同。
 重载匹配
 1. 候选函数包括所有模板实参推断成功的函数模板实例
 2. 如果有多个匹配相同，普通函数优先，更特化的模板函数优先
 */

/**
 * 定义函数模板特化
 必须为原模板中的每个模板参数都提供实参
 (特化的类型必须与声明中的模板中对应的类型匹配，只是替换T本身)
 注意: 一个特化版本本质上是一个实例，而非函数名的一个重载版本。
 */
template <typename T>
int compare(const T&, const T&);

template<>
int compare(const char* const& p1, const char* const& p2); // T -> const char*