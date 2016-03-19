#include "BufferedFile.h"

//*Constructor to open a file and initialize variables.
BufferedFile::BufferedFile(const char* file)
{	
	myfile.open(file, ios::in | ios::out);
	fileName = file;
	getPos = 0;
	putPos = 0;
	pubflag = false;
	gflag = false;
	flag = false;
}

//*Destructor which calls truncate to set number of characters 
//equal to trunCount.
BufferedFile::~BufferedFile()
{
	trunCount = putPos;

	if (gflag == true){
		truncate(fileName,trunCount);
	}
	else{
		truncate(fileName,trunCount-1);
	}
		
	myfile.close();
}


BufferedFile& BufferedFile::get(char& ch)
{
	if (myBuffer.empty()) {
		myfile.seekg(getPos);
		ch = myfile.get();
		getPos = myfile.tellg();
		//getPos += 1;
		
	}
	else {
			pubflag = false;
			ch = myBuffer.front();
			myBuffer.pop_front();
			prevChar = ch;
	}
	
	return *this;
}

//*put() calls the fstream put to put a character on to
//the file.
ostream& BufferedFile::put(char ch)
{
	
	if (getPos == putPos) {
		gflag = true;
		char tempCh;
		if (!myBuffer.empty()) {
			flag = true;
			doOver(ch);
			get(tempCh);
			if(getPos!=-1)
				ch = tempCh;
		}
		else
			get(tempCh);
	
			if (getPos != -1 && flag == false)
			{
					myBuffer.push_back(tempCh);
			}
			flag = false;
	
	}
	if (getPos == -1) {
		myfile.clear();
		myfile.seekp(putPos);
		myfile.put(ch);
		putPos += 1;
		pubflag=true;
	}
	if (getPos == putPos) {
		doOver(ch);
		myfile.seekg(getPos);
		ch = myfile.get();
		getPos = myfile.tellg();
		if (getPos != -1) {
			myBuffer.push_back(ch);
			ch = myBuffer.front();
			myBuffer.pop_front();
		}
	}

	if (getPos != -1) {
		myfile.seekp(putPos);
		myfile.put(ch);
		putPos = myfile.tellp();
	}
	
	return *this;	//return object reference
}

//*doOver: push partialy matched character to deque
void BufferedFile::doOver(char ch)
{
	myBuffer.push_front(ch);
}

//*eof() file function does not returns true unless deque
//is empty
bool BufferedFile::eof() {
	if (getPos == -1 && myBuffer.empty() && pubflag==true)
	{
		return true;
	}
	else
		return false;

}
