#pragma once

template <typename T, T val>
struct integral_constant2 {
	static constexpr T value = val;
	using value_type = T;
	using type = integral_constant2<T, val>;

	constexpr operator value_type() const noexcept {
		return value;
	}

	constexpr value_type operator() () const noexcept {
		return value;
	}
};

template <bool B>
using bool_constant2 = integral_constant2<bool, B>;
using true_type2 = bool_constant2<true>;
using false_type2 = bool_constant2<false>;