#pragma once
// ͨ�����ʽ�ƶ�����
// auto ���ǰ�����decay

// 1. ����������ʼֵʱʹ�õ������ö����ֵ
/**
 * int i = 0;
 * int &r = i;
 * auto a = r; // auto -> int
 */

// 2. ���Զ���const�������ײ�const
/**
 * const int ci = 0;
 * const int &cr = ci;
 * auto b = ci; // auto -> int
 * auto e = &ci; // auto -> const int *
 */

// 3. ���ϣ������const������
/**
 * const auto f = ci;
 * auto &g = i; // ��ʱ����i�Ķ��㳣������
 * const auto &j = 42;
 */