#pragma once

#include <type_traits>

typedef double(*func)();

void foo() {
	std::result_of<func()>::type f;	// double, not call func()
}

template <class>
struct Result_of;

template <class F, class... ArgTypes>
struct Result_of<F(ArgTypes...)>
{
	typedef decltype(std::declval<F>()(std::declval<ArgTypes>()...)) type;
};

