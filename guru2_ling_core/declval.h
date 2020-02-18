#pragma once
/**
 * std::declval<>()����ģ������һ���ض����͵Ķ������õ�ռλ��
 * ֻ�����ڷ���ֵ�����(decltype, sizeof)
 */

#include <utility>
#include <type_traits>

template <
	typename T1, typename T2,
	typename RT = std::decay_t<decltype(true?std::declval<T1>():std::declval<T2>())>>
	RT max(T1 a, T2 b)
{
	return b < a ? a : b;
}

/**
 * declval()����δ�������壬ʹ����ֻ������decltype, sizeof�Ȳ���Ҫ����ĳ���
 * 1. �����������ͣ��䷵������Ϊ��ֵ���ã���ʹ������������޷������Ӻ������ص����Σ�����������ͻ���������
 */
template <typename T>
std::add_rvalue_reference_t<T> declval2() noexcept;

template <typename T1, typename T2>
struct PlusResult {
	using Type = decltype(std::declval<T1>() + std::declval<T2>());
};

/**
 * std::declval<T>(): ����һ������(��ֵ����)���������κι��캯�����ʼ��
 �����ڷ���ֵ���ʽ�����ڴ����������͵Ķ������
 template <typename T>
 add_rvalue_reference_t<T> declval() noexcept;
 1. ��T����ͨ���ͻ���ֵ���ã����ΪT&&
 2. ��T����ֵ���ã����ΪT&
 3. ��T��void,�����Ϊvoid
 */

