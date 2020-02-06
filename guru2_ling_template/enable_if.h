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
	
template <typename Key, typename Value, typename = void>
class Dictionary {};

template <typename Key, typename Value>
class Dictionary<Key, Value,
	std::enable_if_t<HasLess<Key> && !HasHash<Key>>>	// #2
{
};

template <typename Key, typename Value>
class Dictionary<Key, Value,
	std::enable_if_t<HashHash<Key>>>					// #3
{
};

// 2#和3#条件必须互斥