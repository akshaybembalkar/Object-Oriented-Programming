#ifndef FILM_H
#define FILM_H

#include<string>
#include "Media.h"

using namespace std;

class Film : public Media
{
	public:
		Film(const string& call_no,const string& title,const string& subjects,const string& director,const string& notes,const string& year);
		~Film();

		bool compare_other(const string& other_string) const;
		void display() const;	

	private:
		string director;
		string year;

};

#endif
