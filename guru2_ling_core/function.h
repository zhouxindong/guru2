#pragma once
 
/**
 * 可变形参
 * 1. 实参类型相同: initializer_list
 * 2. 实参类型不同: 可变参数模板
 * 3. C函数: ...
 */

// 函数的返回类型决定函数调用是否是左值: 返回引用得到左值，其他返回类型得到右值。

/**
 * 简化函数返回类型的定义:
 * 1. 尾置返回类型: auto .... -> int (*) [10]
 * 2. decltype()
 */

// 函数重载无法跨越不同的作用域!(类的继承体系中基类和派生类定义的同名非虚拟函数无法形成重载)

/**
 * 函数对象
 plus<T>, minus<T>, multiplies<T>, divides<T>, modulus<T>, negate<T>
 equal_to<T>, not_equal_to<T>, greater<T>, greater_equal<T>, less<T>, less_equal<T>
 logical_and<T>, logical_or<T>, logical_not<T>
 */