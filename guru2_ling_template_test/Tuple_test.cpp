#include "stdafx.h"
#include "Tuple.h"
#include <iostream>
#include <string>

/*
int main()
{
	static_assert(IsEmpty<Tuple<>>::value, "IsEmpty() failed");

	Tuple<int, double, std::string> t1(17, 3.14, "Hello, World!");
	using T2 = PopFront<PushBack<decltype(t1), bool>>;
	T2 t2(get<1>(t1), get<2>(t1), true);
	std::cout << t2 << '\n';

	auto t3 = pushFront(t2, 18);
	std::cout << t3 << '\n';

	auto t4 = pushBack(t3, 99.9999);
	std::cout << t4 << '\n';

	auto t5 = popFront(t4);
	std::cout << t5 << '\n';

	auto t6 = reverse(t5);
	std::cout << t6 << '\n';

	system("pause");
	return 0;
}
//*/