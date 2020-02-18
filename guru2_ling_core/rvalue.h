#pragma once
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