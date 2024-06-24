#pragma once
#include "Piece.h"
class Promoted_Rook :
    public Piece
{

public:
	Promoted_Rook(int r, int c, Colour _c, Board* B);
	void draw();
	char getchar();
	bool IsLegalPlace(int sri, int sci, int dri, int dci, Board* b);
	
};

