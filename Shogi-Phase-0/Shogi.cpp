
#include"Board.h"
#include"Rook.h"
#include"Bishop.h"
#include"Knight.h"
#include"gold.h"
#include"Lance.h"
#include"silver.h"
#include"King.h"
#include"Piece.h"
#include"Pawn.h"
#include"Player.h"
#include "Shogi.h"
#include"Promoted_Silver.h"
#include"Promoted_Knight.h"
#include"Promoted_Lance.h"
#include"Promoted_Rook.h"
#include"Promoted_Bishop.h"
#include<Windows.h>
#include<fstream>

void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}

void cordinatesClicked(int rClicked, int cClicked, int rowD, int colD)
{
	getRowColbyLeftClick(rClicked, cClicked);
	gotoRowCol(4, 150);
	cout << "ROW: " << rClicked << " , COLUMN: " << cClicked << endl;
}


void Shogi:: loadgame()
{
	ifstream rdr("Game.txt");
	rdr >>turn;
	char c;
	for (int ri = 0; ri < 9; ri++)
	{
		for (int ci = 0; ci < 9; ci++)
		{
			rdr >> c;
			switch (c)
			{
			case 'P':
				this->B->Ps[ri][ci] = new Pawn(ri, ci, Black, B);
				break;
			case'p':
				this->B->Ps[ri][ci] = new Pawn(ri,ci,White,B);
				break;
			case'R':
				this->B->Ps[ri][ci] = new Rook(ri, ci, Black, B);
				break;
			case 'r':
				this->B->Ps[ri][ci] = new Rook(ri, ci, White, B);	
				break;
			case'B':
				this->B->Ps[ri][ci] = new Bishop(ri, ci, Black, B);
				break;
			case 'b':
				this->B->Ps[ri][ci] = new Bishop(ri, ci, White, B);
				break;
			case'G':
				this->B->Ps[ri][ci] = new gold(ri, ci, Black, B);
				break;
			case 'g':
				this->B->Ps[ri][ci] = new gold(ri, ci, White, B);
				break;
			case'K':
				this->B->Ps[ri][ci] = new King(ri, ci, Black, B);
				break;
			case 'k':
				this->B->Ps[ri][ci] = new King(ri, ci, White, B);
				break;
			case'N':
				this->B->Ps[ri][ci] = new Knight(ri, ci, Black, B);
				break;
			case 'n':
				this->B->Ps[ri][ci] = new Knight(ri, ci, White, B);
				break;
			case 'L':
				this->B->Ps[ri][ci] = new Lance(ri, ci, Black, B);
				break;
			case'l':
				this->B->Ps[ri][ci] = new Lance(ri, ci, White, B);
				break;
			case 'S':
				this->B->Ps[ri][ci] = new silver(ri, ci,Black, B);
				break;
			case's':
				this->B->Ps[ri][ci] = new silver(ri, ci, White, B);
				break;
			case'-':
				this->B->Ps[ri][ci] = nullptr;
				break;
			}
		}
	}
}

Shogi::Shogi()
{
	sr = 0; sc = 0; dr = 0; dc = 0;
	Ps[0] = new Player("Yellow", Black);
	Ps[1] = new Player("Red", White);
	B = new Board();
	turn = rand() % 2;
}

void Shogi::displayturnmsg(Player* p)
{
	cout << p->getname() << " Turn\n";
}

void Shogi::selectPiece()
{
	int r=0, c = 0;
	getRowColbyLeftClick(r,c);
	sr = r / 5;
	sc = c / 5;
}

void Shogi::selectdestination()
{
	int r = 0, c = 0;
	getRowColbyLeftClick(r, c);
	dr = r / 5;
	dc = c / 5;
	//cin >> dr >> dc;
}

void Shogi::turn_change()
{
	turn = (turn + 1) % 2;
}

bool Shogi:: validSourceSelect(int sr, int sc, Player* P)
{
	if (sr < 0 || sr >= 9 || sc < 0 || sc >= 9)
	{
		return false;
	}
	Piece* p = B->getpiece(sr, sc);
	return (p != nullptr && p->getcolor() == P->getcolor());
}

bool Shogi::validDestinationSelect(int sr, int sc, Player* P)
{
	return (sr < 0 || sr >= 9 || sc < 0 || sc >= 0) && !validSourceSelect(sr,sc,P);
}

