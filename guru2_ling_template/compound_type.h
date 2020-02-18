#pragma once

#include <type_traits>
#include <string>

void rank()
{
	int a2[5][7];
	std::rank_v<decltype(a2)>;	// 2
	std::rank_v<int*>;			// 0
	extern int p1[];
	std::rank_v<decltype(p1)>;	// 1
}

void extent()
{
	int a2[5][7];
	std::extent_v<decltype(a2)>;	// 5
	std::extent_v<decltype(a2), 0>;	// 5
	std::extent_v<decltype(a2), 1>;	// 7
	std::extent_v<decltype(a2), 2>; // 0

	std::extent_v<int*>;			// 0
	extern int p1[];
	std::extent_v<decltype(p1)>;	// 0
}

struct C {
	bool operator() (int) const {
		return true;
	}
};

/**
 * std::is_invocable<T, Args...>
 * std::is_nothrow_invocable<T, Args...>
 * std::is_invocable_r<RET_T, T, Args...>
 * std::is_nothrow_invocable_r<RET_T, T, Args...>
 * std::is_callable
 */

/**
 * std::invoke_result<T, Args...>::value
 * std::result_of<T, Args...>::value
 */
std::string foo(int) {
	return std::string();
}

using R0 = typename std::result_of<decltype(&foo)(int)>::type;
using R1 = std::result_of_t<decltype(&foo)(int)>;
// using R2 = std::invoke_result_t<decltype(foo), int>;