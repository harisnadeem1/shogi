#include "Promoted_Rook.h"
#include<iostream>
using namespace std;

Promoted_Rook::Promoted_Rook(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void Promoted_Rook::draw()
{
	cout << ((C == Black) ? "PR" : "pr");
}

char Promoted_Rook::getchar()
{
	return ((C == Black) ? 'PR' : 'pr');
}
bool Promoted_Rook::IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
{

	if (sri == dri)
	{
		int cc = (dci - sci > 0) ? 1 : -1;
		for (int ci = cc + sci; ci != dci; ci = ci + cc)
		{
			if (b->getpiece(sri, ci) != nullptr)
				return false;
		}
		return true;
	}
	else if (sci == dci)
	{
		int rc = (dri - sri > 0) ? 1 : -1;
		for (int ri = rc + sri; ri != dri; ri = ri + rc)
		{
			if (b->getpiece(ri, sci) != nullptr)
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