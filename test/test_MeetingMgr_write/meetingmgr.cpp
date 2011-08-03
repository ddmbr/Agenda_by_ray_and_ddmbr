// =====================================================================================
// 
//       Filename:  meetingmgr.cpp
// 
//    Description:  TODO
// 
//        Version:  1.0
//        Created:  08/01/2011 03:13:04 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  ddmbr, iddmbr@gmail.com
//        Website:  http:\\ddmbr.tk
//         School:  Sun-Yat-Sen University
// 
// =====================================================================================

#include "meetingmgr.h"

//This function will initialize the meeting mgr
MeetingMgr::MeetingMgr()
{
	//initailize the DB directory
	DBdir = "meeting.db";

	//initialize the XML container
	doc = new QDomDocument;

	//load file and extract XML info
	XMLeditor::LoadFile(DBdir, doc);

	XMLeditor::saveToFile(DBdir, doc);
}
int MeetingMgr::Add(string title, Time Start, Time End, string guest)
{
	//
	QDomElement* newMeeting;
	newMeeting = XMLeditor::AddNode(doc, title);
	

	//need some method to process time
	//TODO All the fucking staff about time managing
	//TimeString = getTimeString()
	//THIS LINE IS FOR DEBUG
	QString TimeString = "test";


	XMLeditor::AddAttribute(newMeeting, QString("startTime"), TimeString);
	XMLeditor::AddAttribute(newMeeting, QString("endTime"), TimeString);
	XMLeditor::AddAttribute(newMeeting, QString("Guest"), QString::fromStdString(guest));

	XMLeditor::saveToFile(DBdir, doc);
}
string MeetingMgr::Query(Time Start, Time End)
{

}
int MeetingMgr::Delete(string title)
{

}
int MeetingMgr::Clear()
{

}
MeetingMgr::~MeetingMgr()
{
	filestr.close();
}

