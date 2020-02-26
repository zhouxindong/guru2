#pragma once

template <typename T>
class Foo
{
public:
	Foo(T elem) : elem_{ elem }
	{}

private:
	T elem_;
};

// class template argument deduce guides
// Foo(char const*) -> Foo<std::string>; 

/**
 * 全局特化不是类模板，而是普通类
 * 其定义可以与基本模板完全不同，它们之间的关联仅仅是类名称
 * 全局特化类的定义不能使用template<>
 */
template <typename T>
class S;

template<> class S<char**> {
public:
	void print() const;
};

void S<char**>::print() const{}

template <typename T>
class Outside
{
public:
	template <typename U>
	class Inside {
	};
};

template<>
class Outside<void> {
	template <typename U>
	class Inside {
	private:
		static int count;
	};
};

template <typename U>
int Outside<void>::Inside<U>::count = 1;

// a sample for full member specialization
template <typename T>
class Outer {
public:
	template <typename U>
	class Inner {
	private:
		static int count;
	};

	static int code;
	void print() const {
	}
};

template <typename T>
int Outer<T>::code = 6;

template <typename T>
template <typename U>
int Outer<T>::Inner<U>::count = 7;

template<>
class Outer<bool> {
public:
	template <typename U>
	class Inner {
	private:
		static int count;
	};
	void print() const {}
};

template<>
int Outer<void>::code = 12;

template<>
void Outer<void>::print() const {}

//template<>

/**
 * Tag Dispatching for class Templates
 */
template <typename Iterator, typename Tag>
class Advance;

template <typename Iterator>
class Advance<Iterator, std::input_iterator_tag>
{
};

template <typename Iterator>
class Advance<Iterator, std::bidirectional_iterator_tag>
{
};

/**
 * 特化需要注意的是一定要在使用之前定义，否则就会使用模板去生成了
 特化定义要和模板原本在同一名称空间中
 示例: 为Sales_data类型特化std::hash<T>，使其类型可以置于无序容器中
 */
#include <xstddef>
#include <string>
struct Sales_data {
	std::string bookNo;
	unsigned int units_sold;
	double revenue;
};
namespace std {
	template <>
	struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef Sales_data argument_type; // need ==
		size_t operator() (const Sales_data& s) const {
			return hash<std::string>()(s.bookNo) ^
				hash<unsigned int>()(s.units_sold) ^
				hash<double>()(s.revenue);

		}
	};
}