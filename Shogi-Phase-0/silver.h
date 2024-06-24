#pragma once
#include"Header.h"

#include"Piece.h"

class silver :public Piece
{
public:
    silver(int r, int c, Colour _c, Board* B);
    void draw();
	char getchar();
	bool IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
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
			/*else if ((dci - 1 == sci || dci + 1 == sci) && sri == dri)
				return true;*/
			/*else if (dri + 1 == sri && sci == dci)
				return true;*/
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
};
