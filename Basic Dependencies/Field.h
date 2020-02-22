#pragma once

class Field
{
	std::map<int, std::map <int, Square*>> field;
public:
	Field(int size);
	Field(int m, int n);
	Field(std::map<int, std::map <int, Square*>> _field) { field = _field; };
	~Field();
	Square* searchSquare(int x, int y);
};

Square* Field::searchSquare(int x, int y)
{
	Square* s = field.at(y).at(x);
	return s;
}

Field::Field(int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			field[i][j] = new Square(i, j);
		}
	}
}

Field::Field(int m, int n)
{
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			field[i][j] = new Square(i, j);
		}
	}
}

Field::~Field()
{
	for (std::map<int, std::map <int, Square*>>::iterator it = field.begin(); it != field.end(); it++)
	{
		for (std::map <int, Square*>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			delete it2->second;
		}
	}
}