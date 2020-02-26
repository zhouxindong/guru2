#pragma once
int a[10]; // 数组是一种复合类型，数组类型包括基本类型和维数

// 字符数组的特殊性: 尾部多一个空字符
char a3[] = "C++";  // length = 4;

// 数组不允许拷贝和赋值，所以无法直接作为函数参数传递
// 数组本身就是对象，可以定义数组的指针和数组的引用

int *ptrs[10]; // 指针数组
int(*Parray)[10] = &a; // 指向维度为10的整型数组的指针
int(&arrRef)[10] = a;  // 一个维度为10的整型数组的引用

// 对于数组，编译器一般会把它转换为指针，一个指向数组首元素的指针
auto ia2(a); // int *(decay)
decltype(a) ia3; // int[10]

// 数组形参的性质: 不允许拷贝数组以及使用数组时会将其转换成指针
void print(const int*);
void print(const int[]);
void print(const int[10]);
// 上述声明等价，所以需要添加数组的维度信息
/**
 * 1. 结束标记(C-style string)
 * 2. iterator(begin, end)
 * 3. size_t
 */

/**
 * 字符串字面常量"hello" -> const char[6]
 decltype("hello") -> const char(&)[6]
 非字符串字面常量，为右值
 decltype(1) -> int
 */