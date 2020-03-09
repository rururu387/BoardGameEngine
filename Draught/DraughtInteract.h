#pragma once

std::unordered_set<Position*> Draught::toNextTake(Position* startPosition, int piecePosHash, int x, int y, int moveToX, int moveToY, int xEaten, int yEaten)
{
	std::hash<int> hashFn;
	std::map<int, Piece*>::iterator itEaten = startPosition->getPieceMap().find(hashFn(xEaten) / 2 + (hashFn(yEaten) / 2));
	if (itEaten != startPosition->getPieceMap().end() && itEaten->second->getColourId() != getColourId())
	{
		std::unordered_set<Position*> s1;
		std::unordered_set<Position*> s2;
		auto pieceTemp = startPosition->getPieceMap().extract(piecePosHash);
		pieceTemp.key = hashFn(moveToX) / 2 + (hashFn(moveToY) / 2);
		startPosition->getPieceMap().insert(std::move(pieceTemp));
		if (startPosition->getPieceMap().find(hashFn(xEaten) / 2 + (hashFn(yEaten) / 2)) != startPosition->getPieceMap().end() && startPosition->getPieceMap().find(hashFn(xEaten) / 2 + hashFn(yEaten) / 2)->second->getColourId() != getColourId())
		{
			startPosition->getPieceMap().erase(hashFn(xEaten) / 2 + hashFn(yEaten) / 2);
		}
		switch (getColourId())
		{
			case 1:
			{
				s1 = toNextTake(startPosition, piecePosHash, moveToX, moveToY, moveToX + 2, moveToY + 2, moveToX + 1, moveToY + 1);
				s2 = toNextTake(startPosition, piecePosHash, moveToX, moveToY, moveToX - 2, moveToY + 2, moveToX - 1, moveToY + 1);
				break;
			}
			case 2:
			{
				s1 = toNextTake(startPosition, piecePosHash, moveToX, moveToY, moveToX + 2, moveToY - 2, moveToX + 1, moveToY - 1);
				s2 = toNextTake(startPosition, piecePosHash, moveToX, moveToY, moveToX + 2, moveToY + 2, moveToX + 1, moveToY + 1);
				break;
			}
			case 3:
			{
				s1 = toNextTake(startPosition, piecePosHash, moveToX, moveToY, moveToX + 2, moveToY - 2, moveToX + 1, moveToY - 1);
				s2 = toNextTake(startPosition, piecePosHash, moveToX, moveToY, moveToX - 2, moveToY - 2, moveToX - 1, moveToY - 1);
				break;
			}
			case 4:
			{
				s1 = toNextTake(startPosition, piecePosHash, moveToX, moveToY, moveToX - 2, moveToY - 2, moveToX - 1, moveToY - 1);
				s2 = toNextTake(startPosition, piecePosHash, moveToX, moveToY, moveToX - 2, moveToY - 2, moveToX - 1, moveToY - 1);
				break;
			}
		}
		s1.merge(s2);
		return s1;
	}
	else
	{

		std::unordered_set<Position*> s1;
		s1.insert(startPosition);
		return s1;
	}
}

std::unordered_set<Position*> Draught::toFirstStepPosition(Position* startPosition, int piecePosHash, int x, int y, int moveToX, int moveToY, int xEaten, int yEaten)
{
	std::hash<int> hashFn;
	std::unordered_set<Position*> nextPosition;

	std::map<int, Square*>::iterator posIt = startPosition->getField()->searchSquare(moveToX, moveToY);
	std::map<int, Square*>::iterator endIt = startPosition->getField()->getFieldEnd();
	std::map<int, Piece*> pieceMap = startPosition->getPieceMap();
	std::map<int, Piece*>::iterator pieceInterfere = pieceMap.find(hashFn(moveToY) / 2 + (hashFn(moveToX) / 2));
	std::map<int, Piece*>::iterator pieceEaten = pieceMap.find(hashFn(xEaten) / 2 + (hashFn(yEaten) / 2));

	if (posIt != endIt && pieceInterfere == pieceMap.end() && (pieceEaten == pieceMap.end() || pieceEaten->second->getColourId() != getColourId()))
	{
		if (pieceEaten != pieceMap.end() && pieceEaten->second->getColourId() != getColourId())
		{
			pieceMap.erase(pieceEaten);

			toNextTake(startPosition, piecePosHash, moveToX, moveToY, moveToX + 2, moveToY + 2, moveToX + 1, moveToY + 1);
		}
		auto pieceTemp = pieceMap.extract(piecePosHash);
		pieceTemp.key = hashFn(moveToX) / 2 + (hashFn(moveToY) / 2);
		pieceMap.insert(std::move(pieceTemp));

		setPosition(moveToX, moveToY);
	}
	return nextPosition;
}

std::unordered_set<Position*> Draught::toNextPositions(const Position* startPosition)
{
	std::unordered_set<Position*> nextPositions;
	int x = getPosition()->getX();
	int y = getPosition()->getY();
	std::hash<int> hashFn;
	int piecePosHash = hashFn(x) / 2 + hashFn(y) / 2;
	Position* startPositionCpy = new Position(*startPosition);
	switch (getColourId())
	{
		case 1:
		{
			nextPositions.merge(toFirstStepPosition(startPositionCpy, piecePosHash, x, y, x + 2, y + 2, x + 1, y + 1));
			delete startPositionCpy;
			startPositionCpy = new Position(*startPosition);
			nextPositions.merge(toFirstStepPosition(startPositionCpy, piecePosHash, x, y, x - 2, y + 2, x - 1, y + 1));
			break;
		}
		case 2:
		{
			nextPositions.merge(toFirstStepPosition(startPositionCpy, piecePosHash, x, y, x + 2, y + 2, x + 1, y + 1));
			delete startPositionCpy;
			startPositionCpy = new Position(*startPosition);
			nextPositions.merge(toFirstStepPosition(startPositionCpy, piecePosHash, x, y, x + 2, y - 2, x + 1, y - 1));
			break;
		}
		case 3:
		{
			nextPositions.merge(toFirstStepPosition(startPositionCpy, piecePosHash, x, y, x + 2, y - 2, x + 1, y - 1));
			delete startPositionCpy;
			startPositionCpy = new Position(*startPosition);
			nextPositions.merge(toFirstStepPosition(startPositionCpy, piecePosHash, x, y, x - 2, y - 2, x - 1, y - 1));
			break;
		}
		case 4:
		{		
			nextPositions.merge(toFirstStepPosition(startPositionCpy, piecePosHash, x, y, x - 2, y + 2, x - 1, y + 1));
			delete startPositionCpy;
			startPositionCpy = new Position(*startPosition);
			nextPositions.merge(toFirstStepPosition(startPositionCpy, piecePosHash, x, y, x - 2, y - 2, x - 1, y - 1));
			break;
		}
		default:
		{
			throw (MyBadTypeIdEx("There is no definition for this colour of draught"));
		}
	}
	delete startPositionCpy;

	return nextPositions;
};