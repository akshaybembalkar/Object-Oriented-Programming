
#include "stampbuf.h" 
#include "stamp.h"
#include "row.h"

/*
Allocate a size to a buffer.
*/
stampbuf::stampbuf(int col,int row) : max_col(col),current_row(row),buffer(new char[col/2])
{ 
	current_row = 0;
	current_col = 0;
	setp(buffer, buffer+col/2); //Set output sequence pointers.
	stamping_press::insert_plate(col,row);
}

stampbuf::~stampbuf()
{
	sync();    
	delete[]buffer;		//Free allocated buffer.
	stamping_press::eject_plate();
}

void stampbuf::incrementRow()
{
	current_row = current_row + 1;
}

//* Set the current row to be printed.
void stampbuf::setRow(int rowNo)
{
	current_row = rowNo;
}


void stampbuf::initializeColumn()
{
	current_col = 0;
}

/*
Override sync() which synchronizes contents of buffer with associated
character sequence.
//Called by pubsync.
*/
int stampbuf::sync()
{

	for(char* i = pbase();i!=pptr();++i){
		try{	
			stamping_press::set_die(*i);
		}
		catch(...){
			if(*i==stamping_press::get_die())
			{

			}
			else{
				current_col++;
				continue;
			}
		}
		try{
			stamping_press::stamp(current_col,current_row);
		}
		catch(...)
		{
			continue;
		}
		current_col++;
	}

	setp(buffer, buffer+max_col/2);

	return 0;
}

/*
overflow() called on buffer overflow.
*/
int stampbuf::overflow(int ch)
{

	for(char* i = pbase();i!=pptr();++i){
		try{	
			stamping_press::set_die(*i);
		}
		catch(...){
			if(*i==stamping_press::get_die())
			{

			}
			else{
				current_col++;
				continue;
			}
		}
		try{
			stamping_press::stamp(current_col,current_row);
		}
		catch(...)
		{
		}
		current_col++;
	}

	setp(buffer, buffer+max_col/2);
	sputc(ch);           //Store character at current put position and increase pointer
	return ch;
}
