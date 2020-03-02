#pragma once
#include <string>

class Square
{
	int x;
	int y;
public:
	int getX() { return x; };
	int getY() { return y; };
	void setX(int _x) { x = _x; };
	void setY(int _y) { y = _y; };
	Square(int _x, int _y) { x = _x; y = _y; };
};