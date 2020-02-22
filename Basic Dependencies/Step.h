#pragma once

class Step
{
	std::any* piece;
	std::string pieceLocation;
	Square* startSquare;
	Square* endSquare;
public:
	Step(std::any* _piece, Square* _startSquare, Square* _endSquare);
	std::any* getPiece();
};

Step::Step(std::any* _piece, Square* _startSquare, Square* _endSquare)
{
	piece = _piece;
	startSquare = _startSquare;
	endSquare = _endSquare;
}