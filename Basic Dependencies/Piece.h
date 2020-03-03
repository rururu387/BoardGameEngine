#pragma once
#include <functional>

class Piece
{
	std::string name;
	Square* piecePosition;
	int colourId;
public:
	//Each piece must have a value representing it. The bigger value the more important it is for player. E. g. queen has a value of 9 pawns
	//To create a new piece you have to override the following function
	virtual double getPrice() const = 0;
	Square* getPosition() const { return piecePosition; };
	void setPosition(int x, int y) { piecePosition->setX(x); piecePosition->setY(y); };
	std::string getName() const { return name; };
	void setName(std::string _name) { name = _name; };
	//ColourId is a shortened unfo about colour. It is fully stored in class Colour
	int getColourId() const { return colourId; };
	void setColourId(int _colourId) { colourId = _colourId; };
	//Returns piece's value
	virtual double getValue() const { throw (std::bad_function_call()); };
	virtual std::istream& findPieceStartPos(std::istream& in) { throw (std::bad_function_call()); };
	virtual std::unordered_set<Position*> toNextPositions(Position* startPosition) { throw (std::bad_function_call()); std::unordered_set<Position*> nullSet = std::unordered_set<Position*>();  return nullSet; };
	Piece(std::string _name, int _colourId, Square* _piecePosition)
	{
		name = _name;
		colourId = _colourId;
		piecePosition = _piecePosition;
	}
	Piece(const Piece& _piece);
};

Piece::Piece(const Piece& _piece)
{
	name = _piece.getName();
	piecePosition = _piece.getPosition();
	colourId = _piece.getColourId();
}

std::istream& Piece::findPieceStartPos(std::istream &in)
{
	int cnt = 0;
	while (!in.eof())
	{
		if (in.get() == getName()[cnt])
		{
			cnt++;
		}
		else
		{
			cnt = 0;
		}
		if (cnt == getName().length)
		{
			return in;
		}
	}
}