#pragma once
// 只是需要表达式的类型，不想用其值初始化
// 由编译器分析表达式得到其类型，并不实际计算表达式的值

// 注意: 顶层const的处理与auto不同
// 1. decltype使用的表达式是一个变量，则返回该变量的完整类型
/**
 * const int ci = 0;
 * const int &cj = ci;
 * decltype(ci) x = 0; // const int
 * decltype(cj) y = x; // const int&
 */

// 2. decltype使用的表达式不是一个变量，则返回表达式结果对应的类型
/**
 * int i = 42;
 * int *p = &i;
 * int &r = i;
 * decltype(r+0) b; // int
 * decltype(*p) c = i; // int & (*p返回对象，可以被赋值，因此是引用)
 * decltype(i); // int
 * decltype((i)); // 变量表达式是一种可以作为赋值语句左值的特殊表达式，所以是 int &
 */