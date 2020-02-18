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
 * 1. ֱ��ʹ�ú�������Ϊ���ݲ���ʱ�����ݵĲ��Ǻ����������Ǻ���ָ�������
 * 2. �������������ͨ������Ϊconst
 */

// ʹ�����Ա������Ϊ�ص�����(��Ҫ�����Ӳ���, this pointer)
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
		[](std::string const& prefix, int i) {	// ���ݸ��Ӳ���
		std::cout << prefix << i << '\n';
	}, "- value: ");

	MyClass obj;
	foreach(primes.begin(), primes.end(), &MyClass::memfunc, obj);	// ����Ա��������������Ϊ���Ӳ�������-
}

/**
 * ��װ�������� std::invoke()
 * (������־�����ܲ������߳�ִ����������׼���ȵ�)
 */
template <typename Callable, typename... Args>
decltype(auto) call(Callable&& op, Args&&... args) // decltype(auto)���Է���ref, auto�޷�����
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
 ������һ����������bool(int, double)����һ�������͵Ķ���foo
 bool(*fp)(int, double); // ����һ������ָ�������ײ�����Ϊbool(int, double), ��ʱָ��δ��ʼ��
 fp = foo; // foo���Զ�ת��Ϊָ��
 fp = &foo; // Ч��һ��
 fp(3, 4.4);
 (*fp)(3, 4.4);
 */

/**
 * ���������ƣ����ܶ��庯�����͵��β�(���Զ��壬ֻ��decayΪָ��)
 �βο�����ָ������ָ��(���Զ��庯�����͵Ĳ�����ֻ��decayΪָ��)
 typedef bool Func(const string&, const string&);
 typedef decltype(lengthCompare) Func2;

 typedef bool(*FuncP)(const string&, const string&);
 typedef decltype(lengthCompare)* FuncP2;
 */

/**
 * bind	ͨ�ú���������
 auto newCallable = bind(callable, arg_list)
 arg_list�е�ռλ��_n(1...)����ʾnewCallable�ж�Ӧλ�õĲ���
 */