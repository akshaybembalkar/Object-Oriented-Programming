
#include "Video.h"


Video::Video(const string& call_no,const string& title,const string& subjects,const string& description,const string& distributor,const string& notes,const string& series,const string& label):Media(call_no,title,subjects,notes), description(description),distributor(distributor),series(series),label(label)
{
}


Video::~Video(){}

/*
   compare_other finds if the input string exists in Description, Notes
   and Distributor. It returns boolean value.
 */
bool Video::compare_other(const string& other_string) const{

	if(description.find(other_string)!=string::npos){
		return true;
	}
	else if(Media::compare_other(other_string)){
		return true;
	}
	else if(distributor.find(other_string)!=string::npos){
		return true;
	}
	else{
		return false;
	}
}

/*
   display function to print Video attributes. This function gives
   call to display() of Media class.
 */
void Video::display() const
{
	cout << "------Video------" << endl;

	Media::display();  

	cout<<"Description: "<<description<<endl;
	cout<<"Distributor: "<<distributor<<endl;
	cout<<"Series:      "<<series<<endl;  
	cout<<"Label:       "<<label<<endl<<endl;
}

