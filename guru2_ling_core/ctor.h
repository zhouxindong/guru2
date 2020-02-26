#pragma once
#include <utility>

/**
 * 1. 构造函数: 类对象如何构造
 * 2. 拷贝构造、移动构造: 当用同类型的另一个对象初始化对象时做什么
 * 3. 拷贝赋值、移动赋值: 将一个对象赋予同类型的另一个对象时做什么
 */

/**
 * 派生类的拷贝控制
 其基类子对象的构造不会自动由参数构造，如果你不定义，只会缺省构造
 */
class Base {};

class D : public Base {
public:
	D(const D& d) : Base(d) {}
	D(D&& d) : Base(std::move(d)) {}

	D& operator = (const D& rhs) {
		Base::operator=(rhs);
		return *this;
	}

	D& operator = (D&& rhs) {
		Base::operator=(std::move(rhs));
		return *this;
	}
};

/**
 * 派生类的析构函数只需要负责自己的资源释放，其基类的析构函数的调用是隐式自动完成的。
 */