#pragma once
#include <type_traits>
#include <utility>

template <typename FROM, typename TO>
struct IsConvertible {
private:
	static void aux(TO);

	template <typename F, typename, typename = decltype(aux(std::declval<F>()))>
	static std::true_type test(void*);

	template <typename, typename>
	static std::false_type test(...);

public:
	using Type = decltype(test<FROM>(nullptr));
};