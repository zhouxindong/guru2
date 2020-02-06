#pragma once
#include <utility>

/**
 * 返回值类型特征提供了一种方法来精确定义特定操作符的返回类型
 */

template <typename T1, typename T2>
struct PlusResult {
	using Type = decltype(std::declval<T1>() + std::declval<T2>());
};
