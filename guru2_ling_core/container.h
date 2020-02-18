#pragma once

/**
 * 容器通用操作
 1. 类型别名
 iterator
 const_iterator
 size_type			无符号整数类型
 difference_type
 value_type
 reference
 const_reference

 2. 构造函数
 C c
 C c1(c2)
 C c(b, e)
 C c{a, b, c...}

 3. 赋值与swap
 c1 = c2
 c1 = {a, b, c...}
 a.swap(b)
 swap(a, b)

 4. 大小
 c.size()
 c.max_size()
 c.empty()

 5. 添加/删除元素
 c.insert(args)		将args中的元素拷贝进c
 c.emplace(inits)	使用inits构造c中的一个元素
 c.erase(args)		删除args指定的元素
 c.clear()			删除c中的所有元素，返回void

 6. 关系运算符(使用元素的关系运算符完成比较==或<)
 ==, !=				所有容器都支持
 <, <=, >, >=		关系运算符(无序关联容器不支持)

 7. 获取迭代器
 c.begin(), c.end()
 c.cbegin(), c.cend()
 c.rbegin(), c.rend()
 c.crbegin(), c.crend()

 */