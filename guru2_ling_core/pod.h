#pragma once

/**
 * POD = trival + standard layout(std::is_pod)
 1. trival(std::is_trivial)
 1.1 trival ctor, trival dtor(ȱʡ���죬�������ʹ��default)
 1.2 trival copy ctor, trival move ctor(�������ʹ��default)
 1.3 trival = copy operator, move operator(�������ʹ��default)
 û���麯���������

 2. standard layout(std::is_standard_layout)
 2.1 ���зǾ�̬��Ա����Ȩ����ͬ
 2.2 �������зǾ�̬��Ա��ֻ��һ�������һ���ֻ������̬��Ա
	 ������зǾ�̬��Ա����������û�зǾ�̬��Ա
 2.3 ���еĵ�һ���Ǿ�̬��Ա�����Ͳ��������������
 2.4 û���麯���������
 2.5 ���зǾ�̬���ݳ�Ա���Ǳ�׼����
 */

/**
 * POD
 1. �ֽڸ�ֵ: memset, memcpy
 2. C�ڴ沼�ּ���
 3. ��̬��ʼ����ȫ��Ч
 */