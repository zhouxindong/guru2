#pragma once

/**
 * 初始化列表参数可以被转换为几种不同类型的参数
 * 1. initializer_list类型
 * 2. 拥有initializer_list类型参数构造函数的类型
 * 3. 那些恰好拥有初始化列表元素的构造函数的类型
 * 4. 聚合类型，其数据成员可以被初始化列表元素初始化
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