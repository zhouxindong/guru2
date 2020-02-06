#pragma once
#include <iostream>
#include <type_traits>

/**
 * 1. by value
 * copy ctor.
 * decay: ��������ת��Ϊָ�룬����ת��Ϊ����ָ��
 * const, volatile�޶�������
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
 * const, volatile�޶�������
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
 * �򵥣�decay�ַ�������ֵ��ԭʼ����
 * �����ڴ�����������𡣵������Կ���ʹ��std::cref(), std::ref()���ﵽ����ref������
 */
/**
 * 2. by ref(&,&&)
 * ���ڴ�������ܸ���
 * (1)���ж���Ϊlvalue ref
 * (2)��ʱ����prvalue, ���ƶ�����xvalueΪrvalue ref
 * (3)���߶�����ʹ��forwarding ref
 * ����decay�����Զ����ַ�������ֵ��ԭʼ����Ҫ����С�ġ�
 * ����forwarding ref, T���ܻ��ƶ�Ϊref. �ر���T���ܻ����ڷ�������ʱ(TΨһ�ᱻ�ƶ�Ϊ���õ�����)��
 */