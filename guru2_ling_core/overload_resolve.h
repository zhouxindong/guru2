#pragma once

/**
 * ���ڲ�������X�������ֳ��õ�ʵ������: X, X&, X const&, X&&
 * ������������˵��ͨ��ֻ��Ҫ�������͵����á�
 * 1. C++11֮ǰ
 void report(int&);			// for lvalue
 void report(int const&);	// for rvalues

 * 2. C++11֮��
 void pass(Value const&);	// #1
 void pass(Value&&);		// #2

 void g(X&& x)
 {
	pass(x);	// #1 x is lvalue
	pass(X());	// #2 X() is prvalue
	pass(std::move(x));	// #3 xvalue
 }
 */