
#include "Header.h"
#include <iostream>
#include<string>
using namespace std;
class Player
{
protected:
	string name;
	Colour C;
public:
	Player(string _n, Colour _c);
	string getname();
	Colour getcolor();
};
