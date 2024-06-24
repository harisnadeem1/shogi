#pragma once
#include"Header.h"
#include"Board.h"
#include"Piece.h"
#include"Promoted_Pawn.h"

class Pawn :public Piece
{
protected:
	
public:
    Pawn(int r, int c, Colour _c,Board*B);
    void draw();
	char getchar();
	bool IsLegalPlace(int sri, int sci, int dri, int dci, Board* b);
	
};

