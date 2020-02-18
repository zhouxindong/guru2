#pragma once
#include <type_traits>
#include <utility>

/**
 * lvalues
 * 1. 变量或函数指派表达式
 * 2. *
 * 3. 字符串字面值
 * 4. 返回左值引用的函数调用
 */

/**
 * prvalues(纯右值)
 * 1. 字面值(非字符串字面值)表达式
 * 2. 取址&
 * 3. 内置算术运算符
 * 4. 返回非引用类型的函数调用
 * 5. lambda表达式
 */

/**
 * xvalues(将亡值)
 * 1. 返回右值引用的函数调用(std::move())
 * 2. 转换为右值引用
 * 3. 注意: 函数参数为右值引用，其变量本身为左值，需要传递其为右值引用时，需要std::move()
 */

/**
 * 需要强调的是，上述值分类都是针对的表达式，而非值或实体
 * 例如: 一个变量不是一个左值
 int x = 3; // x是变量，而非一个左值，3是一个prvalue，用来初始化变量x
 int y = x; // x是一个左值，转换为一个prvalue，用来初始化变量y
 */

int f(int const&);
int r = f(3);
// f期望一个引用，3是prvalue，此时生成一个临时对象，初始为3，然后此临时对象传递给函数调用

class X {};
X v;
X const c;

void f(X const&);	// #1, 接受任何值类型的表达式
void f(X&&);		// #2, 接受prvalue和xvalue表达式，比#1这两种表达式是更好的匹配

f(v);	// #1, modifiable lvalue
f(c);	// #1, nonmodifiable lvalue
f(X());	// #2, prvalue, 在C++17语言规范为xvalue，并非为编译器优化，而是直接变量初始化
f(std::move(v));	// #2, xvalue

int& lvalue();
int&& xvalue();
int prvalue();

std::is_same_v<decltype(lvalue()), int&>
std::is_same_v<decltype(xvalue()), int&&>
std::is_same_v<decltype(prvalue()), int>