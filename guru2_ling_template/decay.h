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
 * decay�ڴ�ֵ��ʽ���ݲ�����ʹ��auto���ݲ�������ʱ�Զ�Ӧ��
 * decay�ر������ڿ��ܱ��ƶ�Ϊ�������͵�ģ�����ͬʱ���ڷ�������ʱ
 */

void foo()
{
	std::decay_t<int const&>;	// int
	std::decay_t<int const[4]>;	// int const* (keep low const)
	std::decay_t<decltype(foo)>;	// void(*)()
}