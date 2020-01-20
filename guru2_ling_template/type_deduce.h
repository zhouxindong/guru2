#pragma once
// 1. by reference
/**
 * ʵ�����βα����ϸ�ƥ��
 */

// 2. by value
/**
 * decay: const��volatile���ԣ�����ת��Ϊ�������ͣ��������ת��Ϊ��Ӧ��ָ������
 */

// 3. deducing the Return Type
template <typename T1, typename T2>
auto max(T1 a, T2 b)	// C++14
{
	return b < a ? a : b;
}

template <typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(b < a ? a : b)	// C++11
{
	return b < a ? a : b;
}