#pragma once
#include"Header.h"

#include"Piece.h"

class Rook :public Piece
{
public:
    Rook(int r, int c, Colour _c, Board* B);
    void draw();
	char getchar();
	bool IsLegalPlace(int sri, int sci, int dri, int dci, Board*b)
	{
		if (sri == dri)
		{
			int cc = (dci - sci > 0) ? 1 : -1;
			for (int ci = cc + sci; ci != dci; ci = ci + cc)
			{
				if (b->getpiece(sri,ci) != nullptr)
					return false;
			}
			return true;
		}
		else if (sci == dci)
		{
			int rc = (dri - sri > 0) ? 1 : -1;
			for (int ri = rc + sri; ri != dri; ri = ri + rc)
			{
				if (b->getpiece(ri,sci) != nullptr)
					return false;
			}
			return true;
		}
		return false;
	}
};
