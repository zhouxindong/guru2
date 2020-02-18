#include "stdafx.h"
#include "type_list.h"
#include <type_traits>

/*
int main()
{
	using TestType = Typelist<signed char, short, int, long, long long>;
	static_assert(std::is_same_v<signed char, Front<TestType>>, "Front() failed");

	static_assert(std::is_same_v<Typelist<short, int, long, long long>,
		PopFront<TestType>>, "PopFront() failed");

	static_assert(std::is_same_v<Typelist<bool, signed char, short, int, long, long long>,
		PushFront<TestType, bool>>, "PushFront() failed");

	static_assert(
		std::is_same_v<signed char, NthElement<TestType, 0>> &&
		std::is_same_v<short, NthElement<TestType, 1>> &&
		std::is_same_v<int, NthElement<TestType, 2>> &&
		std::is_same_v<long, NthElement<TestType, 3>> &&
		std::is_same_v<long long, NthElement<TestType, 4>>,
		"NthElement() failed"
		);

	static_assert(std::is_same_v<long long, LargestType<TestType>>, "LargestType() failed");

	static_assert(!IsEmpty<TestType>::value, "IsEmpty() failed");
	static_assert(IsEmpty<Typelist<>>::value, "IsEmpty() failed");

	static_assert(
		std::is_same_v<Typelist<signed char, short, int, long, long long, bool>, PushBack<TestType, bool>>,
		"PushBack() failed"
		);

	static_assert(
		std::is_same_v<Typelist<long long, long, int, short, signed char>, Reverse<TestType>>,
		"Reverse() failed"
		);

	static_assert(
		std::is_same_v<Typelist<signed char, short, int, long>, PopBack<TestType>>, "PopBack() failed"
		);

	system("pause");
	return 0;
}
*/