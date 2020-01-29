#pragma once
// ͨ�����ʽ�ƶ�����
// auto ���ǰ�����decay

// 1. ����������ʼֵʱʹ�õ������ö����ֵ
/**
 * int i = 0;
 * int &r = i;
 * auto a = r; // auto -> int
 */

// 2. ���Զ���const�������ײ�const
/**
 * const int ci = 0;
 * const int &cr = ci;
 * auto b = ci; // auto -> int
 * auto e = &ci; // auto -> const int *
 */

// 3. ���ϣ������const������
/**
 * const auto f = ci;
 * auto &g = i; // ��ʱ����i�Ķ��㳣������
 * const auto &j = 42;
 */

// auto�������ƶ�������ģ�����ʹ�ô�ֵ����(by value)
void foo()
{
	int x;
	auto&& rr = 42;
	auto&& lr = x;
}

// ������auto������ֵ���ã�����Ϊ��������ת�������԰���ֵ���ú���ֵ����(�����ڽ��պ����ķ���ֵ)
template <typename Container>
void g(Container c)
{
	for (auto&& x : c)	// no additional copies are made of the values
	{

	}
}

auto f(int)
{
	return 42;
}

auto f2() -> auto
{
	return 42;
}

auto lm = [](int x) /* -> auto */
{
	return f(x);
};