#pragma once

/**
 * 要注意new和delete表达式与操作符的区别
 我们只能重载操作符，让表达式在取用操作符时选用我们自定义的版本，而不是内置版本
 我们无法改变表达式的含义本身!
 获取内存 -> 在其上构造对象 -> 析构对象 -> 释放内存
 new和delete操作符决定1和4的操作，而整个语义由表达式本身控制
 */
/**
 * 重载new和delete操作符，只能在某个类中或全局空间
 */

/**
 * 内置标准定义
 void *operator new(size_t);
 void *operator new[](size_t); // size_t是数组所有元素所需的空间
 void operator delete(void*) noexcept;
 void operator delete[](void*) noexcept;

 void *operator new(size_t, nothrow_t&) noexcept;
 void *operator new[](size_t, nothrow_t&) noexcept;
 void operator delete(void*, nothrow_t&) noexcept;
 void operator delete[](void*, nothrow_t&) noexcept;
 */
/**
 * 重载时，可以在后面添加自己的参数，这里用这些自定义函数的new表达式必须使用new的定位形式将实参传给新增的形参
 (new (__FILE__, __LINE__))
 void *operator new(size_t, void*); // 不允许重新定义这个版本，这个版本由placement new表达式调用
 */

/**
 * C++中的new运算符
 1. 使用全局operator new分配原始内存
 2. 若内存分配成功，则在新内存上构造对象
 Foo* p = new Foo();
 -------------------------------------
 Foo* p;
 void* raw = operator new(sizeof(Foo));
 try {
	p = new(raw) Foo();  // call the ctor with raw as this 像这样用raw调用ctor分配内存
 }
 catch (...) {
	operator delete(raw);
	throw;  // rethrow the ctor's exception 重新抛出ctor的异常
 }
 */

/**
 * C++中的delete运算符
 1. 调用对象的析构函数
 2. 使用全局operator delete释放内存
 delete p;
 ---------------------------------
 if(p != NULL)
 {
	p->~Foo();
	operator delete(p);
 }
 */

#include <exception>
#include <iostream>

void* operator new(size_t sz) throw (std::bad_alloc)
{
	std::cerr << "allocating " << sz << " bytes\n";
	void* mem = ::malloc(sz); // 此处必须自己分配内存
	if (mem)
		return mem;
	else
		throw std::bad_alloc();
}

void operator delete(void* ptr) throw()
{
	std::cerr << "deallocating at " << ptr << '\n';
	::free(ptr);
}

/**
 * 全局new用来给内置类型、没有重新定义new函数的类、数组分配空间
 */

/**
 * 类重载new | delete运算符
 且基类的重载运算符会被派生类继承
 */
#include <iostream>

using namespace std;

class Base
{
public:
	static void* operator new(size_t sz) // new和delete是隐式静态的，static可以省略
	{
		cerr << "new " << sz << " bytesn" << endl;
		return ::operator new(sz); // 调用全局new操作符完成内存的分配，后面的语义由new表达式负责控制
	}
	void operator delete(void* p, size_t sz) // 注意，与全局delete的规格不同
	{
		cerr << "deleten" << endl;
		::operator delete(p); // delete表达式之前已经调用了对象的析构函数
	}
	virtual ~Base() {}	// 确保基类及其派生类的动态对象被正确释放

private:
	int m_data;
};

class Derived
	: public Base
{
private:
	int m_derived_data;

};

int main()
{
	Base* b = new Base;
	delete b;

	Derived* d = new Derived;
	delete d;

	system("pause");
	return 0;
}

/**
 * placement new expression

 new(place_address) type
 new(place_address) type (initializers)
 new(place_address) type [size]
 new(place_address) type [size] { braced initializer list }

 当仅通过一个地址值调用时，placement new使用operator new(size_t, void*)来获取使用的内存，然后构造对象(在指定的内存上构造对象)

 inline void* operator new(std::size_t, void* __p) throw()
 {
	return __p;
 }
 inline void  operator delete  (void*, void*) throw()
 {
 }
 */
/**
 * 使用placement new创建出来的对象在被销毁时需要显式地调用对象的析构函数，不能使用delete运算符
 */
int main2()
{
	char mem[sizeof(int)];
	cerr << "Addr of mem = " << (void*)mem << endl;

	int* iptr2 = new (mem) int; // placement new
	cerr << "Addr of iptr2 = " << iptr2 << endl;

	delete iptr2; // exception occur!!
	// 根本原因是C++不知道如何释放一个对象，如果是类，只能显式调用析构函数ptr->~Foo();
}

#include <vcruntime_new.h>
class X {};
class Y
{
	static const size_t sizeofx = sizeof(X);
	char x_[sizeofx]; // 危险，可能没有正确的内存对齐
	/**
	 * (char*)malloc(sizeof(Y));
	 new char[sizeof(Y)]
	 上述两种方式能够保证正确的内存对齐
	 */

public:
	Y() {
		new (&x_[0]) X;
	}

	~Y() {
		(reinterpret_cast<X*>(&x_[0]))->~X();
	}
};