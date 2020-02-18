#pragma once

/**
 * 对于参数类型X，有四种常用的实参类型: X, X&, X const&, X&&
 * 但对于重载来说，通常只需要两种类型的引用。
 * 1. C++11之前
 void report(int&);			// for lvalue
 void report(int const&);	// for rvalues

 * 2. C++11之后
 void pass(Value const&);	// #1
 void pass(Value&&);		// #2

 void g(X&& x)
 {
	pass(x);	// #1 x is lvalue
	pass(X());	// #2 X() is prvalue
	pass(std::move(x));	// #3 xvalue
 }
 */