void Shogi::savegame()
{
	ofstream wtr("Game.txt");
	wtr << turn ;
	wtr << endl;
	for (int ri = 0; ri < 9; ri++)
	{
		for (int ci = 0; ci < 9; ci++)
		{
			if (B->getpiece(ri, ci) == nullptr)
				wtr << '-';
			else
				wtr<<B->getpiece(ri, ci)->getchar();
		}
		wtr << endl;
	}

}

void Shogi:: highlight(int sri, int sci)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int r = 0;r < 9;r++)
	{
		for (int c = 0;c < 9;c++)
		{
			if (B->getpiece(sri, sci)->IsLegalPlace(sri, sci, r, c, B))
			{
				
				if (B->getpiece(r, c) != nullptr)
				{
					if (B->getpiece(sri, sci)->getcolor() != B->getpiece(r, c)->getcolor())
					{
						gotoRowCol(r * 5 + 2, c * 5 + 2);
						SetConsoleTextAttribute(H, 2);
						cout << 'X';
						gotoRowCol(r * 5 + 2, c * 5 + 3);
						cout << 'X';
						SetConsoleTextAttribute(H, 15);
						//color(0);
					}
				}
				else if (B->getpiece(r, c) == nullptr)
				{
					gotoRowCol(r * 5 + 2, c * 5 + 2);
					//SetConsoleTextAttribute(H, 0);
					cout << 'X';
				}
				
			}
		}
	}
}

void ispromotion(int sri,int sci,int dri,int dci,Board*b)
{
	if ((dri == 0 || dri == 1 || dri == 2) && b->getpiece(sri, sci)->getcolor() == White&&(b->getpiece(sri,sci)->getchar() == 'p'))
	{
		b->Ps[sri][sci] = new Promoted_Pawn(sri, sci, White, b);
	}
	else if ((dri == 6 || dri == 7 || dri == 8) && b->getpiece(sri, sci)->getcolor() == Black && (b->getpiece(sri, sci)->getchar() == 'P'))
	{
		b->Ps[sri][sci] = new Promoted_Pawn(sri, sci, Black, b);
	}
	else if ((dri == 0 || dri == 1 || dri == 2) && b->getpiece(sri, sci)->getcolor() == White && (b->getpiece(sri, sci)->getchar() == 's'))
	{
		b->Ps[sri][sci] = new Promoted_Silver(sri, sci, White, b);
	}
	else if ((dri == 6 || dri == 7 || dri == 8) && b->getpiece(sri, sci)->getcolor() == Black && (b->getpiece(sri, sci)->getchar() == 'S'))
	{
		b->Ps[sri][sci] = new Promoted_Silver(sri, sci, Black, b);
	}
	else if ((dri == 0 || dri == 1 || dri == 2) && b->getpiece(sri, sci)->getcolor() == White && (b->getpiece(sri, sci)->getchar() == 'n'))
	{
		b->Ps[sri][sci] = new Promoted_Knight(sri, sci, White, b);
	}
	else if ((dri == 6 || dri == 7 || dri == 8) && b->getpiece(sri, sci)->getcolor() == Black && (b->getpiece(sri, sci)->getchar() == 'N'))
	{
		b->Ps[sri][sci] = new Promoted_Knight(sri, sci, Black, b);
	}
	else if ((dri == 0 || dri == 1 || dri == 2) && b->getpiece(sri, sci)->getcolor() == White && (b->getpiece(sri, sci)->getchar() == 'l'))
	{
		b->Ps[sri][sci] = new Promoted_Lance(sri, sci, White, b);
	}
	else if ((dri == 6 || dri == 7 || dri == 8) && b->getpiece(sri, sci)->getcolor() == Black && (b->getpiece(sri, sci)->getchar() == 'L'))
	{
		b->Ps[sri][sci] = new Promoted_Lance(sri, sci, Black, b);
	}
	else if ((dri == 0 || dri == 1 || dri == 2) && b->getpiece(sri, sci)->getcolor() == White && (b->getpiece(sri, sci)->getchar() == 'r'))
	{
		b->Ps[sri][sci] = new Promoted_Rook(sri, sci, White, b);
	}
	else if ((dri == 6 || dri == 7 || dri == 8) && b->getpiece(sri, sci)->getcolor() == Black && (b->getpiece(sri, sci)->getchar() == 'R'))
	{
		b->Ps[sri][sci] = new Promoted_Rook(sri, sci, Black, b);
	}
	else if ((dri == 0 || dri == 1 || dri == 2) && b->getpiece(sri, sci)->getcolor() == White && (b->getpiece(sri, sci)->getchar() == 'b'))
	{
		b->Ps[sri][sci] = new Promoted_Bishop(sri, sci, White, b);
	}
	else if ((dri == 6 || dri == 7 || dri == 8) && b->getpiece(sri, sci)->getcolor() == Black && (b->getpiece(sri, sci)->getchar() == 'B'))
	{
		b->Ps[sri][sci] = new Promoted_Bishop(sri, sci, Black, b);
	}
}

