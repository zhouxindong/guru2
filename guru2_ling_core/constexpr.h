#pragma once
// const expression
// ֵ����ı䣬���ڱ����ڼ���
// ���������ͺͳ�ʼֵ��ͬ�����ܲ��ܳ�Ϊconstexpr

/**
 * const int max_files = 20; // yes
 * const int limit = max_files + 1; // yes
 * int staff_size = 27; // no
 * const int sz = get_size(); // no
 */

/**
 * ������������Ϊconstexpr���ͣ��ɱ�������֤
 * constexpr int mf = 20;
 * constexpr int limit = mf + 1;
 * constexpr int sz = size(); // ֻ�е�size��һ��constexpr����ʱ��������ȷ
 */

const int *p = nullptr; // �ײ�const
constexpr int *q = nullptr; // ����const

constexpr int i = 42;
constexpr const int *p = &i;