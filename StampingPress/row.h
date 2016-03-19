/*
row class returns the current row to be printed on
the stamping press.
*/

#ifndef ROW
#define ROW

class row
{
	public:
		row();             //*Constructor.
		row(int count);

		int getRow() const;  //*Get current row to be printed.

	private:
		int maxRow;

};

#endif
