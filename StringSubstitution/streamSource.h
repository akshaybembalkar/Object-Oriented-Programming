/***
Author: Akshay Bembalkar
****/

#ifndef STREAMSOURCE_H
#define STREAMSOURCE_H


#include <iostream>
#include <string>
#include "BufferedFile.h"
class streamSource
{
public:
	streamSource(std::string oldString, std::string newString, const char* fileName);
	~streamSource();

	streamSource& get(char& ch);
	void put(char& ch);
	void matchSearchString();
	void foundPartialMatch(int matchCount,char ch);
	bool currently_replacing();
	bool eof();


private:

	int replacementCount;
	int searchCount;
	int searchOrigin;
	int stringLength;
	bool search_get;
	bool replacement_get;

	std::string oldString;
	std::string newString;
	BufferedFile obj;
//	std::string fileName;
};

#endif
