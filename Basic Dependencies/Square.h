#pragma once
#include <string>

class Square
{
	int x;
	int y;
	bool isBusy;
public:
	int getX() { return x; };
	int getY() { return y; };
	bool getIsBusy() { return isBusy; };
	bool setIsBusy(bool _isBusy) { isBusy = _isBusy; };
	Square(int _x, int _y) { x = _x; y = _y; isBusy = false; };
};