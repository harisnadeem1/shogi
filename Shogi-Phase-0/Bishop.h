#pragma once


#include"Header.h"

#include"Piece.h"

class Bishop :public Piece
{
public:
    Bishop(int r, int c, Colour _c, Board* B);
    void draw();
	char getchar();
	bool IsLegalPlace(int sri, int sci, int dri, int dci, Board*b)
	{
		if ((dci - sci == dri - sri) || (dci - sci == sri - dri))
		{
			int ri = (dri - sri > 0) ? 1 : -1;
			int ci = (dci - sci > 0) ? 1 : -1;
			int rc;
			int cc;
			for (rc = sri + ri, cc = sci + ci; rc != dri; rc = rc + ri, cc = cc + ci)
			{
				if (b->getpiece(rc, cc)!=nullptr)
					return false;
				
			}
			return true;
		}
		return false;







		//if ((dci - sci == dri - sri) || (dci - sci == sri - dri))
		//{
		//	int ri = (dri - sri > 0) ? 1 : -1;
		//	int ci = (dci - sci > 0) ? 1 : -1;
		//	int rc;
		//	int cc;
		//	for (rc = sri + ri, cc = sci + ci; rc != dri; rc = rc + ri, cc = cc + ci)
		//	{
		//		if (b->getpiece(rc,cc) != nullptr)
		//			return false;
		//	}
		//	return true;
		//}
		return true;
	}
};



