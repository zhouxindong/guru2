#pragma once

/**
 * һ��"���ٶ�����"�����ݽṹ
 */
/**
 * 
 1. tuple<T1, T2, ..., Tn> t;
 2. tuple<T1, T2, ..., Tn> t(v1, v2, ..., vn);
 3. make_tuple(v1, v2, ..., vn);
 4. t1 == t2
 5. t1 != t2
 6. t1 relop t2
 7. get<i>(t) // ��������(��ֵ���û���ֵ����)
 8. tuple_size<tupleType>::value // һ����ģ�壬����ָ��tuple�����г�Ա������
 9. tuple_element<i, tupleType>::type // һ����ģ�壬����ָ��λ�ó�Ա������
 */