#ifndef BOOK_H
#define BOOK_H

#include<string>
#include "Media.h"

using namespace std;

class Book : public Media 
{
	public:
		Book(const string& call_no,const string& title,const string& subjects,const string& author,const string& description,const string& publisher,const  			string& city,const string& year,const string& series,const string& notes);
		~Book();

		bool compare_other(const string& other_string) const;
		void display() const;	

	private:
		string author;
		string description;
		string publisher;
		string city;
		string year;
		string series;

};

#endif
