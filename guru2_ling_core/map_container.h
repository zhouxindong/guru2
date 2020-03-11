#pragma once

/**
 * map
 * set
 * multimap
 * multiset
 */
/**
 * key <
 */

/**
 * 关联容器类别别名
 key_type		first
 mapped_type	second
 value_type   pair<const key_type, mapped_type>
 */

/**
 * 对于关联容器，通常不使用泛型算法(map的key是const，而set元素是constS)
 */

/**
 * 为什么不能通过迭代器直接修改key值
 map<int, string> m;
 m.insert(std::make_pair(299, "A.E. Van Vogt"));
 m.insert(std::make_pair(144, "Robert A.Heinlein"));
 m.insert(std::make_pair(13, "Joe Haldeman"));
 m.insert(std::make_pair(151, "E.E.Smith"));
 m.insert(std::make_pair(148, "Alfred Bester"));
 m.insert(std::make_pair(516, "Lester Del Rey"));
 m.insert(std::make_pair(12, "Larry Niven"));

 auto it = m.find(13);
 if (it != m.end())
 {
 const_cast<int&>(it->first) = 99999;
 }

 it = m.find(144);
 if (it == m.end())
 cout << "can't find 144\n";

 */