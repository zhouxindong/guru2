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

/**
 * ����һ��������������sizeof...�⣬Ψһ���������������չ
 ��չ��ʱ��Ҫ�ṩ����ÿ����չԪ�ص�ģʽ���ڷֽ�Ϊ���ɵ�Ԫ��ʱ����ÿ��Ԫ��Ӧ��ģʽ��
 ͨ����ģʽ�ұ߷���һ��ʡ�Ժ�...��������չ����
 (��ģ��������ͺ�����������չ)
 (��չ�е�ģʽ�������Ӧ���ڰ��е�ÿ��Ԫ��)
 */
template <typename T, typename... Args>
std::ostream&
print(std::ostream& os, const T& t, const Args&... rest)
{
	os << t << ", ";
	return print(os, debug_rep(rest)...);
}

template <typename... Args>
void fun(Args&&... args) // ��ֵ���ã����Դ����������͵�ʵ��
{
	work(std::forward<Args>(args)...); // ����������Ϣ�ڵ���workʱ���ᱣ��ԭ��
}

/**
 * 
 1. ���Ͳ�����
 2. �����Ͳ�����
 3. ģ�������
 */
template <typename I, template<typename> class... B>
struct Container {};

template <typename I, template<typename> class A, template<typename> class... B>
struct Container<I, A, B...>
{
	A<I> a;
	Container<I, B...> b;
};

template <typename I>
struct Container<I> {};

/**
 * ��һ�ֱ䳤ģ������ݹ鶨�������
 */
template <typename... T>
struct MultiTypes;

template <typename T1, typename... T>
struct MultiTypes<T1, T...> : public MultiTypes<T...>
{
	T1 t1;	// std::decay_t<T1> t1;
	MultiTypes<T1, T...>(T1 a, T... b) :
		t1(a), MultiTypes<T...>(b...) {}
};

template <>
struct MultiTypes<>
{
};

template <template <typename...> class VariadicType, typename... Args>
VariadicType Build(Args&&... args)
{
	return VariadicType<Args...>(std::forward<Args>(args)...); // Ҫע��Ψһ�����ƶ�Ϊ���õ�����
															   // ���ܻ��ö���ĳ�Ա��Ϊ��Ч������
}