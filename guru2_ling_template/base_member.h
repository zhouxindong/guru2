#pragma once

template <typename T>
class Base {
public:
	void bar();
};

template <typename T>
class Derived : Base<T> {
public:
	void foo() {
		bar(); // calls external bar() or error
				// this->bar() or Base<T>::bar()
	}
};

template <typename X>
class Base
{
public:
	int basefield;
	using T = int;
};

template <typename T>
class D2 : public Base<double>
{
public:
	void f() {
		basefield = 7;
	}
	T strange;	// T is Base<double>::T, not the template paramter!
};

/**
 * 非限定名称的查找，基类的顺序先于模板参数!
 */