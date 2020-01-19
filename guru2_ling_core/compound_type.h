#pragma once

static inline void lref()
{
	int i1 = 3;
	int &i2 = i1;

	// &i1 == &i2; i2���Ƕ��󣬽�����i1��һ������

	const int ci = 1024;
	const int &r1 = ci; // r1�ǳ�������

	// 1. const���ÿ�������ʱ�����ʼ������Ϊ��ʱ�����ǲ��ɱ��
	// 2. const���ÿ����÷ǳ�������ֻ�ǲ���ͨ���������޸Ķ���
}

static inline void pointer()
{
	int *p1; // ָ�뱾������һ�����󣬿��Ը�ֵ�Ϳ�������ֵ��ĳ������ĵ�ַ
	int **pp1; // ָ���Ȼ�Ƕ����䱾��Ҳ�е�ַ

	int i1 = 33;
	int &i2 = i1;
	int *p3 = &i2; // ָ�����õ�ָ���ǿ��Եģ���ͬ��p1 = &i1; 

	int *&r = p3; // ����ָ������ã���������
	*r = 12; // r��ָ��p3�ı���


	// 1. ����һ��ָ������ָ��ָ��һ���ǳ�������(ָ�볣�����޶�ָ����ָ�Ķ����ܲ���ͨ����ָ��ı������)
	// �ײ�const(�������ú�ָ��ȸ��������й�)
	const double pi = 3.14;
	const double *cptr = &pi;

	// 2. ָ���Ƕ����䱾������Ϊ����(����ָ�룬�޶�ָ�뱾���ܲ��ܸı�Ӷ�ָ��ͬ�Ķ���)
	// ����const(�������������Ͷ�����)
	int errNumb = 0;
	int *const curErr = &errNumb;

	// �ײ�+����const
	const double *const pip = &pi;
}

static inline int fcn() 
{
	return 0;
}

// const��Ҫ�����ƾ���ֻ����const���Ͷ�����ִ�в��ı������ݵĲ���
// ȱʡ״̬�£�const��������ļ�����Ч
const int kBufSize = 512;

// const�������һ�����壬�����ļ��й���
// extern const int kBufSize = fcn(); .cpp
// extern const int kBufSize; //.h