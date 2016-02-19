#include<iostream>
#include "streamSource.h"


int main(int argc,char* argv[])
{

	if(argc!=4){
		std::cout<<"\nNot enough arguments"<<endl;
		return 0;
	}
	std::string oldString = argv[1];
	std::string newString = argv[2];
	const char* fileName = argv[3];
	streamSource ss(oldString,newString,fileName);
	unsigned int matchCount = 0;
	char ch;

	while (!ss.get(ch).eof()) {
//		cout << "ch: " << ch << endl;
		if (!ss.currently_replacing() && ch == oldString[matchCount])
		{
			++matchCount;
			if (matchCount < oldString.size())
				continue;
		}

		if (matchCount == oldString.size()) {
			ss.matchSearchString();
			matchCount = 0;
		}
		else if (matchCount>0) {	//If found partial match.
			ss.foundPartialMatch(matchCount,ch);
			matchCount = 0;
		}
		else
			ss.put(ch);
	}

return 0;

}
