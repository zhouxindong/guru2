#pragma once
/**
 * RTTI可以部分实现动态类型: 为每个类型产生一个type_info类型的数据(typeid查询)
 type_info提供了name和hash_code，以供对变量的类型进行比较查询
 */

template <class _Base>
struct non_copyable : public _Base
{
	explicit non_copyable() = default;

	struct non_copyable_exception {};

	template <typename... _Args>
	explicit non_copyable(_Args&&... args)
		: _Base(std::forward<_Args>(args)...)
	{
		auto t = std::tuple<_Args&&...>(std::forward<_Args>(args)...);
		if (std::tuple_size<decltype(t)>::value != 1)
			return;

		if (typeid(std::tuple_element<0, decltype(t)>::type).hash_code() ==
			typeid(decltype(*this)).hash_code())
		{
			throw non_copyable_exception();
		}
	};

	non_copyable(const non_copyable&) = delete;
	non_copyable& operator = (const non_copyable&) = delete;
};
