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

