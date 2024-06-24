#include "King.h"
#include<iostream>
using namespace std;
King::King(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void King::draw()
{
	cout  << ((C == Black) ? 'K' : 'k');
}

char King::getchar()
{
	return ((C == Black) ? 'K' : 'k');
}

bool King::IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
{
	int deltar = dri - sri;
	int deltac = dci - sci;
	if (((deltar >= -1) && (deltar <= 1)) && ((deltac >= -1) && (deltac <= 1)))
	{
		return true;
	}
	return false;
}