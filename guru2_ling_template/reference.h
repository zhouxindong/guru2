#pragma once

/**
 * Removing References
 */
template <typename T>
struct RemoveReference {
	using Type = T;
};

template <typename T>
struct RemoveReference<T&> {
	using Type = T;
};

template <typename T>
struct RemoveReference<T&&> {
	using Type = T;
};

template <typename T>
using RemoveReferenceT = typename RemoveReference<T>::Type;

/**
 * Adding Reference
 */
template <typename T>
struct AddLValueReference {
	using Type = T&;
};

template <typename T>
struct AddRValueReference {
	using Type = T&&;
};

// special for void
template <>
struct AddLValueReference<void> {
	using Type = void;
};

template <>
struct AddLValueReference<void const> {
	using Type = void const;
};

template <>
struct AddLValueReference<void volatile> {
	using Type = void volatile;
};

template <>
struct AddLValueReference<void const volatile> {
	using Type = void const volatile;
};