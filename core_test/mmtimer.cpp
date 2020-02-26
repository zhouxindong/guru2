#include "stdafx.h"
#include <iostream>

#include "core/mmtimer.h"

using namespace guru2;

//void (CALLBACK TIMECALLBACK)(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)

void proc(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
	std::cout << "uTimerID: " << uTimerID << '\n';
	std::cout << "uMsg: " << uMsg << '\n';
	std::cout << "dwUser: " << dwUser << '\n';
	std::cout << "dw1: " << dw1 << '\n';
	std::cout << "dw2: " << dw2 << '\n';
}

class C {
};

//int main()
//{
//	mmTimer timer;
//	timer.Start(1, proc, &timer, true);
//
//	system("pause");
//	
//	return 0;
//}