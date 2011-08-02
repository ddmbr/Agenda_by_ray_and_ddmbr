// =====================================================================================
// 
//       Filename:  xmleditor.cpp
// 
//    Description:  TODO
// 
//        Version:  1.0
//        Created:  08/02/2011 10:59:43 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  ddmbr, iddmbr@gmail.com
//        Website:  http:\\ddmbr.tk
//         School:  Sun-Yat-Sen University
// 
// =====================================================================================

#include "xmleditor.h"

int XMLeditor::createXML(QDomDocument* doc, QString* XMLstring)
{
	if(*XMLstring == "")
	{
		//create a new one
		QDomElement* root = &(doc->createElement("MeetingContainer"));
		doc->appendChild(*root);
	}
	else
		doc->setContent(*XMLstring);
}
QDomElement* XMLeditor::AddNode(QDomDocument* doc)
{
	QDomElement newMeeting = doc->createElement("Meeting");
	doc->appendChild(newMeeting);
	return &newMeeting;
}
int XMLeditor::AddAttribute(QDomElement* Target, QString TagName, QString value)
{
	QDomDocument* doc = &(Target->ownerDocument());
	QDomElement newNode = doc->createElement(TagName);
	QDomText TextVal = doc->createTextNode(value);
	newNode.appendChild(TextVal);
	Target->appendChild(newNode);
}
int XMLeditor::saveToFile(fstream* filestr, QDomDocument* doc)
{
	(*filestr)<<toString(doc);
}
string XMLeditor::toString(QDomDocument *doc)
{
        QString XMLstring;
        QTextStream text(&XMLstring);
        doc->save(text, 4);
        return XMLstring.toStdString();
}
int XMLeditor::LoadFile(string dir, fstream* filestr, QDomDocument* doc)
{
	(*filestr).open(dir.c_str(), fstream::in | fstream::out | fstream::app);
}
