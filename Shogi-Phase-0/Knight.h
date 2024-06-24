#pragma once
#include"Header.h"

#include"Piece.h"

class Knight :public Piece
{
public:
    Knight(int r, int c, Colour _c, Board* B);
    void draw();
	char getchar();
	bool IsLegalPlace(int sri, int sci, int dri, int dci, Board*b)
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
};

