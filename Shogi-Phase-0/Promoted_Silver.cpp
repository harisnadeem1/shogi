#include "Promoted_Silver.h"
#include<iostream>
using namespace std;

Promoted_Silver::Promoted_Silver(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void Promoted_Silver::draw()
{
	cout << ((C == Black) ? "PS" : "ps");
}

char Promoted_Silver::getchar()
{
	return ((C == Black) ? 'PS' : 'ps');
}

bool Promoted_Silver::IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
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