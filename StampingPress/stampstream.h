/*
stampstream class which inherits public ostream class. We override <<
operator and implement endrow as a new line character.
*/


#include<iostream>
#include "stampbuf.h"
#include "stamp.h"
#include "row.h"

using namespace std;

/*Inherit stampstream class from public ostream class*/

class stampstream : public std::ostream{

	public:
		stampstream(int row,int col);
		~stampstream();

};

ostream& operator<<(ostream& os,const row& rowCount);
ostream& endrow (ostream& os);
