#pragma once

/**
 * 类与友元各自是否是模板相互无关
 1. 一对一友元关系
 */
template <typename>
class BlobPtr;

template <typename>
class Blob;

template <typename T>
bool operator == (const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
};

/**
 * 通用和特定的模板友好关系
 一个类可以将另一个模板的每个实例都声明为友元，或者限定特定的实例为友元
 */
template <typename T>
class Pal;

class C {
	friend class Pal<C>; // 特定类型
	template <typename T>
	friend class Pal2;	// 所有类型
};

template <typename T>
class C2 {
	friend class Pal<T>;

	template <typename X>
	friend class Pal2;

	friend class Pal3;
};

/**
 * 模板参数为友元
 */
template <typename T>
class Bar {
	friend T;
};