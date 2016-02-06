#include "Film.h"

Film::Film(const string& call_no,const string& title,const string& subjects,const string& director,const string& notes,const string& year):Media(call_no,title,subjects,notes),director(director),year(year)
{
}


Film::~Film(){}

/*
   compare_other finds if the input string exists in Notes, Director
   and year. It returns boolean value.
 */

bool Film::compare_other(const string& other_string) const{

	if(director.find(other_string)!=string::npos){
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
   display function to print Film attributes. This function gives
   call to display() of Media class.
 */
void Film::display() const
{
	cout << "------Film------" << endl;

	Media::display();  
	cout<<"Director: "<<director<<endl;
	cout<<"Year:     "<<year<<endl<<endl;


}

