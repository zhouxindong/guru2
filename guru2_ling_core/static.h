#pragma once

struct BigInt
{
private:
	long long _count;

public:
	BigInt(long long count) : _count{ count } {}
};

class B
{
	static int const zero = 0;
	static constexpr float zero2 = 0.0f;
	//inline static BigInt const zero3 = BigInt{ 0 };	// C++17

	static constexpr double zero4()
	{
		return 0.0;
	}

	static BigInt zero5() {
		return BigInt{ 0 };
	}
};