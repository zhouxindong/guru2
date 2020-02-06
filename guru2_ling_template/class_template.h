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
 * ȫ���ػ�������ģ�壬������ͨ��
 * �䶨����������ģ����ȫ��ͬ������֮��Ĺ���������������
 * ȫ���ػ���Ķ��岻��ʹ��template<>
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
