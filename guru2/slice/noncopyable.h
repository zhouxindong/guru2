#pragma once
#ifndef _GURU2_SLICE_NONCOPYABLE_H_
#define _GURU2_SLICE_NONCOPYABLE_H_

#include "../gvals2.h"
#include <type_traits>

_GURU2_BEGIN

/**
 * @brief base chain wrapped the class can't be copy construct or assignment
 * @usage NonCopyable<class>
 */
template <typename _Base>
struct NonCopyable : public _Base
{
	explicit NonCopyable() = default;

	template <typename... _Args,
			  typename = std::enable_if_t<sizeof...(_Args) != 1>>
	explicit NonCopyable(_Args&&... args)
		: _Base(std::forward<_Args>(args)...) {}

	template <typename Arg,
			  typename = std::enable_if_t<
						 !std::is_same_v<NonCopyable, std::decay_t<Arg>>>>
		explicit NonCopyable(Arg&& arg)
		: _Base(std::forward<Arg>(arg)) {}

	NonCopyable(NonCopyable const&) = delete;
	NonCopyable& operator = (NonCopyable const&) = delete;

	NonCopyable(NonCopyable&&) = default;
	NonCopyable& operator = (NonCopyable&&) = default;
};

_GURU2_END

#endif // _GURU2_SLICE_NONCOPYABLE_H_