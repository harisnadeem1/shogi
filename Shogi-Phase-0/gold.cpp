#include "gold.h"
#include<iostream>
using namespace std;
gold::gold(int r, int c, Colour _c, Board* B) :Piece(r, c, _c, B)
{

}

void gold::draw()
{
	cout  << ((C == Black) ? 'G' : 'g');
}
char gold::getchar()
{
	return ((C == Black) ? 'G' : 'g');
}