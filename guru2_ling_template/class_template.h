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