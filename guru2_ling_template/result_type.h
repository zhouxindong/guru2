#pragma once
#include <utility>

/**
 * ����ֵ���������ṩ��һ�ַ�������ȷ�����ض��������ķ�������
 */

template <typename T1, typename T2>
struct PlusResult {
	using Type = decltype(std::declval<T1>() + std::declval<T2>());
};
