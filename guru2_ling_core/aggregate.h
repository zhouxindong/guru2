#pragma once

#include <string>

/**
 * �ۺ������ֱ�ӷ������Ա����������ĳ�ʼ���﷨��ʽ
 ��������:
 1. ���г�Ա����public
 2. û�й��캯��
 3. û�����ڳ�ʼֵ
 4. û�л��࣬û�����⺯��
 */
struct Data {
	int ival;
	std::string s;
};

Data val1 = { 0, "Anna" };