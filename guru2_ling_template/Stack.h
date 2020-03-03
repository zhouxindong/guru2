#pragma once

/**
 * �쳣��ȫ: �����׳�ʲô�����쳣������ʼ�մ�����ȷ�ĺ�һ�µ�״̬
 * �쳣����: �쳣ת����������
 */
#include <cassert>
#include <algorithm>
#include <utility>

template <T>
T* NewCopy(const T* src, size_t srcsize, size_t destsize)
{
	assert(destsize >= srcsize);
	T* dest = new T[destsize];
	try {
		std::copy(src, src + srcsize, dest);
	}
	catch (...)
	{
		delete[] dest;
		throw;
	}
	return dest;
}

template <class T1, class T2>
void construct(T1* p, const T2& value)
{
	new(p) T1(value);
}

template <class T>
void destroy(T* p)
{
	p->~T();
}

template <class FwdIter>
void destroy(FwdIter first, FwdIter last)
{
	while (first != last) {
		destroy(&*first);
		++first;
	}
}

/**
 * StackImpl
 ��������ڴ滺����������������ڴ滺����ͷ�
 */
template <class T>
class StackImpl
{
protected:
	StackImpl(size_t size = 0) 
		: v_(static_cast<T*>(
			size == 0
			? 0
			: operator new(sizeof(T)*size))),
		vsize_(size),
		vused_(0) {}
	
	~StackImpl()
	{
		destroy(v_, v_ + vused_);
		operator delete(v_);
	}

	void Swap(StackImpl& other) noexcept
	{
		std::swap(v_, other.v_);
		std::swap(vsize_, other.vsize_);
		std::swap(vused_, other.vused_);
	}

	T* v_;
	size_t vsize_;
	size_t vused_;

private:
	StackImpl(const StackImpl&) = delete;
	StackImpl& operator=(const StackImpl&) = delete;
};

/**
 * �����ڳ�ʼ�ڴ��й������
 ����ʹ�û����Ӷ�����ʵʹ�������ʽ�ĳ�Ա�Ӷ���Ҳ���ԣ����Ҹ���
 �ŵ�: ֻͨ�������ӿ�
 ʹ�û����Ӷ���:
 1. ��Ҫ���������ı�����Ա
 2. ��Ҫ����ĳ���麯��
 3. ���������Ҫ�ڻ����Ӷ���֮ǰ������
 */
template <class T>
class Stack : private StackImpl<T>
{
public:
	Stack(size_t size = 0) 
		: StackImpl<T>(size)
	{
	}

	~Stack() = default;

	Stack(const Stack& other) 
		: StackImpl<T>(other.vused_)
	{
		while (vused_ < other.vused_)
		{
			construct(v_ + vused_, other.v_[vused_]);
			++vused_;
		}
	}

	Stack& operator=(const Stack& other)
	{
		Stack temp(other);
		Swap(temp);
		return *this;
	}

	//Stack& operator=(Stack temp)
	//{
	//	Swap(temp);
	//	return *this;
	//}

	size_t Count() const
	{
		return vused_;
	}

	void Push(const T& t)
	{
		if (vused_ == vsize_)
		{
			Stack temp(vsize_ * 2 + 1);
			while (temp.Count() < vused_)
			{
				temp.Push(v_[temp.Count()]);
			}
			temp.Push(t);
			Swap(temp);
		}
		else
		{
			construct(v_ + vused_, t);
			++vused_;
		}
	}

	T& Top()
	{
		if (vused_ == 0)
		{
			throw "empty stack";
		}
		return v_[vused_];
	}

	void Pop()
	{
		if (vused_ == 0)
			throw "pop from empty stack";
		else
		{
			--vused_;
			destroy(v_ + vused_);
		}
	}
};