#pragma once
// const主要的限制就是只能在const类型对象上执行不改变其内容的操作
// 缺省状态下，const对象仅在文件内有效
const int kBufSize = 512;

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