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
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}