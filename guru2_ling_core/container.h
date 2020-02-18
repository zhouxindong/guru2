#pragma once

/**
 * ����ͨ�ò���
 1. ���ͱ���
 iterator
 const_iterator
 size_type			�޷�����������
 difference_type
 value_type
 reference
 const_reference

 2. ���캯��
 C c
 C c1(c2)
 C c(b, e)
 C c{a, b, c...}

 3. ��ֵ��swap
 c1 = c2
 c1 = {a, b, c...}
 a.swap(b)
 swap(a, b)

 4. ��С
 c.size()
 c.max_size()
 c.empty()

 5. ���/ɾ��Ԫ��
 c.insert(args)		��args�е�Ԫ�ؿ�����c
 c.emplace(inits)	ʹ��inits����c�е�һ��Ԫ��
 c.erase(args)		ɾ��argsָ����Ԫ��
 c.clear()			ɾ��c�е�����Ԫ�أ�����void

 6. ��ϵ�����(ʹ��Ԫ�صĹ�ϵ�������ɱȽ�==��<)
 ==, !=				����������֧��
 <, <=, >, >=		��ϵ�����(�������������֧��)

 7. ��ȡ������
 c.begin(), c.end()
 c.cbegin(), c.cend()
 c.rbegin(), c.rend()
 c.crbegin(), c.crend()

 */