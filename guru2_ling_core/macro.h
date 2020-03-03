#pragma once

#include <iostream>
using namespace std;

#define int double

void main()
{
	int iOne = 1;
	cout << sizeof(iOne) << endl;

	// 暂时取消之前的int宏定义
#pragma push_macro("int")
#undef int

	int iTwo = 2;
	cout << sizeof(iTwo) << endl;

	// 恢复之前取消的int宏定义
#pragma pop_macro("int")

	int iThree = 3;
	cout << sizeof(iThree) << endl;

	system("pause");
	return;
}
