#include "Knight.h"
#include<iostream>
using namespace std;
Knight::Knight(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void Knight::draw()
{
	cout << ((C == Black) ? 'N' : 'n');
}


char Knight::getchar()
{
	return ((C == Black) ? 'N' : 'n');
}