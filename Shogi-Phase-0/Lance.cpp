#include "Lance.h"
#include<iostream>
using namespace std;
Lance::Lance(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void Lance::draw()
{
	cout  << ((C == Black) ? 'L' : 'l');
}

char Lance::getchar()
{
	return ((C == Black) ? 'L' : 'l');
}

bool Lance:: IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
{

	if (sci == dci)
	{

		if (b->getpiece(sri, sci)->getcolor() == White)
		{
			int rc = -1;
			for (int ri = rc + sri; ri != dri; ri = ri + rc)
			{
				if (b->getpiece(ri, sci) != nullptr)
					return false;
			}
			return true;
		}
		else if (b->getpiece(sri, sci)->getcolor() == Black)
		{
			int rc = 1;
			for (int ri = rc + sri; ri != dri; ri = ri + rc)
			{
				if (b->getpiece(ri, sci) != nullptr)
					return false;
			}
			return true;
		}
	}
	return false;
}