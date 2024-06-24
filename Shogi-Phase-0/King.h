#pragma once
#include"Header.h"

#include"Piece.h"

class King :public Piece
{
public:
    King(int r, int c, Colour _c, Board* B);
    void draw();
	char getchar();
	bool IsLegalPlace(int sri, int sci, int dri, int dci, Board*b)
	{
		int deltar = dri - sri;
		int deltac = dci - sci;
		if (((deltar >= -1) && (deltar <= 1)) && ((deltac >= -1) && (deltac <= 1)))
		{
			return true;
		}
		return false;
	}
};

