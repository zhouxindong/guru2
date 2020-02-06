#pragma once
template <unsigned N, unsigned D = 1>
struct Ratio {
	static constexpr unsigned num = N;
	static constexpr unsigned den = D;
	using Type = Ratio<num, den>;
};

template <typename R1, typename R2>
struct RatioAdd {
private:
	static constexpr unsigned den = R1::den * R2::den;
	static constexpr unsigned num = R1::num * R2::den + R2::num * R1::den;

public:
	typedef Ratio<num, den> Type;
};

/**
 * Duration
 */
template <typename T, typename U = Ratio<1>>
class Duration {
public:
	using ValueType = T;
	using UnitType = typename U::Type;

private:
	ValueType val;

public:
	constexpr Duration(ValueType v = 0) : val(v) {}

	constexpr ValueType value() const {
		return val;
	}
};

template <typename T1, typename U1, typename T2, typename U2>
auto constexpr operator + (Duration<T1, U1> const& lhs, Duration<T2, U2> const& rhs)
{
	using VT = Ratio<1, RatioAdd<U1, U2>::den>;
	auto val = lhs.value() * VT::den / U1::den * U1::num +
		rhs.value() * VT::den / U2::den * U2::num;

	return Duration<decltype(val), VT>(val);
}