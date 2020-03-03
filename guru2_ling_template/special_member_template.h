#pragma once

// ģ�幹�캯����ģ�帳ֵ�����������ȡ��Ԥ����Ĺ��캯����ֵ�����
// �����������ֵʱ��ģ�庯�������ᱻ����

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

// 1# ƥ������ 2#����Ϊ2#��Ҫת��Ϊconst�����ӷ� const�汾��������
// ����������Ҫ���ǵ����ݵĲ�����Person���ܹ�ת��ΪPerson�ı��ʽʱ������ģ���Ա����(enable_if<>)
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
* �Ӻ���ģ�����ɵĺ�����Զ������һ����ͨ��������ʹӵ�е����ͺ�����
* �Ӻ���ģ�����ɵĺ�����Զ������дһ�����⺯��
* �ӹ��캯��ģ�����ɵĹ��캯����Զ���ܳ�Ϊһ���������ƶ����캯��
* �Ӹ�ֵ����ģ�����ɵĸ�ֵ����Ҳ��Զ���ܳ�Ϊһ���������ƶ���ֵ����
*/

/**
 * ����ģ�幹�캯�����ܳ�Ϊ�������캯������˼�ʹ�е�ģ�������������const T&�ĺ������壬
 ��������Ȼ����ʽ�����������캯����ģ�幹�캯�������������캯��(�����������캯��)һ����뵽���ؽ�����
 ���ģ�幹�캯���������Ĺ��캯����ƥ�䣬��ô������������Զ�����и�ֵ��
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