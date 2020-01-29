#pragma once

// bs.template to_string<char, std::char_traits<char>, std::allocator<char>>()

#include <iostream>
template <typename T>
class Shell
{
public:
	template <int N>
	class In
	{
	public:
		template <int M>
		class Deep
		{
		public:
			virtual void f() {
				std::cout << "Shell<T>::In<N>::Deep<M>::f()\n";
			}
		};
	};
};

template <typename T, int N>
class Weird
{
public:
	void case1(
		typename Shell<T>::template In<N>::template Deep<N>* p)
	{
		p->Deep<N>::f();	// p->f();
	}

	void case2(
		typename Shell<T>::template In<N>::template Deep<N>& p
	)
	{
		//p.Deep<N>::f();
		p.f();
	}
};