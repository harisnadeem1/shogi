#include "Knight.h"
#include<iostream>
using namespace std;
Knight::Knight(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void Knight::draw()
{
	cout << ((C == Black) ? 'N' : 'n');
}


char Knight::getchar()
{
	return ((C == Black) ? 'N' : 'n');
}

bool Knight::IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
{

	if (b->getpiece(sri, sci)->getcolor() == White) {
		if ((sci == dci + 1) || (sci == dci - 1))
		{
			if (sri == dri + 2)
				return true;
		}
	}
	else if (b->getpiece(sri, sci)->getcolor() == Black) {
		if ((sci == dci + 1) || (sci == dci - 1))
		{
			if (sri == dri - 2)
				return true;
		}
	}

	return false;
}