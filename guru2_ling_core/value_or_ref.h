#pragma once
#include <iostream>
#include <type_traits>

/**
 * 1. by value
 * copy ctor.
 * decay: 内置数组转换为指针，函数转换为函数指针
 * const, volatile限定符忽略
 */
template <typename T>
void printV(T arg) {
}

void foo()
{
	std::string const c = "hi";
	printV(c);		// std::string
	printV("hi");	// decay to char const*
	int arr[4];
	printV(arr);	// decay to int*
}

/**
 * 2. by ref
 * no copy, no decay
 * const, volatile限定符保留
 */
template <typename T>
void printR(T const& arg)
{
}

void foo2()
{
	std::string const c = "hi";
	printR(c);	// T -> std::string
	printR("hi");	// T -> char[3], arg -> char const(&)[3]
	int arr[4];
	printR(arr);	// T -> int[4], arg -> int const(&)[4]
}

template <typename T>
void outR(T& arg) {
	if (std::is_array<T>::value) {
		std::cout << "got array of " << std::extent<T>::value << " elems\n";
	}
}

std::string returnConstString()
{
	return std::string();
}

void foo3()
{
	std::string const c = "hi";
	outR(c);		// T -> std::string const
	outR(returnConstString()); // T-> std::string const
	outR(std::move(c));	// T-> std::string const
	outR("hi");		// T-> char const[3]
}

/**
 * 1. by value
 * 简单，decay字符串字面值和原始数组
 * 但对于大对象性能有损。调用者仍可以使用std::cref(), std::ref()来达到传递ref的作用
 */
/**
 * 2. by ref(&,&&)
 * 对于大对象性能更好
 * (1)已有对象为lvalue ref
 * (2)临时对象prvalue, 可移动对象xvalue为rvalue ref
 * (3)再者都可以使用forwarding ref
 * 不会decay，所以对于字符串字面值或原始数组要格外小心。
 * 对于forwarding ref, T可能会推断为ref. 特别是T可能会用于返回类型时(T唯一会被推断为引用的情形)。
 */