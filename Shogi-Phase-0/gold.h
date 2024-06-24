#pragma once
#include"Header.h"
#include"Piece.h"


class gold :public Piece
{
public:
    gold(int r, int c, Colour _c, Board* B);
    void draw();
	char getchar();
	bool IsLegalPlace(int sri, int sci, int dri, int dci, Board* b);
	
};
