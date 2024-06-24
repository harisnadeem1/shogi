#include "Pawn.h"
#include<iostream>
using namespace std;

Pawn::Pawn(int r, int c, Colour _c,Board*B):Piece(r,c,_c,B)
{
	
}

void Pawn::draw()
{
	cout << ((C == Black) ? 'P' : 'p');
}

char Pawn::getchar()
{
	return ((C == Black) ? 'P' : 'p');
}