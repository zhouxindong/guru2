#pragma once
// ֻ����Ҫ���ʽ�����ͣ���������ֵ��ʼ��
// �ɱ������������ʽ�õ������ͣ�����ʵ�ʼ�����ʽ��ֵ

// ע��: ����const�Ĵ�����auto��ͬ
// 1. decltypeʹ�õı��ʽ��һ���������򷵻ظñ�������������
/**
 * const int ci = 0;
 * const int &cj = ci;
 * decltype(ci) x = 0; // const int
 * decltype(cj) y = x; // const int&
 */

// 2. decltypeʹ�õı��ʽ����һ���������򷵻ر��ʽ�����Ӧ������
/**
 * int i = 42;
 * int *p = &i;
 * int &r = i;
 * decltype(r+0) b; // int
 * decltype(*p) c = i; // int & (*p���ض��󣬿��Ա���ֵ�����������)
 * decltype(i); // int
 * decltype((i)); // �������ʽ��һ�ֿ�����Ϊ��ֵ�����ֵ��������ʽ�������� int &
 */