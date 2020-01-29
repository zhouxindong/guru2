#pragma once
// const expression
// 值不会改变，且在编译期计算
// 由数据类型和初始值共同决定能不能成为constexpr

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