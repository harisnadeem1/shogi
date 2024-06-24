#pragma once
#include"Header.h"

#include"Piece.h"

class Lance :public Piece
{
public:
    Lance(int r, int c, Colour _c, Board* B);
    void draw();
	char getchar();
	bool IsLegalPlace(int sri, int sci, int dri, int dci, Board* b)
	{
		if (sci == dci)
		{
			if (b->getpiece(sri, sci)->getcolor() == White)
			{
				if (dri > sri)
					return false;
				if (dri < sri)
				{
					for (int r = sri + 1;r < dri;r++)
					{
						if (b->getpiece(r, sci) != nullptr)
							return false;
						
					}
				}
			}
			else if (b->getpiece(sri, sci)->getcolor() == Black)
			{
				if (dri < sri)
					return false;
				if (dri > sri)
				{
					for (int r = sri-1 ;r > dri;r--)
					{
						if (b->getpiece(r, sci) != nullptr)
							return false;
						//return true;
					}
				}
			}
			/*int rc = (dri - sri > 0) ? -1 : -1;
			for (int ri = rc + sri; ri != dri; ri = ri + rc)
			{
				if (b->getpiece(ri, sci) != nullptr)
					return false;
			}
			return true;*/
		}
		return true;
	}
};
