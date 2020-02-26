#pragma once

//  Winmm.lib
//  void (UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)

#ifndef _GURU2_CORE_MMTIMER_H_
#define _GURU2_CORE_MMTIMER_H_

#include "../gvals2.h"
#include "Windows.h"
#include <cassert>

#pragma comment(lib, "Winmm.lib")

_GURU2_BEGIN

/**
 * @brief multi media timer
 */
class mmTimer
{
public:
	mmTimer() noexcept : timer_id_{ NULL }, accuracy_{ 0 } {}
	~mmTimer() noexcept
	{
		Stop();
	}

public:
	bool Start(int period_ms, LPTIMECALLBACK callback, void* param, bool periodic)
	{
		assert(period_ms > 0);
		TIMECAPS caps;
		if (timeGetDevCaps(&caps, sizeof(TIMECAPS)) != TIMERR_NOERROR)
		{
			return false;
		}

		accuracy_ = min(max(caps.wPeriodMin, 1), caps.wPeriodMax);
		timeBeginPeriod(accuracy_);
		timer_id_ = timeSetEvent(
			period_ms, 
			accuracy_, 
			callback, 
			(DWORD_PTR)param,
			periodic ? TIME_PERIODIC : TIME_ONESHOT);
		return (timer_id_ != NULL);
	}

	void Stop()
	{
		if (timer_id_ == NULL) return;
		timeKillEvent(timer_id_);
		timeEndPeriod(accuracy_);
		accuracy_ = 0;
		timer_id_ = NULL;
	}

private:
	UINT timer_id_;
	UINT accuracy_;
};

_GURU2_END

#endif // _GURU2_CORE_MMTIMER_H_