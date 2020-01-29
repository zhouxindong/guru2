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
 * �Ӻ���ģ�����ɵĺ�����Զ������һ����ͨ��������ʹӵ�е����ͺ�����
 * �Ӻ���ģ�����ɵĺ�����Զ������дһ�����⺯��
 * �ӹ��캯��ģ�����ɵĹ��캯����Զ���ܳ�Ϊһ���������ƶ����캯��
 * �Ӹ�ֵ����ģ�����ɵĸ�ֵ����Ҳ��Զ���ܳ�Ϊһ���������ƶ���ֵ����
 */

// �������ؿ���͸���ض��ض����ͽ����㷨����
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