#include "Field.h"

std::multimap<int, Square*>::iterator Field::searchSquare(Square sq) const
{
	auto range = field.equal_range(sq.toHash());
	for (auto it = range.first; it != range.second; it++)
	{
		if (it->second->getX() == sq.getX() && it->second->getY() == sq.getY())
		{
			return it;
		}
	}
	return field.end();
}

Field::Field(const Field& _field)
{
	field = _field.getField();
}

std::multimap<int, Square*>::iterator Field::searchSquare(int x, int y) const
{
	auto it = searchSquare(Square(x, y));
	return it;
}

Field::Field(int size)
{
	std::hash<int> hashFn;
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Square* sq = new Square(i, j);
			field.insert(std::pair<int, Square*>(sq->toHash(), sq));
		}
	}
}

Field::Field(int m, int n)
{
	std::hash<int> hashFn;
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Square* sq = new Square(i, j);
			field.insert(std::pair<int, Square*>(sq->toHash(), sq));
		}
	}
}

Field::~Field()
{
	for (std::multimap<int, Square*>::iterator it = field.begin(); it != field.end(); it++)
	{
		delete it->second;
	}
}