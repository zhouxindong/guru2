#pragma once

/**
 * 1. 插入迭代器
 back_inserter, front_inserter, inserter
 接受一个容器，生成一个迭代器，向容器添加元素(赋值为当前位置插入元素push_back, push_front, insert)
 it = t;
 *it, ++it, it++	无操作，直接返回it

 copy(1st.cbegin(), lst.cend(), front_inserter(lst2);
 */

/**
 * 2. iostream迭代器
 将对应的流当作一个特定类型的元素序列来处理，可以用泛型算法从流对象读取数据或写入数据
 istream_iterator: 要读取的类型必须定义了输入运算符<<

 istream_iterator<int> int_in(cin);
 istream_iterator<int> int_eof;
 while(int_in != int_eof)
	vec.push_back(*int_in++);

 ifstream in("afile");
 istream_iterator<string> str_it(in);

 ostream_iterator: 要写入的类型必须定义了输出运算符>>
 ostream_iterator<int> out_iter(cout, " ");
 for(auto e : vec)
	*out_iter++ = e; // out_iter = e;
 // copy(vec.begin(), vec.end(), out_iter);
 */

/**
 * 3. 反向迭代器
 reverse_iterator
 */

/**
 * 4. 移动迭代器
 */