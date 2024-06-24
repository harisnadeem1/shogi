#include "Lance.h"
#include<iostream>
using namespace std;
Lance::Lance(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void Lance::draw()
{
	cout  << ((C == Black) ? 'L' : 'l');
}

char Lance::getchar()
{
	return ((C == Black) ? 'L' : 'l');
}