#pragma once
#include"Header.h"
#include"Board.h"

class Board;
class Piece
{
protected:
	int row;
	int col;
	Colour C;
	Board* b;
	bool isverticalmove(int sri, int sci, int dri, int dci);
	
	bool ishorizontalmove(int sri, int sci, int dri, int dci);
	
	bool isdigonalmove(int sri, int sci, int dri, int dci);
	
	bool isverticalpathclear(int sri, int sci, int dri, int dci);
	
	bool ishorizontalpathclear(int sri, int sci, int dri, int dci);
	
	bool isdiagnolpath_clear(int sri, int sci, int dri, int dci);
	
public:
	
	Piece(int r, int c, Colour _c,Board*B);
	Colour getcolor();
	void move(int r, int c);
	virtual void draw()=0;
	virtual bool IsLegalPlace(int sri, int sci, int dri, int dci, Board* b) = 0;
	virtual char getchar()=0;
	bool IsLegalMove(int sri, int sci, int dri, int dci, Board* b);
};

