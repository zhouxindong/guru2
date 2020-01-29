#pragma once
// 通过表达式推断类型
// auto 总是伴随着decay

// 1. 引用用作初始值时使用的是引用对象的值
/**
 * int i = 0;
 * int &r = i;
 * auto a = r; // auto -> int
 */

// 2. 忽略顶层const，保留底层const
/**
 * const int ci = 0;
 * const int &cr = ci;
 * auto b = ci; // auto -> int
 * auto e = &ci; // auto -> const int *
 */

// 3. 如果希望保留const或引用
/**
 * const auto f = ci;
 * auto &g = i; // 此时保留i的顶层常量属性
 * const auto &j = 42;
 */

// auto的类型推断类似于模板参数使用传值语义(by value)
void foo()
{
	int x;
	auto&& rr = 42;
	auto&& lr = x;
}

// 若利用auto定义右值引用，其行为类似完美转发，可以绑定左值引用和右值引用(可用于接收函数的返回值)
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