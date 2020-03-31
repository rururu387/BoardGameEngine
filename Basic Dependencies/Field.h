#pragma once
#include <map>
#include "Square.h"

class Field
{
	std::multimap<int, Square*> field;
public:
	std::multimap<int, Square*> getField() const { return field; };
	std::multimap<int, Square*>::iterator getFieldEnd() { return field.end(); };
	Field(int size);
	Field(int m, int n);
	Field(std::multimap<int, Square*> _field) { field = _field; };
	Field(const Field &_field);
	~Field();
	std::multimap<int, Square*>::iterator searchSquare(Square sq) const;
	std::multimap<int, Square*>::iterator searchSquare(int x, int y) const;
};