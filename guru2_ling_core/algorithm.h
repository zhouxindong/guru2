#pragma once
/**
 * 迭代器令算法不依赖于容器，但算法依赖于元素类型的操作(==, <等)
 算法永远不会执行容器的操作，其实算法对容器一无所知
 向目标位置迭代器写入数据的算法都是假定目标位置足够大，能够容纳写入的元素。(除非使用特定的迭代器)
 */

/**
 * 操作两个序列的算法之间的区别在于我们如何传递第二个序列：
 1. 首位置迭代器
 假定第二个序列至少与第一个一样长

 2. 两个迭代器表示的区间
 */

/**
 * 算法形参模式
 alg(beg, end, other args)
 alg(beg, end, dest, other args)		// 目标迭代器的目标空间足够
 alg(beg, end, beg2, other args)
 alg(beg, end, beg2, end2, other args)
 */

/**
 * 算法命名规范
 1. 提供谓词
 unique(beg, end);		// ==比较元素
 unique(beg, end, comp);

 2. _if 用谓词代替指定值
 find(beg, end, val)
 find_if(beg, end, pred)

 3. 拷贝版本和非拷贝版本
 拷贝版本写回输入序列，非拷贝版本写到指定的输出目标位置
 reverse(beg, end)
 reverse_copy(beg, end, dest);
 */