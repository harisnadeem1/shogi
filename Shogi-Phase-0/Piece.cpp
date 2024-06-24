#include "Piece.h"

#include<iostream>
using namespace std;

Piece::Piece(int r,int c,Colour _c,Board*B)
{
	this->row = r;
	this->col = c;
	this->C = _c;
	this->b = B;
}

Colour Piece::getcolor()
{
	return this->C;
}
void Piece::move(int r, int c)
{
	this->row = r;
	this->col = c;
}

bool Piece:: IsLegalMove(int sri, int sci, int dri, int dci, Board* b)
{

	if ((b->getpiece(dri, dci) == nullptr) || (C != b->getpiece(dri, dci)->getcolor()))
	{
		return IsLegalPlace(sri, sci, dri, dci, b);
	}
	return false;
}

bool Piece::isverticalmove(int sri, int sci, int dri, int dci)
{
	return sci == dci;
}
bool Piece::ishorizontalmove(int sri, int sci, int dri, int dci)
{
	return sri == dri;
}
bool Piece::isdigonalmove(int sri, int sci, int dri, int dci)
{
	int dr = abs(dri - sri);
	int dc = abs(dci - sci);
	return (dr == dc);
}
bool Piece::isverticalpathclear(int sri, int sci, int dri, int dci)
{
	if (dri > sri)
	{
		for (int c = sri + 1;c < dri;c++)
		{
			if (b->getpiece(c, sci) != nullptr)
				return false;
		}
		return true;
	}
	else if (sri > dri)
	{
		for (int c = sri - 1;c > dri;c--)
		{
			if (b->getpiece(c, sci) != nullptr)
				return false;
		}
		return true;
	}

}
bool Piece:: ishorizontalpathclear(int sri, int sci, int dri, int dci)
{
	if (dci > sci)
	{
		for (int c = sci + 1;c < dci;c++)
		{
			if (b->getpiece(c, sri) != nullptr)
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
bool Piece:: isdiagnolpath_clear(int sri, int sci, int dri, int dci)
{
	if (sri > dri && sci < dci)
	{
		for (int i = sri - 1; i > dri; i--)
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
	//if no 2

	if (sri > dri && sci > dci)
	{
		for (int i = sri - 1; i > dri; i--)
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

