#include "stdafx.h"
#include "type_erasure.h"
#include <vector>
#include <iostream>

using namespace std;

void forUpTo(int n, FunctionPtr<void(int)>f)
{
	for (int i = 0; i != n; ++i)
	{
		f(i);
	}
}

void printInt(int i)
{
	std::cout << i << ' ';
}

//int main()
//{
//	std::vector<int> values;
//	forUpTo(5,
//		[&values](int i) {
//		values.push_back(i);
//	});
//
//	forUpTo(5, printInt);
//	system("pause");
//	return 0;
//}