#include "King.h"
#include<iostream>
using namespace std;
King::King(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void King::draw()
{
	cout  << ((C == Black) ? 'K' : 'k');
}

char King::getchar()
{
	return ((C == Black) ? 'K' : 'k');
}