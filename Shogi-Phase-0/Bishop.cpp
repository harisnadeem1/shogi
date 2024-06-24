#include "Bishop.h"
#include<iostream>
using namespace std;
Bishop::Bishop(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void Bishop::draw()
{
	cout  << ((C == Black) ? 'B' : 'b');
}
char Bishop::getchar()
{
	return((C == Black) ? 'B' : 'b');
}

bool Bishop:: IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
{
	if ((dci - sci == dri - sri) || (dci - sci == sri - dri))
	{
		int ri = (dri - sri > 0) ? 1 : -1;
		int ci = (dci - sci > 0) ? 1 : -1;
		int rc;
		int cc;
		for (rc = sri + ri, cc = sci + ci; rc != dri; rc = rc + ri, cc = cc + ci)
		{
			if (b->getpiece(rc, cc) != nullptr)
				return false;

		}
		return true;
	}
	return false;


}