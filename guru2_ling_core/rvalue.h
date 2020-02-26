#pragma once
#include <type_traits>
/**
 * prvalue: ��ʱ����(std::string("hi"), returnString())
 * xvalue: std::move(x)
 */

/**
 * ��ֵ���þ���һ������ֵ�������õ����ͣ���ֵͨ��û�����֣�Ҳֻ��ͨ������
 * ��ֵ�����Ǿ�������ֵ�ı�������ֵ�����ǲ����������ı���
 */

/**
 * std::move(): ��һ����ֵǿ��ת��Ϊ��ֵ���ã�����ͨ����ֵ����ʹ�ø�ֵ�������ƶ�����
 static_cast<T&&>(lvalue);
 */
template <typename T>
typename std::remove_reference<T>::type&& Move(T&& t)
{
	return static_cast<typename std::remove_reference<T>::type&&>(t);
}

#include <iostream>
using namespace std;

class HugeMem {
public:
	HugeMem(int size) : sz(size > 0 ? size : 1) {
		c = new int[sz];
	}

	~HugeMem() {
		delete[] c;
	}

	HugeMem(HugeMem&& hm) : sz(hm.sz), c(hm.c) {
		hm.c = nullptr;
	}

	int* c;
	int sz;
};

class Moveable {
public:
	Moveable() : i(new int(3)), h(1024) {}
	~Moveable() { delete i; }

	Moveable(Moveable&& m) : i(m.i), h(std::move(m.h)) {
		m.i = nullptr;
	}

	int* i;
	HugeMem h;
};

/**
 * ���˹��캯���͸�ֵͬʱ�ṩ�������ƶ��汾�⣬��ͨ��Ա����Ҳ�����ṩ�������ƶ��汾���Ż�����
 */

/**
 * ��ֵ������ģ������������������: ģ��ת��ʵ�κ�ģ������
 */
 /**
 * ʹ����ֵ���õĺ�������
 */
template <typename T>
void f(T&&); // �󶨵���const��ֵ

template <typename T>
void f(const T&);	// ��ֵ��const��ֵ
