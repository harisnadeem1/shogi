#pragma once
#include"Header.h"
class Piece;

class Board
{
	public:
	Piece* ** Ps;
	
public:
	
	Board();
	
	void display();
	Piece* getpiece(int r, int c);
	
	
	void move(int sr, int sc, int dr, int dc);
	//bool ismypiece(int sri, int sci, int dri, int dci);
};

