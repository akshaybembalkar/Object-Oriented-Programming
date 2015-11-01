#include "row.h"

row::row()
{
}

row::row(int getRow)
{
	maxRow = getRow;
}

/*
Return the current row to be printed.
*/
int row::getRow() const
{
	return maxRow;
}
