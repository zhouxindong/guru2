#pragma once
/**
 * 四种基本类型的模板
 * 1. class template
 * 2. function template
 * 3. variable template
 * 4. alias template
 */
// global scope
template <typename T>
class Data {
public:
	static constexpr bool copyable = true;
};

template <typename T>
void log(T x) {
}

template <typename T>
T zero = 0;

template <typename T>
bool dataCopyable = Data<T>::copyable;

template <typename T>
using DataList = Data<T*>;

// class scope
class Collection {
public:
	template <typename T>
	class Node {};

	template <typename T>
	T* alloc() {
	}

	template <typename T>
	static T zero = 0;

	template <typename T>
	using NodePtr = Node<T>*;
};