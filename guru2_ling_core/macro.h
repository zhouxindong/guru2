#pragma once

#include <iostream>
using namespace std;

#define int double

void main()
{
	int iOne = 1;
	cout << sizeof(iOne) << endl;

	// ��ʱȡ��֮ǰ��int�궨��
#pragma push_macro("int")
#undef int

	int iTwo = 2;
	cout << sizeof(iTwo) << endl;

	// �ָ�֮ǰȡ����int�궨��
#pragma pop_macro("int")

	int iThree = 3;
	cout << sizeof(iThree) << endl;

	system("pause");
	return;
}
