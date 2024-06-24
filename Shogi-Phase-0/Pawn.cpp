#include "Pawn.h"
#include<iostream>
using namespace std;

Pawn::Pawn(int r, int c, Colour _c,Board*B):Piece(r,c,_c,B)
{
	
}

void Pawn::draw()
{
	cout << ((C == Black) ? 'P' : 'p');
	
}

char Pawn::getchar()
{
	return ((C == Black) ? 'P' : 'p');
}

bool Pawn:: IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
{

	if (b->getpiece(dri, dci) == nullptr)
	{

		if (sci == dci)
		{
			if (b->getpiece(sri, sci)->getcolor() == White)
			{

				if (dri == sri - 1)
				{
					return true;
				}
			}
			else if (b->getpiece(sri, sci)->getcolor() == Black)
			{

				if (dri == sri + 1)
				{
					return true;
				}


			}
		}
	}
	else if (b->getpiece(dri, dci) != nullptr)
	{
		if (sci == dci) {

			if ((sri == dri + 1) || (sri == dri - 1))
			{
				if (b->getpiece(dri, dci)->getcolor() == White)
				{
					if (dri == sri + 1)
					{
						return true;
					}

				}
				else if (dri == sri - 1)
				{


					return true;

				}

			}
		}
	}

	return false;
}