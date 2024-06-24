#pragma once

class Board;
class Player;
class Piece;
class Shogi
{
protected:
	int sr, sc, dr, dc;
	Board* B;
	int turn;
	Player* Ps[2];
public:
	Shogi();
	void Play();
	void displayturnmsg(Player *p);
	void selectPiece();
	void selectdestination();
	bool validSourceSelect(int r, int c, Player* P);
	bool validDestinationSelect(int sr, int sc, Player* P);
	void turn_change();
	void highlight(int sri, int sci);
	void unhighlight();
	void  savegame();
	void loadgame();
	//bool checkking();
	/*bool IsCheckBlack(Colour c);
	bool IsCheckWhite(Colour c);*/
	//bool IsCastle(int sri, int sci, int dci);
	//void Castle(int sri, int sci, int dri, int dci);*/
};
