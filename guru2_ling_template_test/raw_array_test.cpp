#include "stdafx.h"
#include "raw_array.h"

template <typename T1, typename T2, typename T3>
void foo(
	int a1[7], int a2[],	// pointers by language rules
	int(&a3)[42],			// reference to array of known bound
	int(&x0)[],				// reference to array of unknown bound
	T1 x1,					// passing by value decays
	T2& x2, T3&& x3			// passing by reference
)
{
	MyClass<decltype(a1)>::print();	// print() for T*
	MyClass<decltype(a2)>::print();	// print() for T*
	MyClass<decltype(a3)>::print();	// print() for T(&)[42]
	MyClass<decltype(x0)>::print();	// print() for T(&)[]
	MyClass<decltype(x1)>::print();	// print() for T*
	MyClass<decltype(x2)>::print();	// print() for T(&)[]
	MyClass<decltype(x3)>::print();	// print() for T(&)[]
}

//int main()
//{
//	int a[42];
//	MyClass<decltype(a)>::print(); // print() for T[42]
//
//	extern int x[];	// forward declare array
//	MyClass<decltype(x)>::print(); // print() for T[]
//
//	foo(a, a, a, x, x, x, x);
//
//	system("pause");
//	return 0;
//}

int x[] = { 0,8,15 };