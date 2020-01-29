#pragma once
template <char const* name>
class MyClass
{
};

// MyClass<"hello"> x; // error!

extern char const s03[] = "hi"; // external linkage
char const s11[] = "hi";		// internal linkage

MyClass<s03> m03;
MyClass<s11> m11;

void foo()
{
	static char const s17[] = "hi"; 	// no linkage
	// MyClass<s17> m17; // C++17
}
