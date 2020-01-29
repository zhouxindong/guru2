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