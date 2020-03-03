#pragma once

class Position
{
	Field* field;
	std::map<int, Piece*> pieceMap;
public:
	Position(Field* _field, std::map<int, Piece*> _pieceMap);
	Position(Field* _field, std::vector<Piece*> pieceVector);
	Position(const Position &_pos);
	Field* getField() const { return field; };
	std::map<int, Piece*> getPieceMap() const { return pieceMap; };
	double getPriceEval();
	~Position();
};

Position::Position(const Position &_pos)
{
	field = new Field(*(_pos.field));
	pieceMap = std::map<int, Piece*> (_pos.pieceMap);
}

double Position::getPriceEval()
{
	for (std::map<int, Piece*>::iterator it = pieceMap.begin(); it != pieceMap.end(); it++)
	{
		it->second->getValue();
	}
}

Position::Position(Field* _field, std::map<int, Piece*> _pieceMap)
{
	field = _field;
	pieceMap = _pieceMap;
}

Position::Position(Field* _field, std::vector<Piece*> pieceVector)
{
	field = _field;
	for (std::vector<Piece*>::iterator it = pieceVector.begin(); it != pieceVector.end(); it++)
	{
		std::hash<int> hashFn;
		pieceMap[hashFn((*it)->getPosition()->getX()) / 2 + hashFn((*it)->getPosition()->getY()) / 2] = *it;
	}
}

Position::~Position()
{
	for (std::map<int, Piece*>::iterator it = pieceMap.begin(); it != pieceMap.end(); it++)
	{
		delete it->second;
	}
	pieceMap.clear();
}