void savebutton()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, 2);
	gotoRowCol(30, 100);
	char sym = 178;
	cout << sym << sym << sym << sym << sym << sym << sym << sym<< sym << sym << sym << sym << sym;
	gotoRowCol(31, 100);
	cout << sym;
	SetConsoleTextAttribute(H, 6);
	cout << " SAVE GAME ";
	SetConsoleTextAttribute(H, 2);
	cout << sym;
	gotoRowCol(32, 100);
	cout << sym << sym << sym << sym << sym << sym << sym << sym<< sym << sym << sym << sym << sym;
	SetConsoleTextAttribute(H, 15);
}
void removesavebutton()
{
	
	gotoRowCol(30, 100);
	
	cout <<"                                  ";
	gotoRowCol(31, 100);
	cout << "                                 ";
	gotoRowCol(32, 100);
	cout << "                                 ";
	
}
bool checksave()
{
	int r = 0, c = 0;
	getRowColbyLeftClick(r, c);
	if (r >= 30 && r <= 32 && c >= 100 && c <= 107)
		return true;
	return false;
}

void loadbutton()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, 2);
	gotoRowCol(20, 20);
	char sym = 178;
	cout << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym;
	gotoRowCol(21, 20);
	cout << sym << " LOAD GAME " << sym;
	gotoRowCol(22, 20);
	cout << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym;
	SetConsoleTextAttribute(H, 15);
}
void newbutton()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, 2);
	gotoRowCol(10, 20);
	char sym = 178;
	cout << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym;
	gotoRowCol(11, 20);
	cout << sym << " NEW GAME " << sym;
	gotoRowCol(12, 20);
	cout << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym << sym;
	SetConsoleTextAttribute(H, 15);
}
void Shogi::unhighlight()
{
	B->display();
}

void Shogi ::Play()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	int count = 0;
	int r1 = 0, r2 = 0, c1 = 0, c2 = 0;
	
	while (1) {
		
		
		gotoRowCol(0, 0);
		if (count == 0)
		{
			int r = 0, c = 0;
			SetConsoleTextAttribute(H, 4);
			cout << "\n\n\n\n\n\tDo you Want to Load Game OR Start New Game\n";
			loadbutton();
			newbutton();
			getRowColbyLeftClick(r, c);
			if(r>=20&&r<=22&&c>=20&&c<=32)
			{
				loadgame();
			}
			SetConsoleTextAttribute(H, 15);
			system("cls");
		}
		
		B->display();
		if (count>1) {
			savebutton();
			if (checksave())
			{
				savegame();
			}
			removesavebutton();
		}
		cout <<"\n\n\n";
		gotoRowCol(45, 0);
		cout << "  0    1    2    3    4    5    6    7    8\n\n";
		
		
		displayturnmsg(Ps[turn]);cout << endl;
		do {
			do {
				gotoRowCol(49, 5);
				cout << "                                          ";
				gotoRowCol(10 * 5, 5);
				cout << "                                                 ";
				gotoRowCol(49, 5);
				cout << "\tSelect Piece: ";
				
				selectPiece();

			} while (!validSourceSelect(sr, sc, Ps[turn]));
			highlight(sr, sc);
			do {


				
				gotoRowCol(10 * 5, 5 );
				cout << "                                                 ";
				gotoRowCol(10 * 5, 5);
				
					cout << "\tSelect Destination: ";
					
					selectdestination();

						unhighlight();

			} while (!validDestinationSelect(dr, dc, Ps[turn]));
		} while (!B->getpiece(sr, sc)->IsLegalPlace(sr, sc, dr, dc, B));
		ispromotion(sr, sc, dr, dc, B);
		B->move(sr, sc, dr, dc);
		turn_change();
		
		
		system("cls");
		
		count++;
	}
}
















