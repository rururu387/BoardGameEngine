#include "Piece.h"

void Piece::setSquare(int x, int y)
{
	pieceSquare = Square(x, y);
}

void Piece::setSquare(Square sq)
{
	pieceSquare = sq;
}

Piece::Piece(std::string _name, int _colourId, int x, int y)
{
	name = _name;
	colourId = _colourId;
	pieceSquare = Square(x, y);
}

Piece::Piece(std::string _name, int _colourId, Square _piecePosition)
{
	name = _name;
	colourId = _colourId;
	pieceSquare = _piecePosition;
}

Piece::Piece(const Piece& _piece)
{
	name = _piece.getName();
	pieceSquare = _piece.getSquare();
	colourId = _piece.getColourId();
}

std::istream& Piece::findPieceStartPos(std::istream& in)
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
		if (cnt == getName().length())
		{
			return in;
		}
	}
}