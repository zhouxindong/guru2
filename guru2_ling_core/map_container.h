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
 * ��������������
 key_type		first
 mapped_type	second
 value_type   pair<const key_type, mapped_type>
 */

/**
 * ���ڹ���������ͨ����ʹ�÷����㷨(map��key��const����setԪ����constS)
 */

/**
 * Ϊʲô����ͨ��������ֱ���޸�keyֵ
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