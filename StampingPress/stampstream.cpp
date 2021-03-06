
#include "stampstream.h"


/*
stampstream(int,int): An initialization list which allocates memory
to the stampbuf
*/
stampstream::stampstream(int col,int row) : ostream(new stampbuf(col,row))
{
}

//* Free memory allocated to stream buffer object.
stampstream::~stampstream()
{
	delete rdbuf();    
}


/*
Overide endrow to implements a new line character.
*/
ostream& endrow (ostream& os)
{
	stampbuf* myBuffer = dynamic_cast<stampbuf*> (os.rdbuf());
	os.flush();          //Flush out stream buffer.
	myBuffer->sync();
	myBuffer->initializeColumn();
	myBuffer->incrementRow();
	return os;
}

/*
Override << operator.
rdbuf(): It returns a pointer to a stream buffer object associated with that stream
*/
ostream& operator<<(ostream& os,const row& rowCount)
{
	stampbuf* myBuffer = dynamic_cast<stampbuf*> (os.rdbuf());
	os.flush();
	myBuffer->sync();
	myBuffer->setRow(rowCount.getRow());
	myBuffer->initializeColumn();

	return os;
}







