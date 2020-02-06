#pragma once
#include "qualifier.h"

template <typename T>
struct Decay : RemoveCV<T> {
};

template <typename T>
struct Decay<T[]> {
	using Type = T*;
};

template <typename T, std::size_t N>
struct Decay<T[N]> {
	using Type = T*;
};

template <typename R, typename... Args>
struct Decay<R(Args...)> {
	using Type = R(*)(Args...);
};