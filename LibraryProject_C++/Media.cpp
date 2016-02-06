#include "Media.h"


Media::Media(const string& call_no,const string& title,const string& subject,const string& notes):CallNo(call_no),Title(title),Subject(subject),Notes(notes){
	
}

Media::~Media(){}


/*
   compare_Callno returns true if call number is found.
Input: Constant String reference
Output:boolean value
 */
bool Media::compare_Callno(const string& call_no) const{

	if(CallNo.find(call_no)!=string::npos){  //string find returns npos if nothing is found
		return true;
	}
	else{
		return false;
	}
	return 1;
}

/*
   compare_Title returns true if requested title is found.
Input: Constant String reference
Output:boolean value
 */

bool Media::compare_Title(const string& title) const{

	if(Title.find(title)!=string::npos){
		return true;
	}
	else{
		return false;
	}
}

/*
   compare_Subject returns true if requested subject is found.
Input: Constant String reference
Output:boolean value
 */

bool Media::compare_Subject(const string& subject) const{

	if(Subject.find(subject)!=string::npos){
		return true;
	}
	else{
		return false;
	}
}

/*
   compare_other returns true if any random string passed to it is found.
Input: Constant String reference
Output:boolean value
 */

bool Media::compare_other(const string& other) const{

	if(Notes.find(other)!=string::npos){
		return true;
	}
	else{
		return false;
	}
}

/*
   display function prints only the four common fields for book, periodics, video and film.
 */
void Media::display() const{

	cout<<"Call Number: "<<CallNo<<endl;
	cout<<"Title:       "<<Title<<endl;
	cout<<"Subject:     "<<Subject<<endl;
	cout<<"Notes:       "<<Notes<<endl;   
}
