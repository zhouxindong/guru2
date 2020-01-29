#pragma once
#include <string>

template <typename... Mixins>
class Point : public Mixins...{
	double x, y, z;
public:
	Point() : Mixins()...
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