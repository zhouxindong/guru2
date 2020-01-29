#pragma once
template <typename T>
void f(T)
{
}

template void f<int>(int);
template void f<>(float);
template void f(long);
template void f(char);

template <typename T>
class S
{
public:
	void f()
	{
	}
};

template void S<int>::f();
template class S<void>;

// 上述显式实例化是函数定义

// .hpp
extern template void f<unsigned long long>(unsigned long long); // declared

// .cpp
template void f<unsigned long long>(unsigned long long);	// definition