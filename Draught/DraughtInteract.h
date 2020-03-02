#pragma once

Position* Draught::toNextPosition(Position* startPosition, int piecePosHash, std::map<int, Piece*> pieceMap, int moveToX, int moveToY, int xEaten, int yEaten)
{
	std::hash<int> hashFn;
	std::map<int, Square*>::iterator posIt = startPosition->getField()->searchSquare(moveToX, moveToY);
	std::map<int, Square*>::iterator endIt = startPosition->getField()->getFieldEnd();
	std::map<int, Piece*>::iterator pieceInterfere = pieceMap.find(hashFn(moveToY) / 2 + (hashFn(moveToX) / 2));

	if (posIt != endIt && pieceInterfere == pieceMap.end())
	{
		Position* nextPosition = new Position(*startPosition);
		std::map<int, Piece*>::iterator pieceEaten = pieceMap.find(hashFn(xEaten) / 2 + (hashFn(yEaten) / 2));
		if (pieceEaten != pieceMap.end())
		{
			pieceMap.erase(pieceEaten);
		}
		auto pieceTemp = pieceMap.extract(piecePosHash);
		pieceTemp.key = hashFn(moveToX) / 2 + (hashFn(moveToY) / 2);
		pieceMap.insert(std::move(pieceTemp));
		setPosition(moveToX, moveToY);
		return nextPosition;
	}
	return NULL;
}

std::unordered_set<Position*> Draught::toNextPositions(Position* startPosition)
{
	std::unordered_set<Position*> nextPositions;
	int x = getPosition()->getX();
	int y = getPosition()->getY();
	std::hash<int> hashFn;
	int piecePosHash = hashFn(x) / 2 + hashFn(y) / 2;
	std::map<int, Piece*> pieceMap = startPosition->getPieceMap();
	Position* nextPosition = NULL;

	switch (getColourId())
	{
		case 1:
		{
			nextPosition = toNextPosition(startPosition, piecePosHash, pieceMap, x + 2, y + 2, x + 1, y + 1);
			if (nextPosition != NULL)
			{
				nextPositions.insert(nextPosition);
			}
			nextPosition = toNextPosition(startPosition, piecePosHash, pieceMap, x - 2, y + 2, x - 1, y + 1);
			if (nextPosition != NULL)
			{
				nextPositions.insert(nextPosition);
			}
			break;
		}
		case 2:
		{
			nextPosition = toNextPosition(startPosition, piecePosHash, pieceMap, x + 2, y - 2, x + 1, y - 1);
			if (nextPosition != NULL)
			{
				nextPositions.insert(nextPosition);
			}
			nextPosition = toNextPosition(startPosition, piecePosHash, pieceMap, x + 2, y + 2, x + 1, y + 1);
			if (nextPosition != NULL)
			{
				nextPositions.insert(nextPosition);
			}
			break;
		}
		case 3:
		{
			nextPosition = toNextPosition(startPosition, piecePosHash, pieceMap, x + 2, y - 2, x + 1, y - 1);
			if (nextPosition != NULL)
			{
				nextPositions.insert(nextPosition);
			}
			nextPosition = toNextPosition(startPosition, piecePosHash, pieceMap, x - 2, y - 2, x - 1, y - 1);
			if (nextPosition != NULL)
			{
				nextPositions.insert(nextPosition);
			}
			break;
		}
		case 4:
		{
			nextPosition = toNextPosition(startPosition, piecePosHash, pieceMap, x - 2, y - 2, x - 1, y - 1);
			if (nextPosition != NULL)
			{
				nextPositions.insert(nextPosition);
			}
			nextPosition = toNextPosition(startPosition, piecePosHash, pieceMap, x - 2, y - 2, x - 1, y - 1);
			if (nextPosition != NULL)
			{
				nextPositions.insert(nextPosition);
			}
			break;
		}
	}
	return nextPositions;
};