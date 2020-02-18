#pragma once

/**
 * ��ʼ���б�������Ա�ת��Ϊ���ֲ�ͬ���͵Ĳ���
 * 1. initializer_list����
 * 2. ӵ��initializer_list���Ͳ������캯��������
 * 3. ��Щǡ��ӵ�г�ʼ���б�Ԫ�صĹ��캯��������
 * 4. �ۺ����ͣ������ݳ�Ա���Ա���ʼ���б�Ԫ�س�ʼ��
 */

#include <initializer_list>
#include <string>
#include <vector>
#include <complex>
#include <iostream>

void f(std::initializer_list<int>)
{
	std::cout << "#1";
}

void f(std::initializer_list<std::string>)
{
	std::cout << "#2";
}

void g(std::vector<int> const& vec)
{
	std::cout << "#3";
}

void h(std::complex<double> const& cmplx)
{
	std::cout << "#4";
}

struct Point {
	int x, y;
};

void i(Point const& pt) {
	std::cout << "#5";
}

void foo()
{
	f({ 1,2,3 });	// #1
	f({ "hello", "initializer", "list" });	// #2
	g({ 1,1,2,3,5 });	// #3
	h({ 1.5,2.5 });		// #4
	i({ 1,2 });			// #5
}