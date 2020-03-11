#pragma once

/**
 * ���ģ�����T��Լ������
 T* T::Clone() const
 */
template <typename T>
class C
{
	bool ValidateRequirements() const
	{
		T* (T::*test)() const = &T::Clone;
		test;

		return true;
	}

public:
	~C()
	{
		static_assert(ValidateRequirements());
	}
};

/**
 * ʹ��Լ���࣬��ȷĳ��Լ�������д�Լ������ģ����������Ӧ��Լ����
 ������Ĺ��캯������Լ�����ȱʡ���캯�������Լ�����
 */
template <typename T>
class HasClone
{
public:
	static void Constraints()
	{
		T* (T::*test)() const = &T::Clone;
		test;
	}
	HasClone()
	{
		void(*p)() = Constraints;
	}
};

template <typename T>
class C : HasClone()
{
}