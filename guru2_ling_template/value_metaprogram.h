#pragma once
#include <array>

template <typename T, std::size_t N>
auto dotProduct(std::array<T, N> const& x, std::array<T, N> const& y)
{
	T result{};
	for (std::size_t k = 0; k < N; ++k) {
		result += x[k] * y[k];
	}
	return result;
}

template <typename T, std::size_t N>
struct dotProductT {
	static inline T result(T* a, T* b) {
		return *a * *b + dotProductT<T, N - 1>::result(a + 1, b + 1);
	}
};

template <typename T>
struct dotProductT<T, 0> {
	static inline T result(T*, T*) {
		return T{};
	}
};

template <int N, int LO = 1, int HI = N>
struct Sqrt {
	static constexpr auto mid = (LO + HI + 1) / 2;

	// 编译器将实例化所有路径的类型，包括不选择的一边(巨大的编译期开销, condition_t)
	static constexpr auto value = (N < mid*mid) ? Sqrt<N, LO, mid - 1>::value : Sqrt<N, mid, HI>::value;
};

template <int N, int M>
struct Sqrt<N, M, M> {
	static constexpr auto value = M;
};

