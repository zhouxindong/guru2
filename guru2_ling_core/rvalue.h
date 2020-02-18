#pragma once
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

	HugeMem(HugeMem&& hm) : sz()

	int* c;
	int sz;
};