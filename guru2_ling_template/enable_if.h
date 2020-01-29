#pragma once

#include <type_traits>

/**
 * 在特定的编译期条件下忽略函数模板
 */
template <typename T>
std::enable_if_t<(sizeof(T) > 4)>
foo() {
}

template <typename T>
std::enable_if_t<(sizeof(T) > 4), T>
foo() {
	return T();
}

// 上述使用有点笨重，通常enable_if<>用于一个附加的缺省函数模板参数
template <typename T,
		  typename = std::enable_if_t<(sizeof(T) > 4)>>
	void foo() {
}
	