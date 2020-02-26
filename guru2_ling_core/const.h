#pragma once
// const主要的限制就是只能在const类型对象上执行不改变其内容的操作
// 缺省状态下，const对象仅在文件内有效
const int kBufSize = 512;

const int GetConst()
{
	return 10;
}

constexpr int GetConst2()
{
	return 10;
}

//int buf[GetConst()]; // const更多强调的是运行时常量
int buf[GetConst2()];	// constexpr，常量表达式，编译期常量

// const对象仅有一处定义，其他文件中共享
// extern const int kBufSize = fcn(); .cpp
// extern const int kBufSize; //.h

template <char const* str>
class Message {
};

extern char const hello[] = "Hello World!";	// external linkage
char const hello11[] = "Hello World!";		// internal linkage

void foo()
{
	static char const hello17[] = "Hello World!";	// any linkage

	Message<hello> msg03;
	Message<hello11> msg11;
	//Message<hello17> msg17;
}

/**
 * 类成员函数const时，其实是修改隐式this指针的类型
 缺省时this类型是指向类类型非常量版本的常量指针: type *const
 所以其不能绑定到一个常量对象上。
 用const修饰成员函数，其实是修改了this指针的类型: const type *const，使得其能够被绑定的对象范围扩大了

 所以const成员和非const成员函数可以重载，因为其隐式的this指针的类型不同，让其返回不同类型(const, nonconst)对象
 调用时，const对象自匹配const版本，非const匹配非const版本
 通常对于返回引用类型的函数提供两个版本: const版本和非const版本
 */

/**
 * 成员函数除了const限定符外，还可以添加引用限定符，限定能够调用该成员函数的对象的类型: &, &&
 必须同时定义所有版本的引用限定符，不能只定义一个
 Foo anotherMem() const &;
 */
#include <vector>
class Foo {
public:
	Foo sorted() &&;	// 可用于可改变的右值
	Foo sorted() const &;	// 可用于任何类型的Foo
private:
	std::vector<int> data;
};

// 本对象为右值，因此可以原址排序
Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	return *this;
}

// 本对象是const或是一个左值，不能原址排序
Foo Foo::sorted() const & {
	Foo ret(*this);
	sort(ret.data.begin(), ret.data.end());
	return ret; // 返回副本
}