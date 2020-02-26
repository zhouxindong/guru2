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
 * �Ӻ���ģ�����ɵĺ�����Զ������һ����ͨ��������ʹӵ�е����ͺ�������ͬ
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

template <typename T>
int f(T)		// #1
{
	return 1;
}

template <typename T>
int f(T*)		// #2
{
	return 2;
}

template<> 
int f(int)		// specialization of #1
{
	return 3;
}

template<>
int f(int*)		// specialization of #2
{
	return 4;
}

/**
 * �������͵ĺ�������
 */
void f(int);
void f(char const*);

template <typename T> void f(T*);
template <typename T> void f(Array<T>);

/**
 * ʹ����ֵ���õĺ�������
 */
template <typename T>
void f(T&&); // �󶨵���const��ֵ

template <typename T>
void f(const T&);	// ��ֵ��const��ֵ


/**
 * �����ض����͵ĸ���������Ϣ��ͨ������ʵ�ָ��õ��㷨ʵ��
 */
template <typename T>
void swap(T& x, T& y)
{
	T tmp(x);
	x = y;
	y = tmp;
}

template <typename T>
void swap(Array<T>& x, Array<T>& y)
{
	swap(x.ptr, y.ptr);
	swap(x.len, y.len);
	{
	default:
		break;
	}
}

/**
 * ������Щ�޷������͵�������ʽ��ʾ�ĸ�����ʵ���ػ�? Tag Dispatching
 * ���ÿ��Tag��ʵ�����㷨�����Ͱ���TAG���ͳ�Ա
 */
template <typename Iterator, typename Distance>
void advanceIterImpl(Iterator& x, Distance n, std::input_iterator_tag)
{
	while (n > 0)
	{
		++x;
		--n;
	}
}

template <typename Iterator, typename Distance>
void advanceIterImpl(Iterator& x, Distance n, std::random_access_iterator_tag)
{
	x += n;
}

template <typename Iterator, typename Distance>
void advanceIter(Iterator& x, Distance n)
{
	advanceIterImpl(x, n, typename std::iterator_traits<Iterator>::iterator_category()); 
}

/**
 * ����ģ����Ա���һ��ģ�����ͨ�������أ�ֻҪ���������ͻ�������ͬ��
 ����ƥ��
 1. ��ѡ������������ģ��ʵ���ƶϳɹ��ĺ���ģ��ʵ��
 2. ����ж��ƥ����ͬ����ͨ�������ȣ����ػ���ģ�庯������
 */

/**
 * ���庯��ģ���ػ�
 ����Ϊԭģ���е�ÿ��ģ��������ṩʵ��
 (�ػ������ͱ����������е�ģ���ж�Ӧ������ƥ�䣬ֻ���滻T����)
 ע��: һ���ػ��汾��������һ��ʵ�������Ǻ�������һ�����ذ汾��
 */
template <typename T>
int compare(const T&, const T&);

template<>
int compare(const char* const& p1, const char* const& p2); // T -> const char*