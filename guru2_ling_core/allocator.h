#pragma once
#include <memory>

/**
 * new���ڴ����Ͷ����������һ��
 delete�������������ڴ��ͷ������һ��
 */

/**
 * ���Խ����߷ֿ����ȷ���һ����ڴ棬Ȼ��������ڴ��ϰ��蹹�����
 */

/**
 * allocator<T>
 allocator<T> a		// a����ΪT�Ķ�������ڴ�
 a.allocate(n)		// ������Ա���n��T�����ԭʼ�ڴ�
 a.deallocate(p, n)	// �ͷŴ�ָ��p��ַ��ʼ���ڴ�, һ��n������(������֮ǰҪ����destroy��������)
 a.construct(p, args)	// ��p��ַ����������
 a.destroy(p)			// ��������
 */

/**
 * ���������δ��ʼ���ڴ���㷨
 uninitialized_copy(b, e, b2)	// ������[b, e)������b2ָ����ԭʼ�ڴ���
 uninitialized_copy_n(b, n, b2)	// ������b��ʼ����n��Ԫ��
 uninitialized_fill(b, e, t)	// ���t�Ŀ�����[b, e)ָ����ԭʼ�ڴ�
 uninitialized_fill_n(b, n, t)	// ��b��ʼ���n��t����Ŀ���
 */