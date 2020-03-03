#pragma once

class X {
public:
	X() {}
private:
	struct XImpl;
	XImpl* pimpl_;
};

struct X::XImpl
{
	// 放置所有私有成员
};

#include <vcruntime_new.h>

class Y
{
	static const size_t sizeofx = sizeof(X);
	char x_[sizeofx];

public:
	Y() {
		new (&x_[0]) X;
	}

	~Y() {
		(reinterpret_cast<X*>(&x_[0]))->~X();
	}
};