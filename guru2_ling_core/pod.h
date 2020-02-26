#pragma once

/**
 * POD = trival + standard layout(std::is_pod)
 1. trival(std::is_trivial)
 1.1 trival ctor, trival dtor(缺省构造，不定义或使用default)
 1.2 trival copy ctor, trival move ctor(不定义或使用default)
 1.3 trival = copy operator, move operator(不定义或使用default)
 没有虚函数和虚基类

 2. standard layout(std::is_standard_layout)
 2.1 所有非静态成员访问权限相同
 2.2 派生类有非静态成员，只有一个基类且基类只包含静态成员
	 或基类有非静态成员，而派生类没有非静态成员
 2.3 类中的第一个非静态成员的类型不能是其基类类型
 2.4 没有虚函数和虚基类
 2.5 所有非静态数据成员都是标准布局
 */

/**
 * POD
 1. 字节赋值: memset, memcpy
 2. C内存布局兼容
 3. 静态初始化安全有效
 */