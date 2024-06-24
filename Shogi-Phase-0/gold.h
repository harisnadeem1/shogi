#pragma once
#include"Header.h"
#include"Piece.h"


class gold :public Piece
{
public:
    gold(int r, int c, Colour _c, Board* B);
    void draw();
	char getchar();
	bool IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
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
			if (dri -1 == sri && sci == dci)
				return true;
			else if ((dci - 1 == sci || dci + 1 == sci) && sri == dri)
				return true;
			else if (dri +1 == sri && sci == dci)
				return true;
			if (sci == dci + 1 || sci == dci - 1)
			{
				if (sri == dri - 1)
					return true;
			}
		}

		/*int deltar = dri - sri;
		int deltac = dci - sci;
		if (((deltar >= -1) && (deltar <= 1)) && ((deltac >= -1) && (deltac <= 1)))
		{
			return true;
		}*/
		return false;
	}
};
