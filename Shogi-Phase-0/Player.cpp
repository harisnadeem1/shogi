
#include "Player.h"

Player::Player(string _n, Colour _c)
{
	this->name = _n;
	this->C = _c;
}
string Player::getname()
{
	return name;
}
Colour Player::getcolor()
{
	return C;
}