#pragma once
#include "qualifier.h"
#include <type_traits>

template <typename T>
struct Decay : RemoveCV<T> {
};

template <typename T>
struct Decay<T[]> {
	using Type = T*;
};

template <typename T, std::size_t N>
struct Decay<T[N]> {
	using Type = T*;
};

template <typename R, typename... Args>
struct Decay<R(Args...)> {
	using Type = R(*)(Args...);
};

/**
 * std::decay<T>::type
 1. remove_reference
 2. array to pointer
 3. function, add_pointer<function_type>(R(Args...) ->R(*)(Args...))
 4. remove top CV
 */
/**
 * decay在传值方式传递参数或使用auto推演参数类型时自动应用
 * decay特别适用于可能被推断为引用类型的模板参数同时用于返回类型时
 */

void foo()
{
	std::decay_t<int const&>;	// int
	std::decay_t<int const[4]>;	// int const* (keep low const)
	std::decay_t<decltype(foo)>;	// void(*)()
}