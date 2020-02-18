#pragma once

#include <string>

/**
 * 聚合类可以直接访问其成员，具有特殊的初始化语法形式
 满足条件:
 1. 所有成员都是public
 2. 没有构造函数
 3. 没有类内初始值
 4. 没有基类，没有虚拟函数
 */
struct Data {
	int ival;
	std::string s;
};

Data val1 = { 0, "Anna" };