#pragma once
#include <map>
#include <unordered_set>
#include "Field.h"
#include "Square.h"

class Position
{
	Field* field;
	std::map<Square, Piece*> pieceMap;
	CircleQueue<Player>* playersQueue;
public:
	Position(Field* _field, CircleQueue<Player>* _playersQueue, std::map<Square, Piece*> _pieceMap);
	Position(Field* _field, CircleQueue<Player>* _playersQueue, std::vector<Piece*> pieceVector);
	Position(const Position &_pos);
	CircleQueue<Player>* getQueue() { return playersQueue; };
	Field* getField() const { return field; };
	std::map<Square, Piece*> getPieceMap() const { return pieceMap; };
	double getPriceEval(int colourId);
	std::unordered_set<Position*> toNextPositions();
	virtual bool gameEnd() const;
	std::map<Square, Piece*>::const_iterator getPieceByCoords(Square sq) const;
	bool isPieceOnCoords(Square sq) const;
	void changePieceSquare(Square sqOld, Square sqNew);
	std::string piecesToString();
	~Position();
};