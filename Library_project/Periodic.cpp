#include "Periodic.h"


Periodic::Periodic(const string& call_no,const string& title,const string& subjects,const string& author,const string& description,const string& publisher,const string& publishing_history,const string& series,const string& notes,const string& related_titles,const string& other_forms_of_title,const string& gov_doc_number):Media(call_no,title,subjects,notes),author(author), description(description), publisher(publisher),publishing_history(publishing_history),series(series),related_titles(related_titles),other_forms_of_title(other_forms_of_title),gov_doc_number(gov_doc_number)
{
}

Periodic::~Periodic(){}


/*
   compare_other finds if the input string exists in Description,Notes, series
   and related_titles. It returns boolean value.
 */
bool Periodic::compare_other(const string& other_string) const{

	if(description.find(other_string)!=string::npos){
		return true;
	}
	else if(series.find(other_string)!=string::npos){
		return true;
	}
	else if(Media::compare_other(other_string)){
		return true;
	}
	else if(related_titles.find(other_string)!=string::npos){
		return true;
	}
	else{
		return false;
	}
}

/*
   display function to print Periodics attributes. This function gives
   call to display() of Media class.
 */
void Periodic::display() const
{
	cout << "------Periodic------" << endl;
	Media::display();
	cout<<"Author:      	     "<<author<<endl;
	cout<<"Description:        "<<description<<endl;
	cout<<"Publisher:          "<<publisher<<endl;
	cout<<"publishing_history: "<<publishing_history<<endl;
	cout<<"Series: 	     "<<series<<endl;
	cout<<"related_titles:     "<<related_titles;
	cout<<"other_forms_of_title: "<<other_forms_of_title<<endl;
	cout<<"gov_doc_number:     "<<gov_doc_number<<endl<<endl;

}
