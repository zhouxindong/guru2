#pragma once
#include <iostream>

// 传递原始数组或字符串字面量给模板时，需要特别注意
/**
 * 1. 如果模板参数声明为引用，则实参不会decay: "hello" -> char const[6]
 * 2. 如果模板参数声明为值传递，"hello" -> char const*
 */

// 针对原始数组或字符串字面量，可以定义特定的模板函数加以处理
template <typename T, int N, int M>
bool less(T(&a)[N], T(&b)[M])
{
	for (int i = 0; i < N && i < M; ++i)
	{
		if (a[i] < b[i]) return true;
		if (b[i] < a[i]) return false;
	}
	return N < M;
}

// int x[] = { 1,2,3 };
// int y[] = { 1,2,3,4,5 };
// std::cout << less(x,y);

template <typename T>
struct MyClass;	// primary template

template <typename T, std::size_t SZ>
struct MyClass<T[SZ]>	// partial specialization for arrays of known bounds
{
	static void print()
	{
		std::cout << "print() for T[" << SZ << "]\n";
	}
};

template <typename T, std::size_t SZ>
struct MyClass<T(&)[SZ]>	// partial spec. for references to arrays of known bounds
{
	static void print()
	{
		std::cout << "print() for T(&)[" << SZ << "]\n";
	}
};

template <typename T>
struct MyClass<T[]>	// partial spec. for arrays of unknown bounds
{
	static void print()
	{
		std::cout << "print() for T[]\n";
	}
};

template <typename T>
struct MyClass<T(&)[]>	// partial spec. for references to arrays of unknown bounds
{
	static void print()
	{
		std::cout << "print() for T(&)[]\n";
	}
};

template <typename T>
struct MyClass<T*>	// partial spec. for pointers
{
	static void print()
	{
		std::cout << "print() for T*\n";
	}
};