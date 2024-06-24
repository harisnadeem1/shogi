#include "silver.h"
#include<iostream>
using namespace std;

silver::silver(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void silver::draw()
{
	cout  << ((C == Black) ? 'S' : 's');
}


char silver::getchar()
{
	return ((C == Black) ? 'S' : 's');
}