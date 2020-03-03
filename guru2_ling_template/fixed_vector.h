#pragma once

#include <algorithm>

/**
 * Òì³£°²È«
 */
template <typename T, size_t size>
class fixed_vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	fixed_vector() : v_(new T[size]) {}
	~fixed_vector() { delete[] v_; }

	template <typename U, size_t usize>
	fixed_vector(const fixed_vector<U, usize>& other) : v_(new T[size])
	{
		try {
			copy(other.begin(), other.begin() + min(size, usize), begin());
		}
		catch (...) {
			delete[] v_;
			throw;
		}
	}

	fixed_vector(const fixed_vector<T, size>& other)
		: v_(new T[size])
	{
		try {
			copy(other.begin(), other.end(), begin());
		}
		catch (...) {
			delete[] v_;
			throw;
		}
	}

	void Swap(fixed_vector<T, size>& other) noexcept
	{
		swap(v_, other.v_);
	}

	template <typename U, size_t usize>
	fixed_vector<T, size>& operator = (const fixed_vector<U, usize>& other)
	{
		fixed_vector<T, size> temp(other);
		Swap(temp);
		return *this;
	}

	fixed_vector<T, size>& operator = (const fixed_vector<T, size>& other) {
		fixed_vector<T, size> temp(other);
		Swap(temp);
		return *this;
	}


	iterator begin() {
		return v_;
	}

	iterator end() {
		return v_ + size;
	}

	const_iterator begin() const {
		return v_;
	}

	const_iterator end() const {
		return v_ + size;
	}

private:
	//T v_[size];
	T* v_; // more exceptional safe
};