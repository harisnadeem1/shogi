#include"Header.h"

#include<iostream>
#include<Windows.h>
using namespace std;
#include<conio.h>
#include<math.h>


void gotoRowCol(int rpos, int cpos)
{
	int xpos = cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}