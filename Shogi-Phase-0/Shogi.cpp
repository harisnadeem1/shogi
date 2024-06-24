#include<Windows.h>
#include<fstream>
#include"Board.h"
#include"Piece.h"
#include"Pawn.h"
#include"Player.h"
#include "Shogi.h"

//void color(int k)
//{
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, k);
//}


Shogi::Shogi()
{
	sr = 0; sc = 0; dr = 0; dc = 0;
	Ps[0] = new Player("Haris", Black);
	Ps[1] = new Player("Player1", White);
	B = new Board();
	turn = rand() % 2;
}

void Shogi::displayturnmsg(Player* p)
{
	cout << p->getname() << " Turn\n";
}

void Shogi::selectPiece()
{
	cin >> this->sr >> this->sc;
}

void Shogi::selectdestination()
{
	cin >> dr >> dc;
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
	for (int r = 0;r < 9;r++)
	{
		for (int c = 0;c < 9;c++)
		{
			if (B->getpiece(sri, sci)->IsLegalPlace(sri, sci, r, c, B))
			{
				//if (B->getpiece(sri, sci)->getcolor() != B->getpiece(r, c)->getcolor()) {
				if (B->getpiece(r, c) != nullptr)
				{
					if (B->getpiece(sri, sci)->getcolor() != B->getpiece(r, c)->getcolor())
					{
						gotoRowCol(r * 5 + 2, c * 5 + 2);
						//color(3);
						cout << "x";
					}
				}
				else if (B->getpiece(r, c) == nullptr)
				{
					gotoRowCol(r * 5 + 2, c * 5 + 2);
					//color(3);
					cout << "x";
				}
				//}
			}
		}
	}
}


bool ispromotion(Piece*p,int sri,int sci)
{
	if ((sri == 0 || sri == 1 || sri == 2) && p->getcolor() == White)
		return true;
	else if ((sri == 6 || sri == 7 || sri == 8) && p->getcolor() == Black)
		return true;
	return false;
}



void Shogi ::Play()
{
	
	while (1) {
		
		B->display();
		
		cout <<"\n\n\n";

		cout << "  0    1    2    3    4    5    6    7    8\n";
		displayturnmsg(Ps[turn]);cout << endl;
		do {
			do {

				cout << "\n\tSelect Source Piece(R C): ";
				selectPiece();

			} while (!validSourceSelect(sr, sc, Ps[turn]));
			highlight(sr, sc);
			do {


				//cout << "\tSelect Destination piece(R C): ";
				//selectdestination();
				//do
				//{
				gotoRowCol(10 * 5, 5 );
				//cout << "                                       "<<endl;
					cout << "\tSelect Destination piece(R C): ";
					
					selectdestination();
				//} while (!B->getpiece(sr, sc)->IsLegalPlace(sr, sc, dr, dc, B));


			} while (!validDestinationSelect(dr, dc, Ps[turn]));
		} while (!B->getpiece(sr, sc)->IsLegalPlace(sr, sc, dr, dc, B));

		
		//if (B->getpiece(sr, sc)->IsLegalPlace(sr, sc, dr, dc, B)) {
		B->move(sr, sc, dr, dc);
		cout << "enter Y to save enter N to continue";
		char Y;
		cin >> Y;
		if (Y == 'Y') {
			savegame();
		}

		
		turn_change();
		system("cls");
	}
}