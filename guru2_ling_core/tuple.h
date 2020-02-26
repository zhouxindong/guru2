#pragma once

/**
 * 一个"快速而随意"的数据结构
 */
/**
 * 
 1. tuple<T1, T2, ..., Tn> t;
 2. tuple<T1, T2, ..., Tn> t(v1, v2, ..., vn);
 3. make_tuple(v1, v2, ..., vn);
 4. t1 == t2
 5. t1 != t2
 6. t1 relop t2
 7. get<i>(t) // 返回引用(左值引用或右值引用)
 8. tuple_size<tupleType>::value // 一个类模板，返回指定tuple类型中成员的数量
 9. tuple_element<i, tupleType>::type // 一个类模板，返回指定位置成员的类型
 */