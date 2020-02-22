#pragma once

std::vector<Position*> Draught::toNextPositions(Position* startPosition)
{
	std::vector<Position*> nextPositions;
	int y = getPosition()->getY();
	int x = getPosition()->getX();
	if (getColourId() == 1)
	{
		Position* nextPosition = new Position(*startPosition);
		try
		{
			Square* s = startPosition->getField()->searchSquare(y + 2, x + 2);

			try
			{
				nextPosition->getPieceMap().at(y + 1).at(x + 1);
				nextPosition->getPieceMap().at(y+ 1).erase(x + 1);
			}
			catch (std::out_of_range ex)
			{}

			std::any_cast<Piece>(nextPosition->getPieceMap().at(y).at(x).first)->setPosition(s);
			nextPositions.push_back(nextPosition);
		}
		catch (std::out_of_range ex)
		{
		}

		nextPosition = new Position(*startPosition);
		try
		{
			Square* s = startPosition->getField()->searchSquare(y + 2, x - 2);

			try
			{
				nextPosition->getPieceMap().at(y + 1).at(x - 1);
				nextPosition->getPieceMap().at(y + 1).erase(x - 1);
			}
			catch (std::out_of_range ex)
			{
			}

			std::any_cast<Piece>(nextPosition->getPieceMap().at(y).at(x).first)->setPosition(s);
			nextPositions.push_back(nextPosition);
		}
		catch (std::out_of_range ex)
		{
		}
	}

	if (getColourId() == 2)
	{
		Position* nextPosition = new Position(*startPosition);
		try
		{
			Square* s = startPosition->getField()->searchSquare(y - 2, x + 2);

			try
			{
				nextPosition->getPieceMap().at(y - 1).at(x + 1);
				nextPosition->getPieceMap().at(y - 1).erase(x + 1);
			}
			catch (std::out_of_range ex)
			{
			}

			std::any_cast<Piece>(nextPosition->getPieceMap().at(y).at(x).first)->setPosition(s);
			nextPositions.push_back(nextPosition);
		}
		catch (std::out_of_range ex)
		{
		}

		nextPosition = new Position(*startPosition);
		try
		{
			Square* s = startPosition->getField()->searchSquare(y - 2, x - 2);

			try
			{
				nextPosition->getPieceMap().at(y - 1).at(x - 1);
				nextPosition->getPieceMap().at(y - 1).erase(x - 1);
			}
			catch (std::out_of_range ex)
			{
			}

			std::any_cast<Piece>(nextPosition->getPieceMap().at(y).at(x).first)->setPosition(s);
			nextPositions.push_back(nextPosition);
		}
		catch (std::out_of_range ex)
		{
		}
	}
	return nextPositions;
};