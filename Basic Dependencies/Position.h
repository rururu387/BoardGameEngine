#pragma once

class Position
{
	Field* field;
	std::map<int, Piece*> pieceMap;
	int playersAm;
public:
	Position(Field* _field, std::map<int, Piece*> _pieceMap, int _playersAm);
	Position(Field* _field, std::vector<Piece*> pieceVector, int _playersAm);
	Position(const Position &_pos);
	int getPlayersAm() { return playersAm; };
	void setPlayersAm(int _playersAm) { playersAm = _playersAm; };
	Field* getField() const { return field; };
	std::map<int, Piece*> getPieceMap() const { return pieceMap; };
	double getPriceEval(int colourId);
	std::unordered_set<Position*> toNextPositions();
	virtual bool gameEnd();
	~Position();
};

std::unordered_set<Position*> Position::toNextPositions()
{
	if (this->gameEnd())
	{}
	std::unordered_set<Position*> nextPositions;
	for (std::map<int, Piece*>::iterator it = this->getPieceMap().begin(); it != this->getPieceMap().end(); it++)
	{
		nextPositions.merge(it->second->toNextPositions(this));
	}
	return nextPositions;
}

//Условие выигрыша в шашках (когда все фигуры соперников удалены с доски)
bool Position::gameEnd()
{
	if (pieceMap.empty())
	{
		return true;
	}
	else
	{
		int colourId = pieceMap.begin()->second->getColourId();
		for (std::map<int, Piece*>::iterator it = pieceMap.begin(); it != pieceMap.end(); it++)
		{
			if (colourId != it->second->getColourId())
			{
				return false;
			}
		}
		return true;
	}
}

Position::Position(const Position &_pos)
{
	field = new Field(*(_pos.field));
	pieceMap = std::map<int, Piece*> (_pos.pieceMap);
}

double Position::getPriceEval(int colourId)
{
	double posEval = 0;
	for (std::map<int, Piece*>::iterator it = pieceMap.begin(); it != pieceMap.end(); it++)
	{
		if (it->second->getColourId() == colourId)
		{
			posEval += it->second->getValue();
		}
		else
		{
			posEval -= it->second->getValue() / ( - 1);
		}
	}
}

Position::Position(Field* _field, std::map<int, Piece*> _pieceMap, int _playersAm)
{
	field = _field;
	pieceMap = _pieceMap;
	playersAm = _playersAm;
}

Position::Position(Field* _field, std::vector<Piece*> pieceVector, int _playersAm)
{
	field = _field;
	playersAm = _playersAm;
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