//bool Shogi:: IsCheckBlack(Colour C)
//{
//	// Find the king
//	int iKingRow;
//	int iKingCol;
//	for (int iRow = 0; iRow < 9; ++iRow)
//	{
//		for (int iCol = 0; iCol < 9; ++iCol)
//		{
//			if (B->getpiece(iRow,iCol) != nullptr)
//			{
//				if (B->getpiece(iRow, iCol)->getcolor() == (C==1))
//				{
//					if (B->getpiece(iRow, iCol)->getchar() == 'K')
//					{
//						iKingRow = iRow;
//						iKingCol = iCol;
//						return true;
//					}
//				}
//				
//			}
//		}
//	}
//	
//	// Run through the opponent's pieces and see if any can take the king
//	/*for (int iRow = 0; iRow < 9; ++iRow)
//	{
//		for (int iCol = 0; iCol < 9; ++iCol)
//		{
//			if (B->getpiece(iRow, iCol) != nullptr)
//			{
//				if (B->getpiece(iRow, iCol)->getcolor() != (C==1))
//				{
//					if (B->getpiece(iRow, iCol)->IsLegalMove(iRow, iCol, iKingRow, iKingCol,B))
//					{
//						return true;
//					}
//				}
//			}
//		}
//	}*/
//	return false;
//}
//bool Shogi::IsCheckWhite(Colour C)
//{
//	// Find the king
//	int iKingRow;
//	int iKingCol;
//	for (int iRow = 0; iRow < 9; ++iRow)
//	{
//		for (int iCol = 0; iCol < 9; ++iCol)
//		{
//			if (B->getpiece(iRow, iCol) != nullptr)
//			{
//				if (B->getpiece(iRow, iCol)->getcolor() == (C == 0))
//				{
//					if (B->getpiece(iRow, iCol)->getchar() == 'k')
//					{
//						iKingRow = iRow;
//						iKingCol = iCol;
//						return true;
//					}
//				}
//
//			}
//		}
//	}
//	return false;
//}
//bool Shogi:: IsCastle(int sri, int sci, int dci)
//{
//	if (turn == White && sri == 0)
//	{
//		if (B->getpiece(sri,3)->getchar() == 'k')
//		{
//			if (dci == 0 || dci == 8)
//				return true;
//		}
//	}
//	else if (turn == Black && sri == 8)
//	{
//		if (B->getpiece(sri,3)->getchar() == 'K')
//		{
//			if (dci == 8 || dci == 0)
//				return true;
//		}
//	}
//	return false;
//}
//void Shogi:: Castle(int sri, int sci, int dri, int dci)
//{
//	if (IsCastle(sri, sci, dci))
//	{
//		if (turn == Black)
//		{
//			if (B->getpiece(0,4)->getchar() == 'K' && B->getpiece(0, 3) == nullptr && B->getpiece(0, 2) == nullptr)
//			{
//				B->Ps[0][2] = new King(0,2,Black,B);
//				B->Ps[0][3] = new Rook(0,3,Black,B);
//				B->Ps[0][4] = nullptr;
//				B->Ps[0][1] = nullptr;
//			}
//			else if (B->getpiece(0, 4)->getchar() == 'K' && B->getpiece(0,5) == nullptr && B->getpiece(0,6) == nullptr && B->getpiece(0,7) == nullptr)
//			{
//				B->Ps[0][6] = new King(0,6,Black,B);
//				B->Ps[0][5] = new Rook(0,5,Black,B);
//				B->Ps[0][4] = nullptr;
//				B->Ps[0][8] = nullptr;
//			}
//		}
//		else
//		{
//			if (B->getpiece(8,4)->getchar() == 'k' && B->getpiece(8,3) == nullptr && B->getpiece(8,2) == nullptr)
//			{
//				B->Ps[8][2] = new King(8, 2, White, B);
//				B->Ps[8][3] = new Rook(8, 3, White, B);
//				B->Ps[8][4] = nullptr;
//				B->Ps[8][0] = nullptr;
//			}
//			else if (B->getpiece(8,4)->getchar() == 'K' && B->getpiece(8,5) == nullptr && B->getpiece(8,6) == nullptr && B->getpiece(8,7) == nullptr)
//			{
//				B->Ps[8][6] = new King(8, 6, White, B);
//				B->Ps[8][5] = new Rook(8, 5, White, B);
//				B->Ps[8][4] = nullptr;
//				B->Ps[8][8] = nullptr;
//			}
//		}
//	}
//}