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
 * ������ȡ�������е�ÿ��������ֻ�ܽ��������ݹ�ش��ݸ��������һһ��ȡ��
 * ÿ������չ����һ��ģʽ����ģʽ��Ӧ���ڲ������е�ÿ������(��...֮ǰ)
 */

// ����չ�������κζ��ŷָ��б������(�൱���Զ���չÿ��Ԫ����ɶ��ű��ʽ)