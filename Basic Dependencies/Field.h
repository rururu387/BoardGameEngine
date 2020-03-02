#pragma once

class Field
{
	std::map<int, Square*> field;
public:
	std::map<int, Square*> getField() { return field; };
	std::map<int, Square*>::iterator getFieldEnd() { return field.end(); };
	Field(int size);
	Field(int m, int n);
	Field(std::map<int, Square*> _field) { field = _field; };
	~Field();
	std::map<int, Square*>::iterator searchSquare(int x, int y);
};

std::map<int, Square*>::iterator Field::searchSquare(int x, int y)
{
	std::hash<int> hashFn;
	std::map<int, Square*>::iterator it = field.find(hashFn(x) / 2 + (hashFn(y) / 2));
	return it;
}

Field::Field(int size)
{
	std::hash<int> hashFn;
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			field[hashFn(i) / 2 + (hashFn(j) / 2)] = new Square(i, j);
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
			field[hashFn(i) / 2 + (hashFn(j) / 2)] = new Square(i, j);
		}
	}
}

Field::~Field()
{
	for (std::map<int, Square*>::iterator it = field.begin(); it != field.end(); it++)
	{
		delete it->second;
	}
}