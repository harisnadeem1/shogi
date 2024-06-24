#pragma once
#include"Header.h"
#include"Board.h"
#include"Piece.h"

class Pawn :public Piece
{
protected:
	bool IsLegalPlace(int sri, int sci, int dri, int dci,Board*b)//, Board*b)
	{
		//Piece* qpDest = Ps[]
		if (b->getpiece(dri,dci) == nullptr)
		{
			// Destination square is unoccupied
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
		else if(b->getpiece(dri, dci) != nullptr)
		{
			if (sci == dci) {
				// Dest holds piece of opposite color
				if ((sri == dri + 1) || (sri == dri - 1))
				{
					if (b->getpiece(dri, dci)->getcolor() == White || Black)
					{
						if (dri == sri + 1)
						{
							return true;
						}
						else if (dri == sri - 1)
						{


							return true;

						}
					}

				}
			}
		}
		return false;
	}
public:
    Pawn(int r, int c, Colour _c,Board*B);
    void draw();
	char getchar();
};

