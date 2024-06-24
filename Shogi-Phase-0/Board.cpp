

#include"Board.h"
#include"Pawn.h"
#include"Bishop.h"
#include"Knight.h"
#include"Rook.h"
#include"Lance.h"
#include"silver.h"
#include"gold.h"
#include"King.h"
#include<Windows.h>
#include<iostream>
using namespace std;




Board::Board()
{
	Ps = new Piece * *[9];
	for (int ri = 0;ri < 9;ri++)
	{
		Ps[ri] = new Piece * [9];
		for (int ci = 0;ci < 9;ci++)
		{
			if (ri == 2)
			{
				Ps[ri][ci] = new Pawn(ri, ci, Black, this);
			}
			else if (ri == 6)
			{
				Ps[ri][ci] = new Pawn(ri, ci, White, this);
			}
			else if (ri == 1 && ci == 1)
			{
				Ps[ri][ci] = new Bishop(ri, ci, Black, this);
			}
			else if (ri == 7 && ci == 1)
			{
				Ps[ri][ci] = new Bishop(ri, ci, White, this);
			}
			else if (ri == 1 && ci == 7)
			{
				Ps[ri][ci] = new Rook(ri, ci, Black, this);
			}
			else if (ri == 7 && ci == 7)
			{
				Ps[ri][ci] = new Rook(ri, ci, White, this);
			}
			else if (ri == 0 && ci == 1 || ri == 0 && ci == 7)
			{
				Ps[ri][ci] = new Knight(ri, ci, Black, this);
			}
			else if (ri == 8 && ci == 1 || ri == 8 && ci == 7)
			{
				Ps[ri][ci] = new Knight(ri, ci, White, this);
			}
			else if (ri == 0 && ci == 0 || ri == 0 && ci == 8)
			{
				Ps[ri][ci] = new Lance(ri, ci, Black, this);
			}
			else if (ri == 8 && ci == 0 || ri == 8 && ci == 8)
			{
				Ps[ri][ci] = new Lance(ri, ci, White, this);
			}
			else if (ri == 0 && ci == 2 || ri == 0 && ci == 6)
			{
				Ps[ri][ci] = new silver(ri, ci, Black, this);
			}
			else if (ri == 8 && ci == 2 || ri == 8 && ci == 6)
			{
				Ps[ri][ci] = new silver(ri, ci, White, this);
			}
			else if (ri == 0 && ci == 3 || ri == 0 && ci == 5)
			{
				Ps[ri][ci] = new gold(ri, ci, Black, this);
			}
			else if (ri == 8 && ci == 3 || ri == 8 && ci == 5)
			{
				Ps[ri][ci] = new gold(ri, ci, White, this);
			}
			else if (ri == 0 && ci == 4)
			{
				Ps[ri][ci] = new King(ri, ci, Black, this);
			}
			else if (ri == 8 && ci == 4)
			{
				Ps[ri][ci] = new King(ri, ci, White, this);
			}

			else
				Ps[ri][ci] = nullptr;
		}

	}
}


void color(int k)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}
void PrintBox(int sr, int sc, int rdim, int cdim, char s, int c)
{
	color(c);
	for (int r = 0; r < rdim; r++)
	{
		for (int c = 0; c < cdim; c++)
		{
			if (r == 0 || r == rdim - 1)
			{
				gotoRowCol(sr + r, sc + c);
				cout << s;
			}
			else if (c == 0 || c == cdim - 1)
			{
				gotoRowCol(sr + r, sc + c);
				cout << s;
			}
			else
			{
				gotoRowCol(sr + r, sc + c);
				cout << s;
			}
		}
	}
}
void PrintGrid(int Rows, int cols, int d, int rdim, int cdim, char s)
{
	for (int r = 0; r < d; r++)
	{
		for (int c = 0; c < d; c++)
		{
			int sr = r * rdim, sc = c * cdim;
			if (r == 0 || r % 2 == 0)
			{
				if (c == 0 || c % 2 == 0)
					PrintBox(sr, sc, rdim, cdim, s, 1);
				else
					PrintBox(sr, sc, rdim, cdim, s, 7);
			}
			else
			{
				if (c == 0 || c % 2 == 0)
					PrintBox(sr, sc, rdim, cdim, s, 7);
				else
					PrintBox(sr, sc, rdim, cdim, s, 1);
			}
		}
	}
	color(2);
}






void Board::display()
{
	PrintGrid(40, 40, 9, 5, 5, -37);
	for (int ri = 0; ri < 9; ri++)
	{
		for (int ci = 0; ci < 9; ci++)
		{
			if (Ps[ri][ci] != nullptr)
			{
				gotoRowCol(((ri + 4 * ri) + 2), ((ci + 4 * ci) + 2));
				color(6);

				Ps[ri][ci]->draw();
			}
		}
	}
	color(7);
}
Piece* Board::getpiece(int r, int c)
{
	return Ps[r][c];
}



void Board::move(int sr, int sc, int dr, int dc)
{
	Ps[dr][dc] = Ps[sr][sc];
	Ps[sr][sc] = nullptr;
	Ps[dr][dc]->move(dr, dc);

}















/*cout << "\n\t\t\t\t Shogi Game";

	cout << "\n\n\n\n";
	cout << "\t0\t1\t2\t3\t4\t5\t6\t7\t8\n\n\n";
	for (int ri = 0;ri < 9;ri++)
		{
			cout << ri;
			for (int ci = 0;ci < 9;ci++)
			{

				if (Ps[ri][ci] == nullptr)
				{
					cout << "\t" << " ";
				}
				else

					Ps[ri][ci]->draw();
			}
			cout << "\n\n";
		}*/