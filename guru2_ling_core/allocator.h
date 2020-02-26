#pragma once
#include <memory>

/**
 * new将内存分配和对象构造组合在一起
 delete将对象析构和内存释放组合在一起
 */

/**
 * 可以将二者分开，先分配一大块内存，然后在这块内存上按需构造对象
 */

/**
 * allocator<T>
 allocator<T> a		// a可以为T的对象分配内存
 a.allocate(n)		// 分配可以保存n个T对象的原始内存
 a.deallocate(p, n)	// 释放从指针p地址开始的内存, 一共n个对象(别忘了之前要调用destroy析构对象)
 a.construct(p, args)	// 在p地址处构建对象
 a.destroy(p)			// 析构对象
 */

/**
 * 拷贝和填充未初始化内存的算法
 uninitialized_copy(b, e, b2)	// 迭代器[b, e)拷贝到b2指定的原始内存中
 uninitialized_copy_n(b, n, b2)	// 迭代器b开始拷贝n个元素
 uninitialized_fill(b, e, t)	// 填充t的拷贝至[b, e)指定的原始内存
 uninitialized_fill_n(b, n, t)	// 从b开始填充n个t对象的拷贝
 */