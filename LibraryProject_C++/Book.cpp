#include "Book.h"

Book::Book(const string& call_no,const string& title,const string& subjects,const string& author,const string& description,const string& publisher,const string& city,const string& year,const string& series,const string& notes):Media(call_no,title,subjects,notes),author(author), description(description), publisher(publisher)
,city(city), year(year), series(series)
{
}


Book::~Book(){}

/*
   compare_other finds if the input string exists in Description, Notes
   and year. It returns boolean value.
 */
bool Book::compare_other(const string& other_string) const{

	if(description.find(other_string)!=string::npos){
		return true;
	}
	else if(year.find(other_string)!=string::npos){
		return true;
	}
	else if(Media::compare_other(other_string)){
		return true;
	}
	else{
		return false;
	}
}

/*
   display function to print book attributes. This function gives
   call to display() of Media class.
 */
void Book::display() const
{
	cout << "------Book------" << endl;

	Media::display();  
	cout<<"Author:      "<<author<<endl;
	cout<<"Description: "<<description<<endl;
	cout<<"Publisher:   "<<publisher<<endl;
	cout<<"City:        "<<city<<endl;
	cout<<"Year:        "<<year<<endl;
	cout<<"Series:      "<<series<<endl<<endl;


}

