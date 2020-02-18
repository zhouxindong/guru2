#pragma once

/**
 * 赋值运算符要求左边和右边的运算对象类型相同
 list<string> names;
 vector<const char*> oldstyle;
 names = oldstyle;	// 错误: 容器类型不匹配
 names.assign(oldstyle.cbegin(), oldstyle.cend());
 */

/**
 * swap(c1, c2);
 优先使用非成员版本的swap
 */

/**
 *
 push_back(t), emplace_back(args)
 push_front(t), emplace_front(args)
 insert(it, t), emplace(it, args) // 新元素位于it之前
 insert(it, n, t)
 insert(it, b, e)
 insert(it, li)
 */