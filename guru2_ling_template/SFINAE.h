#pragma once

// SFINAE���ں���ģ��Ĳ�ͬʵ��ѡ��
/**
 * ����decltypeָ��ģ�������Լ��
 * ��decltype�Ŀ�ʼ����������Լ��(ת��Ϊvoid��ֹ�������������)
 * �����һ������������ʵ�ķ�������
 */
template <typename T>
auto len(T const& t) -> decltype((void)(t.size()), T::size_type())
{
	return t.size();
}

/**
 * ���ֻ��ڱ�������������������ض����ļ���
 * 1. �ֲ��ػ�
 * 2. SFINAE
 * 3. std::enable_if
 * 4. if constexpr(...)
 */

/**
 * SFINAEԭ��ֻ�Ǻ�������ƥ���һ�ֻ��ƣ����������滻ʧ�ܺ�ѡ���������ذ汾
 * Ҳ�����ڱ����ڼ���������ض����ͻ���ʽ�Ƿ���Ч: �����Ƿ����ض��ĳ�Ա��֧���ض��Ĳ���
 * 1. SFINAE��������
 * 2. SFINAE�ֲ��ػ�
 */

/**
 * 1. SFINAE��������
 */
#include <type_traits>

template <typename T>
struct IsDefaultConstructible {
private:
	// must template for U, not directly T(���ʹ��T��Tʵ����ʱtest����ͬʱʵ������������Чʱ�������)
	template <typename U, typename = decltype(U())>	
	static char test(void*);

	template <typename>
	static long test(...);

public:
	static constexpr bool value = std::is_same<decltype(test<T>(nullptr)), char>::value;
};

template <typename T>
struct IsDefaultConstructible2 {
private:
	template <typename U, typename = decltype(U())>
	static std::true_type test(void*);

	template <typename>
	static std::false_type test(...);

public:
	using Type = decltype(test<T>(nullptr));
};

/**
 * 2. SFINAE�ֲ��ػ�
 */

// ����������������ģ�����
template <typename...> 
using VoidT = void; // std::void_t

template <typename, typename = VoidT<>>
struct IsDefaultConstructible3 : std::false_type
{
};

// VoidT<>��������������Ŀ�ı�����Լ����֤
template <typename T>
struct IsDefaultConstructible3<T, VoidT<decltype(T())>> : std::true_type
{ 
};

/**
 * SFINAE traits
 */
template <typename, typename, typename = std::void_t<>>
struct HasPlusT : std::false_type
{
};

template <typename T1, typename T2>
struct HasPlusT<T1, T2, std::void_t<decltype(std::declval<T1>() + std::declval<T2>())>>
	: std::true_type
{
};

template <typename T1, typename T2, bool = HasPlusT<T1, T2>::value>
struct PlusResultT {
	using Type = decltype(std::declval<T1>() + std::declval<T2>());
};

template <typename T1, typename T2>
struct PlusResultT<T1, T2, false>{
};