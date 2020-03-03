#pragma once

/**
 * Ҫע��new��delete���ʽ�������������
 ����ֻ�����ز��������ñ��ʽ��ȡ�ò�����ʱѡ�������Զ���İ汾�����������ð汾
 �����޷��ı���ʽ�ĺ��屾��!
 ��ȡ�ڴ� -> �����Ϲ������ -> �������� -> �ͷ��ڴ�
 new��delete����������1��4�Ĳ����������������ɱ��ʽ�������
 */
/**
 * ����new��delete��������ֻ����ĳ�����л�ȫ�ֿռ�
 */

/**
 * ���ñ�׼����
 void *operator new(size_t);
 void *operator new[](size_t); // size_t����������Ԫ������Ŀռ�
 void operator delete(void*) noexcept;
 void operator delete[](void*) noexcept;

 void *operator new(size_t, nothrow_t&) noexcept;
 void *operator new[](size_t, nothrow_t&) noexcept;
 void operator delete(void*, nothrow_t&) noexcept;
 void operator delete[](void*, nothrow_t&) noexcept;
 */
/**
 * ����ʱ�������ں�������Լ��Ĳ�������������Щ�Զ��庯����new���ʽ����ʹ��new�Ķ�λ��ʽ��ʵ�δ����������β�
 (new (__FILE__, __LINE__))
 void *operator new(size_t, void*); // ���������¶�������汾������汾��placement new���ʽ����
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
	void* mem = ::malloc(sz); // �˴������Լ������ڴ�
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

/**
 * ������new | delete�����
 �һ��������������ᱻ������̳�
 */
#include <iostream>

using namespace std;

class Base
{
public:
	static void* operator new(size_t sz) // new��delete����ʽ��̬�ģ�static����ʡ��
	{
		cerr << "new " << sz << " bytesn" << endl;
		return ::operator new(sz); // ����ȫ��new����������ڴ�ķ��䣬�����������new���ʽ�������
	}
	void operator delete(void* p, size_t sz) // ע�⣬��ȫ��delete�Ĺ��ͬ
	{
		cerr << "deleten" << endl;
		::operator delete(p); // delete���ʽ֮ǰ�Ѿ������˶������������
	}
	virtual ~Base() {}	// ȷ�����༰��������Ķ�̬������ȷ�ͷ�

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

 ����ͨ��һ����ֵַ����ʱ��placement newʹ��operator new(size_t, void*)����ȡʹ�õ��ڴ棬Ȼ�������(��ָ�����ڴ��Ϲ������)

 inline void* operator new(std::size_t, void* __p) throw()
 {
	return __p;
 }
 inline void  operator delete  (void*, void*) throw()
 {
 }
 */
/**
 * ʹ��placement new���������Ķ����ڱ�����ʱ��Ҫ��ʽ�ص��ö������������������ʹ��delete�����
 */
int main2()
{
	char mem[sizeof(int)];
	cerr << "Addr of mem = " << (void*)mem << endl;

	int* iptr2 = new (mem) int; // placement new
	cerr << "Addr of iptr2 = " << iptr2 << endl;

	delete iptr2; // exception occur!!
	// ����ԭ����C++��֪������ͷ�һ������������ֻ࣬����ʽ������������ptr->~Foo();
}

#include <vcruntime_new.h>
class X {};
class Y
{
	static const size_t sizeofx = sizeof(X);
	char x_[sizeofx]; // Σ�գ�����û����ȷ���ڴ����
	/**
	 * (char*)malloc(sizeof(Y));
	 new char[sizeof(Y)]
	 �������ַ�ʽ�ܹ���֤��ȷ���ڴ����
	 */

public:
	Y() {
		new (&x_[0]) X;
	}

	~Y() {
		(reinterpret_cast<X*>(&x_[0]))->~X();
	}
};