// =====================================================================================
// 
//       Filename:  meetingmgr.h
// 
//    Description:  TODO
// 
//        Version:  1.0
//        Created:  08/01/2011 11:26:16 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  ddmbr (), iddmbr@gmail.com
//        Company:  SYSU
// 
// =====================================================================================
#ifndef MEETINGMGR_H
#define MEETINGMGR_H

#include <string>
#include <QString>
#include "meeting.h"
#include "mtime.h"
#include <fstream>
#include "encryptor"
#include "xmleditor.h"

using namespace std;

class MeetingMgr
{
public:
	//Constructor
	MeetingMgr();
	//Deconstructor
	~MeetingMgr();
	//Add a meetinf
	int Add(string title, Time Start, Time End, string guest);
	//query the meeting in given time interval
	string Query(Time Start, Time End);
	//delete a meeting
	int Delete(string title);
	//clear all meetings
	int Clear();
private:
	Meeting* GetMeeting(string title);
	QDomDocument* doc;
	string XMLstring;
	fstream filestr;

	//scope?temp instance?TODO
	string DBdir;
};

#endif
