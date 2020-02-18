#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <type_traits>

template <typename Iter, typename Callable>
void foreach(Iter current, Iter end, Callable op)
{
	while (current != end)
	{
		op(*current);
		++current;
	}
}

void func(int i)
{
	std::cout << "func() called for: " << i << '\n';
}

class FuncObj {
public:
	void operator() (int i) const {	// Note: const member function
		std::cout << "FuncObj::op() called for: " << i << '\n';
	}
};

void foo()
{
	std::vector<int> primes = { 2,3,5,7,11,13,17,19 };
	foreach(primes.begin(), primes.end(), func);	// decay to pointer
	foreach(primes.begin(), primes.end(), &func);	// function pointer as callable
	foreach(primes.begin(), primes.end(), FuncObj()); // function object as callable
	foreach(primes.begin(), primes.end(),
		[](int i) {									// lambda as callable
		std::cout << "lambda called for: " << i << '\n';
	});
}

/**
 * 1. 直接使用函数名作为传递参数时，传递的不是函数本身，而是函数指针或引用
 * 2. 函数对象运算符通常声明为const
 */

// 使用类成员函数作为回调函数(需要处理附加参数, this pointer)
template <typename Iter, typename Callable, typename... Args>
void foreach(Iter current, Iter end, Callable op, Args const&... args)
{
	while (current != end)
	{
		std::invoke(op, args..., *current);
		++current;
	}
}

class MyClass
{
public:
	void memfunc(int i) const {
		std::cout << "MyClass::memfunc() called for: " << i << '\n';
	}
};

int main()
{
	std::vector<int> primes = { 2,3,5,7,11,13,17,19 };
	foreach(primes.begin(), primes.end(),
		[](std::string const& prefix, int i) {	// 传递附加参数
		std::cout << prefix << i << '\n';
	}, "- value: ");

	MyClass obj;
	foreach(primes.begin(), primes.end(), &MyClass::memfunc, obj);	// 将成员函数所属对象作为附加参数传入-
}

/**
 * 封装函数调用 std::invoke()
 * (调用日志，性能测量，线程执行体上下文准备等等)
 */
template <typename Callable, typename... Args>
decltype(auto) call(Callable&& op, Args&&... args) // decltype(auto)可以返回ref, auto无法做到
{
	if (constexpr(std::is_same_v < std::invoke_result_t<Callable, Args...>, void) {
		// return type is void(decltype(void) is invalid)
		std::invoke(std::forward<Callable>(op), std::forward<Args>(args)...);
		return;
	})
	else {
		// return type is not void
		decltype(auto) ret{ std::invoke(std::forward<Callable>(op), std::forward<Args>(args)...) };
		return ret;
	}
}

/**
 * bool foo(int, double);
 声明了一个函数类型bool(int, double)，及一个此类型的对象foo
 bool(*fp)(int, double); // 声明一个函数指针对象，其底层类型为bool(int, double), 此时指针未初始化
 fp = foo; // foo会自动转换为指针
 fp = &foo; // 效果一样
 fp(3, 4.4);
 (*fp)(3, 4.4);
 */

/**
 * 和数组类似，不能定义函数类型的形参(可以定义，只是decay为指针)
 形参可以是指向函数的指针(可以定义函数类型的参数，只是decay为指针)
 typedef bool Func(const string&, const string&);
 typedef decltype(lengthCompare) Func2;

 typedef bool(*FuncP)(const string&, const string&);
 typedef decltype(lengthCompare)* FuncP2;
 */

/**
 * bind	通用函数适配器
 auto newCallable = bind(callable, arg_list)
 arg_list中的占位符_n(1...)，表示newCallable中对应位置的参数
 */