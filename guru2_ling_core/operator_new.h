#pragma once

/**
 * ����new��delete��������ֻ����ĳ�����л�ȫ�ֿռ�
 */

/**
 * C++�е�new�����
 1. ʹ��ȫ��operator new����ԭʼ�ڴ�
 2. ���ڴ����ɹ����������ڴ��Ϲ������
 Foo* p = new Foo();
 -------------------------------------
 Foo* p;
 void* raw = operator new(sizeof(Foo));
 try {
	p = new(raw) Foo();  // call the ctor with raw as this ��������raw����ctor�����ڴ�
 }
 catch (...) {
	operator delete(raw);
	throw;  // rethrow the ctor's exception �����׳�ctor���쳣
 }
 */

/**
 * C++�е�delete�����
 1. ���ö������������
 2. ʹ��ȫ��operator delete�ͷ��ڴ�
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
 * ȫ��new�������������͡�û�����¶���new�������ࡢ�������ռ�
 */