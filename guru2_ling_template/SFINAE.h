#pragma once

// SFINAE用于函数模板的不同实现选择
/**
 * 利用decltype指定模板参数的约束
 * 在decltype的开始处定义所有约束(转换为void防止逗号运算符重载)
 * 最后定义一个对象用于真实的返回类型
 */
template <typename T>
auto len(T const& t) -> decltype((void)(t.size()), T::size_type())
{
	return t.size();
}

/**
 * 四种基于编译期条件启动或禁用特定语句的技术
 * 1. 局部物化
 * 2. SFINAE
 * 3. std::enable_if
 * 4. if constexpr(...)
 */