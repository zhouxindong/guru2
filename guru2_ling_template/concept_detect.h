#pragma once

/**
 * 检测模板参数T的约束条件
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
 * 使用约束类，明确某个约束，让有此约束的类模板派生于相应的约束类
 派生类的构造函数调用约束类的缺省构造函数，完成约束检查
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