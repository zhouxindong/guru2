#pragma once
#include <string>

template <typename... Mixins>
class Point : public Mixins...{
	double x, y, z;
public:
	Point() : Mixins()..., x(0.0), y(0.0), z(0.0)
	{
	}

	Point(double x, double y, double z) : Mixins()..., x(x), y(y), z(z)
	{
	}

	template <typename Visitor>
	void visitMixins(Visitor visitor)
	{
		visitor(static_cast<Mixins&>(*this)...);	// call argument pack expansion
	}
};

struct Color { char red, green, blue; };
struct Label { std::string name; };

Point<Color, Label> p;

/**
 * Parameterized Virtually
 */
class NotVirtual {

};

class Virtual {
public:
	virtual void foo() {}
};

template <typename... Mixins>
class Base : public Mixins...{
public:
	void foo() {
	}
};

template <typename... Mixins>
class Derived : public Base<Mixins...> {
public:
	void foo() {
	}
};

void foo2() {
	Base<NotVirtual>* p1 = new Derived<NotVirtual>;
	p1->foo();

	Base<Virtual>* p2 = new Derived<Virtual>;
	p2->foo();
}