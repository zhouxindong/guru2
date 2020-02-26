#pragma once

/**
 * ������Ԫ�����Ƿ���ģ���໥�޹�
 1. һ��һ��Ԫ��ϵ
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
 * ͨ�ú��ض���ģ���Ѻù�ϵ
 һ������Խ���һ��ģ���ÿ��ʵ��������Ϊ��Ԫ�������޶��ض���ʵ��Ϊ��Ԫ
 */
template <typename T>
class Pal;

class C {
	friend class Pal<C>; // �ض�����
	template <typename T>
	friend class Pal2;	// ��������
};

template <typename T>
class C2 {
	friend class Pal<T>;

	template <typename X>
	friend class Pal2;

	friend class Pal3;
};

/**
 * ģ�����Ϊ��Ԫ
 */
template <typename T>
class Bar {
	friend T;
};