/***************************************************************
	Akshay S. Bembalkar

Here we create object of stampstream class. We assign maximum 
row and column to be printed on a plate. 
***************************************************************/
#include <iostream>
#include "stampstream.h"
#include "stampbuf.h"
#include "row.h"
#include "stamp.h"


int main()
{
	stampstream s(30,10);
	s << "hi th#re planetoid humans" << endrow
		<< " how's all the fish" << row(5) << "one more";
	s << row(4) << " two more" << 3.1415;
	s << row(8) << "The quick brown fox jumped over the lazzy dog's back. ";
	s << row(3) << "the end";

	return 0;
}


