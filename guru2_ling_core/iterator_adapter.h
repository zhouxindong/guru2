#pragma once

/**
 * 1. ���������
 back_inserter, front_inserter, inserter
 ����һ������������һ�������������������Ԫ��(��ֵΪ��ǰλ�ò���Ԫ��push_back, push_front, insert)
 it = t;
 *it, ++it, it++	�޲�����ֱ�ӷ���it

 copy(1st.cbegin(), lst.cend(), front_inserter(lst2);
 */

/**
 * 2. iostream������
 ����Ӧ��������һ���ض����͵�Ԫ�����������������÷����㷨���������ȡ���ݻ�д������
 istream_iterator: Ҫ��ȡ�����ͱ��붨�������������<<

 istream_iterator<int> int_in(cin);
 istream_iterator<int> int_eof;
 while(int_in != int_eof)
	vec.push_back(*int_in++);

 ifstream in("afile");
 istream_iterator<string> str_it(in);

 ostream_iterator: Ҫд������ͱ��붨������������>>
 ostream_iterator<int> out_iter(cout, " ");
 for(auto e : vec)
	*out_iter++ = e; // out_iter = e;
 // copy(vec.begin(), vec.end(), out_iter);
 */

/**
 * 3. ���������
 reverse_iterator
 */

/**
 * 4. �ƶ�������
 */