#pragma once

#include <utility>

/**
 * ����ת��
 * 1. ���޸Ķ���
 * 2. ��������
 * 3. ���ƶ�����
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

// ��ζ���һ�����͵�f()�������Զ�������������������?
template <typename T>
void f(T&& val)
{
	g(std::forward<T>(val));	// g(static_cast<T&&>(val));
}

/**
 * 1. X&&������һ������Ϊ�ض����͵���ֵ���ã�ֻ�ܰ󶨵�һ�����ƶ�����: prvalue(��ʱ����)��xvalue(std::move())
 *	X&&���͵Ĳ���ת��ʱ��������ֵ�������壬�������Զ�ӵ���ƶ����壬�ƶ�����Ĵ�����Ҫstd::move(x)
 * 2. T&&��ģ�����������ת�����û��������á�T&&�������Զ�ӵ��ת�����壬��Ҫstd::forward<T>(x)
 */

/**
 * TΨһ�ƶ�Ϊref������
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

// ����ת����ʱ����
template <typename T>
void foo(T x)
{
	auto&& val = get(x);
	set(std::forward<decltype(val)>(val));
}

// ����ת���ɱ�ģ�����
template <typename... Ts>
void forwardToG(Ts&&... xs)
{
	g(std::forward<Ts>(xs)...);
}

// ������ֵ������ת��
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
 * ����ת����Ӧ���������۵�����
 1. ��ֵ���������۵�Ϊ��ֵ����
 2. ģ�������Ƶ�����: ת��������ʵ������ֵ���ã�ģ������Ƶ�ΪT&, Ϊ��ֵ���ã��Ƶ�ΪT&&
 */