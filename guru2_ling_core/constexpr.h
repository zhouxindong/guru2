#pragma once
// const expression
// 值不会改变，且在编译期计算
// 由数据类型和初始值共同决定能不能成为constexpr

// 可以用于函数、数据、构造函数

/**
 * const和constexpr定义有什么区别呢?
 const定义一定会生成实体
 constexpr不一定会生成实体，这一点类似枚举值和右值字面常量
 (对于浮点数，编译期值和运行期值在精度上可能会有差别，但现在支持编译期浮点常量)
 */

/**
 * const int max_files = 20; // yes
 * const int limit = max_files + 1; // yes
 * int staff_size = 27; // no
 * const int sz = get_size(); // no
 */

/**
 * 允许将变量声明为constexpr类型，由编译器验证
 * constexpr int mf = 20;
 * constexpr int limit = mf + 1;
 * constexpr int sz = size(); // 只有当size是一个constexpr函数时声明才正确
 */

const int *p = nullptr; // 底层const
constexpr int *q = nullptr; // 顶层const

constexpr int i = 42;
constexpr const int *p = &i;

/**
 * constexpr函数的返回类型及所有形参的类型都是字面值类型
 * constexpr不一定返回常量表达式，由编译器负责验证
 * constexpr的定义放在头文件中
 */

// constexpr可以部分代替模板的编译期计算
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

// if constexpr可以用于任何函数，不仅仅是模板，需要的只是一个编译期的布尔表达式
template <typename T, typename... Types>
void print(T const& firstArg, Types const&... args)
{
	std::cout << firstArg << '\n';
	if constexpr(sizeof...(args) > 0) {
		print(args...);
	}
}

/**
 * constexpr不能直接用于定义类，只能用于类的构造函数
 */
struct MyType {
	constexpr MyType(int x) : i(x) {}

	int i;
};

constexpr MyType mt = { 0 };

/**
 * 如果函数是递归的，而且是一个常量表达式函数，支持
 */
constexpr int Fibonacci(int n)
{
	return (n == 1) ? 1 : ((n == 2) ? 1 : Fibonacci(n - 1) + Fibonacci(n - 2));
}