#pragma once
// ֻ����Ҫ���ʽ�����ͣ���������ֵ��ʼ��
// �ɱ������������ʽ�õ������ͣ�����ʵ�ʼ�����ʽ��ֵ

// ע��: ����const�Ĵ�����auto��ͬ(auto���Զ���const����decltype��������const)
// 1. decltypeʹ�õı��ʽ��һ���������򷵻ظñ�������������
/**
 * const int ci = 0;
 * const int &cj = ci;
 * decltype(ci) x = 0; // const int
 * decltype(cj) y = x; // const int&
 */

// 2. decltypeʹ�õı��ʽ����һ���������򷵻ر��ʽ�����Ӧ�����ͣ��������ֵʱ������������
/**
 * int i = 42;
 * int *p = &i;
 * int &r = i;
 * decltype(r+0) b; // int
 * decltype(*p) c = i; // int & (*p���ض��󣬿��Ա���ֵ�����������)
 * decltype(i); // int
 * decltype((i)); // �������ʽ��һ�ֿ�����Ϊ��ֵ�����ֵ��������ʽ�������� int &
 */
/**
 * if e is an lvalue of type T, decltype(e) -> T&
 * if e is an xvalue of type T, decltype(e) -> T&&
 * if e is a prvalue of type T, decltype(e) -> T
 */

// decltype(auto)
void foo()
{
	int i = 42;
	int const& ref = i;
	auto x = ref;	// x -> int	
	decltype(auto) y = ref; // y -> int const&
}

template <typename T1, typename T2>
struct PlusResult {
	using Type = decltype(T1() + T2());
};

using size_t = decltype(sizeof(0));
using ptrdiff_t = decltype((int*)0 - (int*)0);
using nullptr_t = decltype(nullptr);