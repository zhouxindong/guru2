#pragma once
#include <type_traits>
/**
 * prvalue: 临时对象(std::string("hi"), returnString())
 * xvalue: std::move(x)
 */

/**
 * 右值引用就是一个对右值进行引用的类型，右值通常没有名字，也只能通过引用
 * 左值引用是具名变量值的别名，右值引用是不具名变量的别名
 */

/**
 * std::move(): 将一个左值强制转化为右值引用，可以通过右值引用使用该值，用于移动语义
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
 * 除了构造函数和赋值同时提供拷贝和移动版本外，普通成员函数也可以提供拷贝和移动版本，优化性能
 */

/**
 * 右值引用在模板参数中用于两种情况: 模板转发实参和模板重载
 */
 /**
 * 使用右值引用的函数重载
 */
template <typename T>
void f(T&&); // 绑定到非const右值

template <typename T>
void f(const T&);	// 左值和const右值
