#pragma once

#include <type_traits>

void foo(void(f)())
{
	std::is_function_v<decltype(f)>;	// false(f has type void(*)())
	std::is_function_v<decltype(foo)>;	// true;
	std::is_function_v<decltype(&foo)>;	// false;
	std::is_function_v<decltype(foo(f))>;	// false(return type)
}