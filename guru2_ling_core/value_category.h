#pragma once
#include <type_traits>
#include <utility>

/**
 * lvalues
 * 1. ��������ָ�ɱ��ʽ
 * 2. *
 * 3. �ַ�������ֵ
 * 4. ������ֵ���õĺ�������
 */

/**
 * prvalues(����ֵ)
 * 1. ����ֵ(���ַ�������ֵ)���ʽ
 * 2. ȡַ&
 * 3. �������������
 * 4. ���ط��������͵ĺ�������
 * 5. lambda���ʽ
 */

/**
 * xvalues(����ֵ)
 * 1. ������ֵ���õĺ�������(std::move())
 * 2. ת��Ϊ��ֵ����
 * 3. ע��: ��������Ϊ��ֵ���ã����������Ϊ��ֵ����Ҫ������Ϊ��ֵ����ʱ����Ҫstd::move()
 */

/**
 * ��Ҫǿ�����ǣ�����ֵ���඼����Եı��ʽ������ֵ��ʵ��
 * ����: һ����������һ����ֵ
 int x = 3; // x�Ǳ���������һ����ֵ��3��һ��prvalue��������ʼ������x
 int y = x; // x��һ����ֵ��ת��Ϊһ��prvalue��������ʼ������y
 */

int f(int const&);
int r = f(3);
// f����һ�����ã�3��prvalue����ʱ����һ����ʱ���󣬳�ʼΪ3��Ȼ�����ʱ���󴫵ݸ���������

class X {};
X v;
X const c;

void f(X const&);	// #1, �����κ�ֵ���͵ı��ʽ
void f(X&&);		// #2, ����prvalue��xvalue���ʽ����#1�����ֱ��ʽ�Ǹ��õ�ƥ��

f(v);	// #1, modifiable lvalue
f(c);	// #1, nonmodifiable lvalue
f(X());	// #2, prvalue, ��C++17���Թ淶Ϊxvalue������Ϊ�������Ż�������ֱ�ӱ�����ʼ��
f(std::move(v));	// #2, xvalue

int& lvalue();
int&& xvalue();
int prvalue();

std::is_same_v<decltype(lvalue()), int&>
std::is_same_v<decltype(xvalue()), int&&>
std::is_same_v<decltype(prvalue()), int>