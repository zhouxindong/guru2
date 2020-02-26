#pragma once
// const expression
// ֵ����ı䣬���ڱ����ڼ���
// ���������ͺͳ�ʼֵ��ͬ�����ܲ��ܳ�Ϊconstexpr

// �������ں��������ݡ����캯��

/**
 * const��constexpr������ʲô������?
 const����һ��������ʵ��
 constexpr��һ��������ʵ�壬��һ������ö��ֵ����ֵ���泣��
 (���ڸ�������������ֵ��������ֵ�ھ����Ͽ��ܻ��в�𣬵�����֧�ֱ����ڸ��㳣��)
 */

/**
 * const int max_files = 20; // yes
 * const int limit = max_files + 1; // yes
 * int staff_size = 27; // no
 * const int sz = get_size(); // no
 */

/**
 * ������������Ϊconstexpr���ͣ��ɱ�������֤
 * constexpr int mf = 20;
 * constexpr int limit = mf + 1;
 * constexpr int sz = size(); // ֻ�е�size��һ��constexpr����ʱ��������ȷ
 */

const int *p = nullptr; // �ײ�const
constexpr int *q = nullptr; // ����const

constexpr int i = 42;
constexpr const int *p = &i;

/**
 * constexpr�����ķ������ͼ������βε����Ͷ�������ֵ����
 * constexpr��һ�����س������ʽ���ɱ�����������֤
 * constexpr�Ķ������ͷ�ļ���
 */

// constexpr���Բ��ִ���ģ��ı����ڼ���
constexpr bool isPrime(unsigned int p)
{
	for (unsigned int d = 2; d <= p / 2; ++d) {
		if (p% d == 0)
		{
			return false;
		}
	}
	return p > 1;
}

// if constexpr���������κκ�������������ģ�壬��Ҫ��ֻ��һ�������ڵĲ������ʽ
template <typename T, typename... Types>
void print(T const& firstArg, Types const&... args)
{
	std::cout << firstArg << '\n';
	if constexpr(sizeof...(args) > 0) {
		print(args...);
	}
}

/**
 * constexpr����ֱ�����ڶ����ֻ࣬��������Ĺ��캯��
 */
struct MyType {
	constexpr MyType(int x) : i(x) {}

	int i;
};

constexpr MyType mt = { 0 };

/**
 * ��������ǵݹ�ģ�������һ���������ʽ������֧��
 */
constexpr int Fibonacci(int n)
{
	return (n == 1) ? 1 : ((n == 2) ? 1 : Fibonacci(n - 1) + Fibonacci(n - 2));
}