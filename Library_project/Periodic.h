#ifndef PERIODIC_H
#define PERIODIC_H

#include<string>
#include "Media.h"

using namespace std;

class Periodic : public Media
{
	public:
		Periodic(const string& call_no,const string& title,const string& subjects,const string& author,const string& description,const string& publisher,const string& publishing_history,const string& series,const string& notes,const string& related_titles,const string& other_forms_of_title,const string& gov_doc_number);

		~Periodic();

		bool compare_other(const string& other_string) const;
		void display() const;

	private:
		string author;
		string description;
		string publisher;
		string publishing_history;
		string series;
		string related_titles;
		string other_forms_of_title;
		string gov_doc_number;

};

#endif
