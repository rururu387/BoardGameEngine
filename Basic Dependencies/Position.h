#pragma once

class Position
{
	Field* field;
	std::map<int, std::map <int, Piece*>> pieceMap;
public:
	Position(Field* _field, std::map<int, std::map <int, Piece*>> _pieceMap);
	Position(Field* _field, std::vector<Piece*> pieceVector);
	Field* getField() { return field; };
	std::map<int, std::map <int, Piece*>> getPieceMap() { return pieceMap; };
	~Position();
};

Position::Position(Field* _field, std::map<int, std::map <int, Piece*>> _pieceMap)
{
	field = _field;
	pieceMap = _pieceMap;
}

Position::Position(Field* _field, std::vector<Piece*> pieceVector)
{
	field = _field;
	for (std::vector<Piece*>::iterator it = pieceVector.begin(); it != pieceVector.end(); it++)
	{
		pieceMap[(*it)->getPosition()->getY()][(*it)->getPosition()->getX()] = *it;
	}
}

Position::~Position()
{
	for (std::map<int, std::map <int, Piece*>>::iterator it = pieceMap.begin(); it != pieceMap.end(); it++)
	{
		for (std::map <int, Piece*>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
			delete it2->second;
	}
	pieceMap.clear();
}