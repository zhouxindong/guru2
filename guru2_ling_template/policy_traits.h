#pragma once
#include <type_traits>
#include <vector>

template <typename T>
struct RParam {
	using Type = typename std::conditional<sizeof(T) <= 2 * sizeof(void*), T, T const&>::type;
};

template <typename T>
struct RParam<std::vector<T> const&> {
	using Type = std::vector<T> const&;
};