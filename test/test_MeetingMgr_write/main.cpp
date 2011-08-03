// =====================================================================================
// 
//       Filename:  main.cpp
// 
//    Description:  Test the MeetingMgr module
// 
//        Version:  1.0
//        Created:  08/03/2011 10:02:04 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  ddmbr, iddmbr@gmail.com
//        Website:  http:\\ddmbr.tk
//         School:  Sun-Yat-Sen University
// 
// =====================================================================================
#include "meetingmgr.h"
int main()
{
	MeetingMgr test;
	Time testTime;
	string guest = "testGuest";

	test.Add("testMeeting", testTime, testTime, guest);
}
