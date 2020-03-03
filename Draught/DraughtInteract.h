#pragma once

bool toNextTake(Position* nextPosition, int piecePosHash, std::map<int, Piece*> pieceMap, int moveToX, int moveToY, int xEaten, int yEaten)
{
	std::hash<int> hashFn;
	if (pieceMap.find(hashFn(xEaten) / 2 + (hashFn(yEaten) / 2)) != pieceMap.end())
	{

	}
	std::map<int, Piece*>::iterator curPiece = pieceMap.find(piecePosHash);
}

//To do
std::unordered_set<Position*> Draught::toNextPosition(const Position* startPosition, int piecePosHash, int moveToX, int moveToY, int xEaten, int yEaten)
{
	std::hash<int> hashFn;
	Position* startPositionCpy = new Position(*startPosition);
	std::unordered_set<Position*> nextPosition;
	std::map<int, Square*>::iterator posIt = startPositionCpy->getField()->searchSquare(moveToX, moveToY);
	std::map<int, Square*>::iterator endIt = startPositionCpy->getField()->getFieldEnd();
	std::map<int, Piece*> pieceMap = startPosition->getPieceMap();
	std::map<int, Piece*>::iterator pieceInterfere = pieceMap.find(hashFn(moveToY) / 2 + (hashFn(moveToX) / 2));
	std::map<int, Piece*>::iterator pieceEaten = pieceMap.find(hashFn(xEaten) / 2 + (hashFn(yEaten) / 2));

	if (posIt != endIt && pieceInterfere == pieceMap.end() && (pieceEaten == pieceMap.end() || pieceEaten->second->getColourId() != getColourId()))
	{
		if (pieceEaten != pieceMap.end() && pieceEaten->second->getColourId() != getColourId())
		{
			pieceMap.erase(pieceEaten);
			toNextPosition()
		}
		auto pieceTemp = pieceMap.extract(piecePosHash);
		pieceTemp.key = hashFn(moveToX) / 2 + (hashFn(moveToY) / 2);
		pieceMap.insert(std::move(pieceTemp));

		setPosition(moveToX, moveToY);
		while (toNextTake())
		{}
		while (toNextTake())
		{}
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
	std::unordered_set<Position*> nextPosition;

	switch (getColourId())
	{
		case 1:
		{
			nextPosition = toNextPosition(startPosition, piecePosHash, x + 2, y + 2, x + 1, y + 1);
			nextPositions.merge(nextPosition);
			nextPosition = toNextPosition(startPosition, piecePosHash, x - 2, y + 2, x - 1, y + 1);
			nextPositions.merge(nextPosition);
			break;
		}
		case 2:
		{
			nextPosition = toNextPosition(startPosition, piecePosHash, x + 2, y - 2, x + 1, y - 1);
			nextPositions.merge(nextPosition);
			nextPosition = toNextPosition(startPosition, piecePosHash, x + 2, y + 2, x + 1, y + 1);
			nextPositions.merge(nextPosition);
			break;
		}
		case 3:
		{
			nextPosition = toNextPosition(startPosition, piecePosHash, x + 2, y - 2, x + 1, y - 1);
			nextPositions.merge(nextPosition);
			nextPosition = toNextPosition(startPosition, piecePosHash, x - 2, y - 2, x - 1, y - 1);
			nextPositions.merge(nextPosition);
			break;
		}
		case 4:
		{
			nextPosition = toNextPosition(startPosition, piecePosHash, pieceMap, x - 2, y - 2, x - 1, y - 1);
			nextPositions.merge(nextPosition);
			nextPosition = toNextPosition(startPosition, piecePosHash, pieceMap, x - 2, y - 2, x - 1, y - 1);
			nextPositions.merge(nextPosition);
			break;
		}
	}
	return nextPositions;
};