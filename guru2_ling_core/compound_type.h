#pragma once

// 复合类型由基本类型+限定符组成
/**
 * 简单的复合类型包括: 指针，左值引用，右值引用，成员指针，数组等
 * 类和函数类型也是复合类型，但更加复杂(任意数量的成员或参数)
 */

static inline void lref()
{
	int i1 = 3;
	int &i2 = i1;

	// &i1 == &i2; i2不是对象，仅仅是i1的一个别名

	const int ci = 1024;
	const int &r1 = ci; // r1是常量引用

	// 1. const引用可以用临时对象初始化，因为临时对象都是不可变的
	// 2. const引用可以用非常量对象，只是不能通过此引用修改对象
}

static inline void pointer()
{
	int *p1; // 指针本身就是一个对象，可以赋值和拷贝，其值是某个对象的地址
	int **pp1; // 指针既然是对象，其本身也有地址

	int i1 = 33;
	int &i2 = i1;
	int *p3 = &i2; // 指向引用的指针是可以的，等同于p1 = &i1; 

	int *&r = p3; // 定义指针的引用，从右向左
	*r = 12; // r是指针p3的别名


	// 1. 允许一个指向常量的指针指向一个非常量对象(指针常量，限定指针所指的对象能不能通过此指针改变对象本身)
	// 底层const(仅与引用和指针等复合类型有关)
	const double pi = 3.14;
	const double *cptr = &pi;

	// 2. 指针是对象，其本身可以为常量(常量指针，限定指针本身能不能改变从而指向不同的对象)
	// 顶层const(对所有数据类型都适用)
	int errNumb = 0;
	int *const curErr = &errNumb;

	// 底层+顶层const
	const double *const pip = &pi;
}

static inline int fcn() 
{
	return 0;
}

/**
 * compound
  1. member_pointer: member_object_pointer, member_function_pointer
  2. pointer
  3. enum
  4. class(lambda)
  5. union
  6. array
  7. reference: lvalue_reference, rvalue_reference
  8. function
 */


