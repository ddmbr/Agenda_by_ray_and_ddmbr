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
	//initailize the eof charactor
	eof = -1;

	//initialize the XML container
	doc = new QDomDocument;

	//load file and extract XML info
	filestr.open("./meeting.db", "fstream::in | fstream::out | fstream::app");
	try
	{
		if(!filestr)
			//TODO exception handling
			throw e;
		getline(filestr, XMLstring, eof);
		XMLeditor::createXML(doc, &XMLstring);
	}
}
int MeetingMgr::Add(string title, Time Start, Time End)
{
	//
	QDomElement* newMeeting;
	newMeeting = XMLeditor::AddNode(doc);

	//need some method to process time
	//TODO All the fucking staff about time managing
	//TimeString = getTimeString()
	
	XMLeditor::AddAttribute(mewMeeting, "time", TimeString);
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

