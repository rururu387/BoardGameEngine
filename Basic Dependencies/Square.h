#pragma once

class Square
{
	int x;
	int y;
public:
	int getX() const { return x; };
	int getY() const { return y; };
	void setX(int _x) { x = _x; };
	void setY(int _y) { y = _y; };
	Square(int _x, int _y) { x = _x; y = _y; };
	Square() { x = 0; y = 0; };
	bool operator ==(Square sq) const;
	int toHash() const;
	bool operator< (const Square& sq) const;
};