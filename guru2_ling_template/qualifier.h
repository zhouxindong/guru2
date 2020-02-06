#pragma once

template <typename T>
struct RemoveConst {
	using Type = T;
};

template <typename T>
struct RemoveConst<T const> {
	using Type = T;
};

template <typename T>
using RemoveConstT = typename RemoveConst<T>::Type;

template <typename T>
struct RemoveVolatile {
	using Type = T;
};

template <typename T>
struct RemoveVolatile<T volatile> {
	using Type = T;
};

template <typename T>
using RemoveVolatileT = typename RemoveVolatile<T>::Type;

template <typename T>
struct RemoveCV : RemoveConst<typename RemoveVolatile<T>::Type> {
};