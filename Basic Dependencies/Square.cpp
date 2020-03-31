#include "Square.h"

bool Square::operator<(const Square& sq) const
{
	if (y < sq.getY())
	{
		return true;
	}
	else if (y == sq.getY() && x < sq.getX())
	{
		return true;
	}
	return false;
}

inline int Square::toHash() const
{
	std::hash<int> hashFn;
	return hashFn(x) / 2 + hashFn(y) / 2;
}

bool Square::operator==(Square sq) const
{
	if (x == sq.getX() && y == sq.getY())
	{
		return true;
	}
	return false;
}