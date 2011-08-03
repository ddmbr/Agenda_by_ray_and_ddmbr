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
#include <iostream>
using namespace std;
int XMLeditor::createXML(QDomDocument* doc, QString* XMLstring)
{
	if(*XMLstring == "")
	{
		//create a new one
		QDomElement* root = new QDomElement(doc->createElement("MeetingContainer"));
		doc->appendChild(*root);
	}
	else
		doc->setContent(*XMLstring);
}
QDomElement* XMLeditor::AddNode(QDomDocument* doc, string title)
{
	QDomElement* newMeeting = new QDomElement(doc->createElement(QString::fromStdString(title)));
	doc->firstChild().appendChild(*newMeeting);
	return newMeeting;
}
int XMLeditor::AddAttribute(QDomElement* Target, QString TagName, QString value)
{
	QDomDocument* doc = &(Target->ownerDocument());
	QDomElement newNode = doc->createElement(TagName);
	QDomText TextVal = doc->createTextNode(value);
	newNode.appendChild(TextVal);
	Target->appendChild(newNode);
}
int XMLeditor::saveToFile(string dir, QDomDocument* doc)
{
	fstream filestr;
	filestr.open(dir.c_str(), fstream::out | fstream::trunc);
	filestr<<toString(doc);
	filestr.close();
}
string XMLeditor::toString(QDomDocument *doc)
{
        QString XMLstring;
        QTextStream text(&XMLstring);
        doc->save(text, 4);
        return XMLstring.toStdString();
}
int XMLeditor::LoadFile(string dir, QDomDocument* doc)
{
	fstream filestr;
	string XMLstring;

	filestr.open(dir.c_str(), ios_base::in);
	getline(filestr, XMLstring, char(-1));
	createXML(doc, &(QString::fromStdString(XMLstring)));
	filestr.close();
}
