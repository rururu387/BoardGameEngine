#include <Position.h>

std::string Position::piecesToString()
{
	std::string str = "";
	for (auto pieceIt = pieceMap.begin(); pieceIt != pieceMap.end(); pieceIt++)
	{
		str += pieceIt->second->getName() + '\t' + "colour:" + std::to_string(pieceIt->second->getColourId()) + '\t' + "coords:" + std::to_string(pieceIt->second->getSquare().getX()) + ", " + std::to_string(pieceIt->second->getSquare().getY()) + '\n';
	}
	return str;
}

void Position::changePieceSquare(Square sqOld, Square sqNew)
{
	if (field->searchSquare(sqNew) == field->getFieldEnd())
	{
		throw std::invalid_argument("Can't move piece to a square that doesn't exist on the field");
	}
	auto pieceIt = pieceMap.find(sqOld);
	pieceIt->second->setSquare(sqNew);
	auto extrPair = pieceMap.extract(sqOld);
	extrPair.key() = sqNew;
	pieceMap.insert(move(extrPair));
}

bool Position::isPieceOnCoords(Square sq) const
{
	if (pieceMap.find(sq) != pieceMap.end())
	{
		return true;
	}
	return false;
}

std::map<Square, Piece*>::const_iterator Position::getPieceByCoords(Square sq) const
{
	return pieceMap.find(sq);
}

std::unordered_set<Position*> Position::toNextPositions()
{
	std::unordered_set<Position*> nextPositions;
	if (this->gameEnd())
	{
		return nextPositions;
	}
	int colourToMove = playersQueue->getElement()->getColourId();
	for (std::multimap<Square, Piece*>::iterator it = this->getPieceMap().begin(); it != this->getPieceMap().end(); it++)
	{
		if (colourToMove == it->second->getColourId())
		{
			nextPositions.merge(it->second->toNextPositions(this));
		}
	}
	return nextPositions;
}

Position::Position(const Position& _pos)
{
	field = new Field(*(_pos.field));
	pieceMap = std::map<Square, Piece*>(_pos.pieceMap);
}

double Position::getPriceEval(int colourId)
{
	double posEval = 0;
	if (playersQueue->getSize() == 1)
	{
		if (colourId == playersQueue->getElement()->getColourId())
			return DBL_MAX;
		else
			return DBL_MIN;
	}
	for (std::map<Square, Piece*>::iterator it = pieceMap.begin(); it != pieceMap.end(); it++)
	{
		if (it->second->getColourId() == colourId)
		{
			posEval += it->second->getValue();
		}
		else
		{
			posEval -= it->second->getValue() / (playersQueue->getSize() - 1);
		}
	}
}

Position::Position(Field* _field, CircleQueue<Player>* _playersQueue, std::map<Square, Piece*> _pieceMap)
{
	field = _field;
	playersQueue = _playersQueue;
	pieceMap = _pieceMap;
}

Position::Position(Field* _field, CircleQueue<Player>* _playersQueue, std::vector<Piece*> pieceVector)
{
	field = _field;
	playersQueue = _playersQueue;
	for (std::vector<Piece*>::iterator it = pieceVector.begin(); it != pieceVector.end(); it++)
	{
		pieceMap.insert(std::pair<Square, Piece*>((*it)->getSquare(), *it));
	}
}

Position::~Position()
{
	playersQueue->~CircleQueue();
	for (std::map<Square, Piece*>::iterator it = pieceMap.begin(); it != pieceMap.end(); it++)
	{
		delete it->second;
	}
	pieceMap.clear();
}