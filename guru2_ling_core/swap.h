#pragma once
#include <utility>

/**
 * std::swap()ʹ�ö�����ƶ�����ͨ���ƶ��������Ż����󽻻�
 ��Ҳ����ͨ�������ض����swap�������������

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