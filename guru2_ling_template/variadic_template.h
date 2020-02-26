#pragma once

#include <iostream>

void print()
{
}

template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
	std::cout << firstArg << '\n';
	print(args...);
}

template <typename T>
void print2(T arg)
{
	std::cout << arg << '\n';
}

template <typename T, typename... Types>
void print2(T firstArg, Types... args)
{
	print2(firstArg);
	print2(args...);
}

//template <typename T, typename... Types>
//void print3(T firstArg, Types... args)
//{
//	std::cout << firstArg << '\n';
//	if (sizeof...(args) > 0)
//		print3(args...);
//}

// 1. variadic expression
template <typename... T>
void printDoubled(T const&... args)
{
	print(args + args...); // (args+args)...
}

// 2. variadic indices
template <typename C, typename... Idx>
void printElem(C const& coll, Idx... idx)
{
	print(coll[idx]...);
}
// printElem(coll, 2, 0, 3);

template<std::size_t... Idx, typename C>
void printIdx(C const& coll)
{
	print(coll[Idx]...);
}
// printIdx<2,0,3>(coll);

// 3. variadic class template
template <typename... Elements>
class Tuple;
// Tuple<int, std::string, char> t;

template <typename... Types>
class Variant;
// Variant<int, std::string, char> v;

template <std::size_t...>
struct Indices {};

template <typename T, std::size_t... Idx>
void printByIdx(T t, Indices<Idx...>)
{
	print(std::get<Idx>(t)...);
}
// printByIdx(arr, Indices<0,4,3>());

/**
 * 如果想获取参数包中的每个参数，只能将参数包递归地传递给类或函数来一一获取。
 * 每个包扩展都有一个模式，该模式被应用于参数包中的每个参数(在...之前)
 */

// 包扩展可用于任何逗号分隔列表语句中(相当于自动扩展每个元素组成逗号表达式)

/**
 * 对于一个参数包，除了sizeof...外，唯一能做的事情就是扩展
 扩展包时，要提供用于每个扩展元素的模式。在分解为构成的元素时，对每个元素应用模式。
 通过在模式右边放置一个省略号...来触发扩展操作
 (对模板参数包和函数参数包扩展)
 (扩展中的模式会独立地应用于包中的每个元素)
 */
template <typename T, typename... Args>
std::ostream&
print(std::ostream& os, const T& t, const Args&... rest)
{
	os << t << ", ";
	return print(os, debug_rep(rest)...);
}

template <typename... Args>
void fun(Args&&... args) // 右值引用，可以传递任意类型的实参
{
	work(std::forward<Args>(args)...); // 所有类型信息在调用work时都会保持原样
}