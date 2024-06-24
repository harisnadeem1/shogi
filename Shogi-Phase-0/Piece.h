#pragma once
#include"Header.h"
#include"Board.h"

class Board;
class Piece
{
protected:
	int row;
	int col;
	Colour C;
	Board* b;
	bool isverticalmove(int sri, int sci, int dri, int dci)
	{
		return sci == dci;
	}
	bool ishorizontalmove(int sri, int sci, int dri, int dci)
	{
		return sri == dri;
	}
	bool isdigonalmove(int sri, int sci, int dri, int dci)
	{
		int dr = abs(dri - sri);
		int dc = abs(dci - sci);
		return (dr == dc);
	}
	bool isverticalpathclear( int sri, int sci, int dri, int dci)
	{
		if (dri > sri)
		{
			for (int c = sri + 1;c < dri;c++)
			{
				if (b->getpiece(c,sci) != nullptr)
					return false;
			}
			return true;
		}
		else if (sri > dri)
		{
			for (int c = sri - 1;c > dri;c--)
			{
				if (b->getpiece(c,sci) != nullptr)
					return false;
			}
			return true;
		}

	}
	bool ishorizontalpathclear( int sri, int sci, int dri, int dci)
	{
		if (dci > sci)
		{
			for (int c = sci + 1;c < dci;c++)
			{
				if (b->getpiece(c,sri) != nullptr)
					return false;
			}
			return true;
		}
		else if (sci > dci)
		{
			for (int c = sci - 1;c > dci;c--)
			{
				if (b->getpiece(c, sri) != nullptr)
					return false;
			}
		}
	}
	bool isdiagnolpath_clear( int sri, int sci, int dri, int dci)
{
	if (sri > dri && sci < dci)
	{
		for (int i = sri - 1; i > dri; i--)
		{
			for (int j = sci + 1; j < dci; j++)
			{
				if (b->getpiece(i,j) != nullptr)
				{
					return false;
				}
			}
		}
	}
	//if no 2

	if (sri > dri && sci > dci)
	{
		for (int i = sri - 1; i > dri; i--)
		{
			for (int j = sci - 1; j > dci; j--)
			{
				if (b->getpiece(i,j) != nullptr)
				{
					return false;
				}
			}
		}
	}
	// if no 3

	if (sri < dri && sci < dci)
	{
		for (int i = sri + 1; i < dri; i++)
		{
			for (int j = sci + 1; j < dci; j++)
			{
				if (b->getpiece(i, j) != nullptr)
				{
					return false;
				}
			}
		}
	}
	// if no 4
	if (sri<dri && sci>dci)
	{
		for (int i = sri + 1; i < dri; i++)
		{
			for (int j = sci - 1; j > dci; j--)
			{
				if (b->getpiece(i, j) != nullptr)
				{
					return false;
				}
			}
		}
	}
	return true;
}


	bool IsLegalMove(int sri, int sci, int dri, int dci, Board* b)
	{
		//Piece* dest = CBoard[dri][dci];
		if ((b->getpiece(dri,dci) == nullptr) || (C != b->getpiece(dri, dci)->getcolor()))
		{
			return IsLegalPlace(sri, sci, dri, dci, b);
		}
		return false;
	}
public:
	
	Piece(int r, int c, Colour _c,Board*B);
	Colour getcolor();
	void move(int r, int c);
	virtual void draw()=0;
	virtual bool IsLegalPlace(int sri, int sci, int dri, int dci, Board* b) = 0;
	virtual char getchar()=0;
	
	
};

