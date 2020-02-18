#pragma once

/**
 * 使用using Base::foo可以将基类中所有的foo函数声明引入到派生类中(名称引入)
 * 对于构造函数，特别是大量的派生类"透传"构造函数可以通过基类构造函数名称引入简化
 */

#include "cstring"
#include <iostream>

struct A {
	int i = 0;
	double d = 0.0;
	float f = 0.0;
	char* c = nullptr;

	A() {}
	A(int i) : i(i) {}
	A(double d, int i) :d(d), i(i) {}
	A(float f, int i, const char* s) :f(f), i(i), c(new char[std::strlen(s) + 1]) {
		std::strcpy(c, s);
	}

	~A()
	{
		if (c != nullptr)
			delete[] c;
	}
};

template <typename Base>
struct B : Base {
	using Base::Base;
};

int main()
{
	B<A> a(3.314, 39, "hello, world");
	std::cout << a.f << '\n';
	std::cout << a.i << '\n';
	std::cout << a.c << '\n';

	system("pause");
	return 0;
}
