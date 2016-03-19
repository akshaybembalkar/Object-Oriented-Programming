
/*
stampbuf class which inherits public streambuf class. It overrides sync
and overflow methods from base class.
*/


#ifndef STAMPBUF
#define STAMPBUF

#include<iostream>

//* Inherit streambuf class to a stampbuf class publicly.

class stampbuf : public std::streambuf
{
	public:
		stampbuf(int col,int row);
		~stampbuf();

		void incrementRow();
		void setRow(int current_row);
		void initializeColumn();
		virtual int sync();
		virtual int overflow(int ch);



	private:
		int max_row;
		int max_col;
		int current_row;
		int current_col;
		char* buffer;

};

#endif
