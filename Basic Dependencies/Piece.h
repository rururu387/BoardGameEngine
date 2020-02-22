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
	void setPosition(Square* _piecePosition) { piecePosition = _piecePosition; };
	std::string getName() const { return name; };
	void setName(std::string _name) { name = _name; };
	//ColourId is a shortened unfo about colour. It is fully stored in class Colour
	int getColourId() const { return colourId; };
	void setColourId(int _colourId) { colourId = _colourId; };
	//Returns piece's price
	double getValue(const Piece& piece) const { return piece.getPrice(); };
	virtual std::istream& findPieceStartPos(std::istream& in) { throw (std::bad_function_call()); };
	virtual std::vector<Position*> toNextPositions(Position* startPosition) { throw (std::bad_function_call()); };
	Piece(std::string _name, int _colourId, Square* _piecePosition)
	{
		name = _name;
		colourId = _colourId;
		piecePosition = _piecePosition;
	}
	Piece(const Piece& _piece);
	virtual std::vector<Position*> toNextPositions(Position startPosition) {};
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