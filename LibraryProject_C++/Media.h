#ifndef MEDIA_H
#define MEDIA_H

#include<iostream>
#include<string>


using namespace std;

class Media
{
	public:
		Media(const string& call_no,const string& title,const string& subject,const string& notes);
		virtual ~Media();

		bool compare_Callno(const string& call_no) const;
		bool compare_Title(const string& title) const;
		bool compare_Subject(const string& subject) const;

		virtual bool compare_other(const string& other) const;
		virtual void display() const;

	private:
		string CallNo;
		string Title;
		string Subject;
		string Notes;


};



#endif
