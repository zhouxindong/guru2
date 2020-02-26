#pragma once

/**
 * 重载new和delete操作符，只能在某个类中或全局空间
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
	void* mem = ::malloc(sz);
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