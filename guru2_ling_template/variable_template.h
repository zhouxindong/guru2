#pragma once
#include <utility>

template <typename T>
constexpr std::size_t SZ = sizeof(T);

template <typename T>
typename T::iterator null_iterator;
