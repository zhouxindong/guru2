#pragma once
// 通过表达式推断类型
// auto 总是伴随着decay

// 1. 引用用作初始值时使用的是引用对象的值
/**
 * int i = 0;
 * int &r = i;
 * auto a = r; // auto -> int
 */

// 2. 忽略顶层const，保留底层const
/**
 * const int ci = 0;
 * const int &cr = ci;
 * auto b = ci; // auto -> int
 * auto e = &ci; // auto -> const int *
 */

// 3. 如果希望保留const或引用
/**
 * const auto f = ci;
 * auto &g = i; // 此时保留i的顶层常量属性
 * const auto &j = 42;
 */