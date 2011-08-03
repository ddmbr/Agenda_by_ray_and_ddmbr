// =====================================================================================
// 
//       Filename:  xmleditor.h
// 
//    Description:  TODO
// 
//        Version:  1.0
//        Created:  08/02/2011 10:53:55 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  ddmbr (), iddmbr@gmail.com
//        Company:  
// 
// =====================================================================================
#include <fstream>
#include <string>
#include <QtXml>
#include <QString>
using namespace std;
class XMLeditor
{
public:
	static QDomElement* AddNode(QDomDocument* doc, string title);
	static int AddAttribute(QDomElement* Target, QString TagName, QString value);
	static int createXML(QDomDocument* doc, QString* XMLstring);
	static int saveToFile(string dir, QDomDocument* doc);
	static int LoadFile(string dir, QDomDocument* doc);
private:
	static string toString(QDomDocument *doc);
};
