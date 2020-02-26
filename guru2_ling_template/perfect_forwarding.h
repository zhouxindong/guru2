#pragma once

#include <utility>

/**
 * 完美转发
 * 1. 可修改对象
 * 2. 常量对象
 * 3. 可移动对象
 */
class X {
};

void g(X&) {}
void g(X const&) {}
void g(X&&) {}

void f(X& val) {
	g(val);
}

void f(X const& val) {
	g(val);
}

void f(X&& val) {
	g(std::move(val));
}

// 如何定义一个泛型的f()，可以自动处理上述三种情形呢?
template <typename T>
void f(T&& val)
{
	g(std::forward<T>(val));	// g(static_cast<T&&>(val));
}

/**
 * 1. X&&，声明一个参数为特定类型的右值引用，只能绑定到一个可移动对象: prvalue(临时对象)，xvalue(std::move())
 *	X&&类型的参数转发时本身是左值引用语义，并不会自动拥有移动语义，移动语义的传递需要std::move(x)
 * 2. T&&，模板参数声明，转发引用或万能引用。T&&并不会自动拥有转发语义，需要std::forward<T>(x)
 */

/**
 * T唯一推断为ref的情形
 */
template <typename T>
void passR(T&& arg)	// arg is a forwarding reference
{
	T x;	// for passed lvalues, x is a reference, which requires an initializer

}

void foo()
{
	passR(42);	// T -> int
	int i;
	passR(i);	// ERROR! T -> int&
}

// 完美转发临时对象
template <typename T>
void foo(T x)
{
	auto&& val = get(x);
	set(std::forward<decltype(val)>(val));
}

// 完美转发可变模板参数
template <typename... Ts>
void forwardToG(Ts&&... xs)
{
	g(std::forward<Ts>(xs)...);
}

// 带返回值的完美转发
template <typename... Ts>
auto forwardToG11(Ts&&... xs) -> decltype(g(std::forward<Ts>(xs)...))
{
	return g(std::forward<Ts>(xs)...);
}

template <typename... Ts>
decltype(auto) forwardToG14(Ts&&... xs)
{
	return g(std::forward<Ts>(xs)...);
}

/**
 * 完美转发中应用了引用折叠规则
 1. 左值引用总是折叠为左值引用
 2. 模板类型推导规则: 转发函数的实参是左值引用，模板参数推导为T&, 为右值引用，推导为T&&
 */