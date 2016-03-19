/***
Author: Akshay Bembalkar
****/

#ifndef BUFFEREDFILE_H
#define BUFFEREDFILE_H

#include<iostream>
#include<fstream>
#include "deque.h"
#include<unistd.h>

using namespace std;

class BufferedFile : public fstream
{
public:
	BufferedFile(const char* file);
	~BufferedFile();

	BufferedFile& get(char& ch);
	ostream& put(char ch);
	char prevChar;
	void doOver(char ch);	//Push char to the front
	bool eof();
	

private:
	std::streampos getPos;
	std::streampos putPos;
	fstream myfile;
	TrackingDeque<char> myBuffer;	

	int trunCount;	
	bool gflag;	//If getPos==putPos, set to ture
	bool flag;
	bool pubflag;
	const char* fileName;

};

#endif
