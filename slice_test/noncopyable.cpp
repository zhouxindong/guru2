#include "stdafx.h"

#include <string>
#include <iostream>
//
//#include "slice/noncopyable.h"

class C1 {
public:
	C1(int i1 = 0, double d1 = 0) : i(i1), d(d1) {}
	int i;
	double d;
};

class C2 : public C1 {
public:
	C2(int i1 = 0, double d1 = 0, std::string s1 = "") :
		C1(i1, d1), s(std::move(s1)) {}
	C1 c1;
	std::string s;
};

int main()
{
	C2 c(3, 5.3, "hello");
	std::cout << c.i << "\n";
	std::cout << c.d << "\n";
	std::cout << c.s << "\n";

	//C2 cc(c);
	//std::cout << cc.i << "\n";
	//std::cout << cc.d << "\n";
	//std::cout << cc.s << "\n";

	//guru2::NonCopyable<C2> cc(c);
	//std::cout << cc.i << "\n";
	//std::cout << cc.d << "\n";
	//std::cout << cc.s << "\n";

	guru2::NonCopyable<C2> c2(3, 5.3, "hello");
	std::cout << c.i << "\n";
	std::cout << c.d << "\n";
	std::cout << c.s << "\n";

	//guru2::NonCopyable<C2> cc(c2);
	//std::cout << cc.i << "\n";
	//std::cout << cc.d << "\n";
	//std::cout << cc.s << "\n";


	system("pause");
	return 0;
}