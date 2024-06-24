#pragma once
#include"Header.h"
#include"Piece.h"

class Rook :public Piece
{
public:
    Rook(int r, int c, Colour _c, Board* B);
    void draw();
	char getchar();
	bool IsLegalPlace(int sri, int sci, int dri, int dci, Board* b);
	
};
