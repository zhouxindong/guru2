#pragma once

#include <type_traits>

/**
 * ���ض��ı����������º��Ժ���ģ��
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

// ����ʹ���е㱿�أ�ͨ��enable_if<>����һ�����ӵ�ȱʡ����ģ�����
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

// 2#��3#�������뻥��