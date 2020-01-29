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
	