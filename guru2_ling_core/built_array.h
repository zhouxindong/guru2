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
auto ia2(a); // int *
decltype(a) ia3; // int[10]