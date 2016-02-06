#ifndef VIDEO_H
#define VIDEO_H

#include<string>
#include "Media.h"

using namespace std;

class Video : public Media
{
	public:
		Video(const string& call_no,const string& title,const string& subjects,const string& description,const string& distributor,const string& notes,const 			string& series,const string& label);
		~Video();

		bool compare_other(const string& other_string) const;
		void display() const;	

	private:

		string description;
		string distributor;
		string series;
		string label;

};

#endif
