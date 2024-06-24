#include "Rook.h"
#include<iostream>
using namespace std;

Rook::Rook(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void Rook::draw()
{
	cout << ((C == Black) ? 'R' : 'r');
}

char Rook::getchar()
{
	return ((C == Black) ? 'R' : 'r');
}