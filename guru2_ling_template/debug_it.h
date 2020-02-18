#pragma once

template <typename T>
void clear(T& p)
{
	*p = 0; // assumes T is a pointer-like type
}

template <typename T>
void core(T& p)
{
	clear(p);
}

template <typename T>
void middle(typename T::Index p)
{
	core(p);
}

template <typename T>
void shell(T const& env)
{
	typename T::Index i;
	middle<T>(i);
}

class Client
{
public:
	using Index = int;
};