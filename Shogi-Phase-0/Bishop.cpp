#include "Bishop.h"
#include<iostream>
using namespace std;
Bishop::Bishop(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void Bishop::draw()
{
	cout  << ((C == Black) ? 'B' : 'b');
}
char Bishop::getchar()
{
	return((C == Black) ? 'B' : 'b');
}