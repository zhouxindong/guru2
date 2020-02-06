#include "stdafx.h"
#include "Tuple.h"
#include <iostream>
#include <string>

int main()
{
	Tuple<int, double, std::string> t1(17, 3.14, "Hello, World!");
	using T2 = typename PopFront<typename PushBack<decltype(t1), bool>::Type>::Type;
	T2 t2(get<1>(t1), get<2>(t1), true);
	std::cout << t2 << '\n';

	auto t3 = pushFront(t2, 18);
	std::cout << t3 << '\n';
	system("pause");
	return 0;
}