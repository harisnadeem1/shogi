#include "Promoted_Bishop.h"
#include<iostream>
using namespace std;

Promoted_Bishop::Promoted_Bishop(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void Promoted_Bishop::draw()
{
	cout << ((C == Black) ? "PB" : "pb");
}

char Promoted_Bishop::getchar()
{
	return ((C == Black) ? 'PB' : 'pb');
}

bool Promoted_Bishop:: IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
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
	int deltar = dri - sri;
	int deltac = dci - sci;
	if (((deltar >= -1) && (deltar <= 1)) && ((deltac >= -1) && (deltac <= 1)))
	{
		return true;
	}
	return false;


}