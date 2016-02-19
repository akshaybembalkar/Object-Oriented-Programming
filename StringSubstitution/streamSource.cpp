#include "streamSource.h"


//*streamSource() initialize our BufferFile object
streamSource::streamSource(std::string oldS, std::string newS, const char* fileN):oldString(oldS),newString(newS),obj(fileN)
{
	//obj(fileName);
	replacementCount = 0;
	searchCount = 0;
}

streamSource::~streamSource(){
}

//*
streamSource& streamSource::get(char& ch) {
	
	if (searchCount > 0) {
		ch = oldString[stringLength - searchCount--];
		obj.prevChar = ch;
		search_get = true;
	}
	else if (replacementCount > 0) {
		ch = newString[stringLength-replacementCount--];
		obj.prevChar = ch;
		replacement_get = true;
	}
	else {
		obj.get(ch);
		search_get = replacement_get = false;
	}
	
	return *this;      //return object reference
}

void streamSource::put(char& ch)
{
	obj.put(ch);
}

//*matchSearchString() is called if string match found
void streamSource::matchSearchString()
{
	replacementCount = stringLength = newString.size();
	
}

void streamSource::foundPartialMatch(int matchCount, char ch)
{
	if (search_get)//if true
	{
		++searchOrigin;
	}
	else
	{
		searchOrigin = 0;
		stringLength = matchCount;
		obj.doOver(ch);
	}
	put(oldString[searchOrigin]); //invoke StreamSource::put
	searchCount = stringLength - 1 - searchOrigin;

}

bool streamSource::currently_replacing()
{
	if (replacementCount > 0 || replacement_get == true) {
		return true;
	}
	else {
		return false;
	}
}


bool streamSource::eof() {
	if (searchCount!=0 || replacementCount!=0) {
		return false;
	}
	else
		return obj.eof();
}
