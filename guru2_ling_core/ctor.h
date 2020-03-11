#pragma once
#include <utility>

/**
 * 1. ���캯��: �������ι���
 * 2. �������졢�ƶ�����: ����ͬ���͵���һ�������ʼ������ʱ��ʲô
 * 3. ������ֵ���ƶ���ֵ: ��һ��������ͬ���͵���һ������ʱ��ʲô
 */

/**
 * ������Ŀ�������
 ������Ӷ���Ĺ��첻���Զ��ɲ������죬����㲻���壬ֻ��ȱʡ����
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
 * ���������������ֻ��Ҫ�����Լ�����Դ�ͷţ����������������ĵ�������ʽ�Զ���ɵġ�
 */

/**
 * һ������������ڴӹ��캯���������ŵ�����������������
 */

class A {};
class B {};

class C : private A {
public:
	C() try :
		A(), b_()
	{

	}
	catch (...)
	{

	}
private:
	B b_;
};