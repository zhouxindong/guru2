#pragma once
#include <utility>

/**
 * std::swap()使用对象的移动语义通过移动构造来优化对象交换
 你也可以通过定义特定类的swap重载来提高性能

 */

class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
private:
	int i;
	double* ps;
};

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	//_Ty _Tmp = _STD move(_Left);
	//_Left = _STD move(_Right);
	//_Right = _STD move(_Tmp);

	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}