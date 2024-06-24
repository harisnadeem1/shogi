#include "silver.h"
#include<iostream>
using namespace std;

silver::silver(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void silver::draw()
{
	cout  << ((C == Black) ? 'S' : 's');
}


char silver::getchar()
{
	return ((C == Black) ? 'S' : 's');
}

bool silver::IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
{
	if (b->getpiece(sri, sci)->getcolor() == White) {


		if (dri + 1 == sri && sci == dci)////up
			return true;
		else if (sci == dci + 1 || sci == dci - 1)    ///digonal
		{
			if (sri == dri + 1)
				return true;
			if (sri == dri - 1)
				return true;
		}

	}
	else if (b->getpiece(sri, sci)->getcolor() == Black) {
		if (dri - 1 == sri && sci == dci)
			return true;
		if (sci == dci + 1 || sci == dci - 1)
		{
			if (sri == dri + 1)
				return true;
			if (sri == dri - 1)
				return true;
		}
	}
	return false;
}