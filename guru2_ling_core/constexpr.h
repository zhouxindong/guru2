#pragma once
// const expression
// 值不会改变，且在编译期计算
// 由数据类型和初始值共同决定能不能成为constexpr

/**
 * const int max_files = 20; // yes
 * const int limit = max_files + 1; // yes
 * int staff_size = 27; // no
 * const int sz = get_size(); // no
 */

/**
 * 允许将变量声明为constexpr类型，由编译器验证
 * constexpr int mf = 20;
 * constexpr int limit = mf + 1;
 * constexpr int sz = size(); // 只有当size是一个constexpr函数时声明才正确
 */

const int *p = nullptr; // 底层const
constexpr int *q = nullptr; // 顶层const

constexpr int i = 42;
constexpr const int *p = &i;