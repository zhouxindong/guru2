#pragma once
#include <utility>

template <typename T>
class ValuePtr
{
public:
	explicit ValuePtr(T* p = 0) : p_(p) {}

	~ValuePtr() {
		delete p_;
	}

	T& operator*() const {
		return *p_;
	}

	T* operator->() const {
		return p_;
	}

	void Swap(ValuePtr& other)
	{
		std::swap(p_, other.p_);
	}

	//ValuePtr(const ValuePtr&) = delete;
	//ValuePtr& operator=(const ValuePtr&) = delete;

	ValuePtr(const ValuePtr& other) : p_(CreateFrom(other.p_)) {}

	ValuePtr& operator=(const ValuePtr& other)
	{
		ValuePtr temp(other);
		Swap(temp);
		return *this;
	}

	template <typename U>
	ValuePtr(const ValuePtr<U>& other) :
		p_(CreateFrom(other.p_)) {}

	template <typename U>
	ValuePtr& operator=(const ValuePtr<U>& other)
	{
		ValuePtr temp(other);
		Swap(temp);
		return *this;
	}

private:
	template <typename U>
	T* CreateFrom(const U* p) const {
		return p ? VPTraits<U>::Clone(p) : 0;
	}

	template <typename U> friend class ValuePtr;

private:
	T* p_;
};

class Y {
public:
	Y* CloneMe() const {
		return new Y;
	}
};

template <typename T>
class VPTraits
{
public:
	static T* Clone(const T* p)
	{
		return new T(*p);
	}
};

template <>
class VPTraits<Y>
{
public:
	static Y* Clone(const Y* p) {
		return p->CloneMe();
	}
};