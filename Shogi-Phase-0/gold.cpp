#include "gold.h"
#include<iostream>
using namespace std;
gold::gold(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void gold::draw()
{
	cout  << ((C == Black) ? 'G' : 'g');
}
char gold::getchar()
{
	return ((C == Black) ? 'G' : 'g');
}

bool gold:: IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
{
	if (b->getpiece(sri, sci)->getcolor() == White) {
		if (dri + 1 == sri && sci == dci)
			return true;
		else if ((dci - 1 == sci || dci + 1 == sci) && sri == dri)
			return true;
		else if (dri - 1 == sri && sci == dci)
			return true;
		if (sci == dci + 1 || sci == dci - 1)
		{
			if (sri == dri + 1)
				return true;
		}
	}
	else if (b->getpiece(sri, sci)->getcolor() == Black) {
		if (dri - 1 == sri && sci == dci)
			return true;
		else if ((dci - 1 == sci || dci + 1 == sci) && sri == dri)
			return true;
		else if (dri + 1 == sri && sci == dci)
			return true;
		if (sci == dci + 1 || sci == dci - 1)
		{
			if (sri == dri - 1)
				return true;
		}
	}


	return false;
}