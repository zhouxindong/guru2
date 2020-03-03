#pragma once

// 模板构造函数或模板赋值运算符并不会取代预定义的构造函数或赋值运算符
// 构造对象或对象赋值时，模板函数并不会被考虑

#include <utility>
#include <string>
#include <iostream>

class Person
{
private:
	std::string name;

public:
	explicit Person(std::string const& n) : name(n) {	// #1
		std::cout << "copying string-CONSTR for '" << name << "'\n";
	}

	explicit Person(std::string&& n) : name(std::move(n)) {	// #2
		std::cout << "moving string-CONSTR for '" << name << "'\n";
	}

	Person(Person const& p) : name(p.name) {			// #3
		std::cout << "COPY-CONSTR Person '" << name << "'\n";
	}

	Person(Person&& p) : name(std::move(p.name)) {		// #4
		std::cout << "MOVE-CONSTR Person '" << name << "'\n";
	}
};

void foo()
{
	std::string s = "sname";
	Person p1(s);		// #1
	Person p2("tmp");	// #2
	Person p3(p1);		// #3
	Person p4(std::move(p1));	// #4
}

class Person2
{
private:
	std::string name;
public:
	// generic constructor for passed initial name:
	template <typename STR>
	explicit Person2(STR&& n) : name(std::forward<STR>(n)) {	// #1
		std::cout << "TMPL-CONSTR for '" << name << "'\n";
	}

	// copy and move constructor
	Person2(Person2 const& p) : name(p.name) {					// #2
		std::cout << "COPY-CONSTR Person '" << name << "'\n";
	}

	Person2(Person2&& p) : name(std::move(p.name)) {			// #3
		std::cout << "MOVE-CONSTR Person '" << name << "'\n";
	}
};

void foo2()
{
	std::string s = "sname";
	Person2 p1(s);		// #1
	Person2 p2("tmp");	// #1 -> char const[4]
	//Person2 p3(p1);		// ERROR! because non-const lvalue, #1 is better than #2(#2 need convert to const)
							// (1# don't need converted) STR with Person2&
	Person2 p4(std::move(p1));	// #3
	Person2 const p2c("ctmp");	// #1
	Person2 p3c(p2c);			// #2
}

// 1# 匹配优于 2#，因为2#需要转换为const，增加非 const版本并非良策
// 我们真正需要的是当传递的参数是Person或能够转换为Person的表达式时，禁用模板成员函数(enable_if<>)
class Person3
{
private:
	std::string name;
public:
	// generic constructor for passed initial name:
	template <typename STR,
			  typename = std::enable_if_t<
							std::is_convertible_v<STR, std::string>>>
	explicit Person3(STR&& n) : name(std::forward<STR>(n)) {	// #1
		std::cout << "TMPL-CONSTR for '" << name << "'\n";
	}

	// copy and move constructor
	Person3(Person3 const& p) : name(p.name) {					// #2
		std::cout << "COPY-CONSTR Person '" << name << "'\n";
	}

	Person3(Person3&& p) : name(std::move(p.name)) {			// #3
		std::cout << "MOVE-CONSTR Person '" << name << "'\n";
	}
};

void foo3()
{
	std::string s = "sname";
	Person3 p1(s);				// 1#
	Person3 p2("tmp");			// 1#

	Person3 p3(p1);				// 2#
	Person3 p4(std::move(p1));	// 3#
}

/**
* 从函数模板生成的函数永远不等于一个普通函数，即使拥有的类型和名称
* 从函数模板生成的函数永远不会重写一个虚拟函数
* 从构造函数模板生成的构造函数永远不能成为一个拷贝或移动构造函数
* 从赋值函数模板生成的赋值函数也永远不能成为一个拷贝或移动赋值函数
*/

/**
 * 由于模板构造函数不能成为拷贝构造函数，因此即使有单模板参数，且形如const T&的函数定义，
 在类中仍然会隐式声明拷贝构造函数。模板构造函数将与其他构造函数(包括拷贝构造函数)一起参与到重载解析中
 如果模板构造函数比其他的构造函数更匹配，那么将会调用它来对对象进行赋值。
 */

class C
{
public:
	C() = default;
	C(C const&) {}	// #1
	C(C&&) {}		// #2
	template <typename T>
	C(T&&) {}		// #3
};

void foo4()
{
	C x;
	C x2{ x };				// #3
	C x3{ std::move(x) };	// #2
	C const c;
	C x4{ c };				// #1
	C x5{ std::move(c) };	// #3
}