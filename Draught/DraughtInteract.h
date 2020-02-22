#pragma once

Draught* anyToDraught(std::any* piece)
{
	Draught* draught = new Draught(std::any_cast<Draught>(*piece));
	return draught;
}

std::vector<Position*> toNextPositions(std::any* _draught, Position* startPosition)
{
	std::vector<Position*> nextPositions;
	Draught* draught = anyToDraught(_draught);
	if (draught->getColourId() == 1)
	{
		Position* nextPosition = new Position(*startPosition);
		try
		{
			Square* s = startPosition->getField()->searchSquare(draught->getPosition()->getY() + 2, draught->getPosition()->getX() + 2);

			try
			{
				nextPosition->getPieceMap().at(draught->getPosition()->getY() + 1).at(draught->getPosition()->getX() + 1);
				nextPosition->getPieceMap().at(draught->getPosition()->getY() + 1).erase(draught->getPosition()->getX() + 1);
			}
			catch (std::out_of_range ex)
			{}

			std::any_cast<Piece>(nextPosition->getPieceMap().at(draught->getPosition()->getY()).at(draught->getPosition()->getX()).first)->setPosition(s);
			nextPositions.push_back(nextPosition);
		}
		catch (std::out_of_range ex)
		{
		}

		nextPosition = new Position(*startPosition);
		try
		{
			Square* s = startPosition->getField()->searchSquare(draught->getPosition()->getY() + 2, draught->getPosition()->getX() - 2);

			try
			{
				nextPosition->getPieceMap().at(draught->getPosition()->getY() + 1).at(draught->getPosition()->getX() - 1);
				nextPosition->getPieceMap().at(draught->getPosition()->getY() + 1).erase(draught->getPosition()->getX() - 1);
			}
			catch (std::out_of_range ex)
			{
			}

			std::any_cast<Piece>(nextPosition->getPieceMap().at(draught->getPosition()->getY()).at(draught->getPosition()->getX()).first)->setPosition(s);
			nextPositions.push_back(nextPosition);
		}
		catch (std::out_of_range ex)
		{
		}
	}

	if (draught->getColourId() == 2)
	{
		Position* nextPosition = new Position(*startPosition);
		try
		{
			Square* s = startPosition->getField()->searchSquare(draught->getPosition()->getY() - 2, draught->getPosition()->getX() + 2);

			try
			{
				nextPosition->getPieceMap().at(draught->getPosition()->getY() - 1).at(draught->getPosition()->getX() + 1);
				nextPosition->getPieceMap().at(draught->getPosition()->getY() - 1).erase(draught->getPosition()->getX() + 1);
			}
			catch (std::out_of_range ex)
			{
			}

			std::any_cast<Piece>(nextPosition->getPieceMap().at(draught->getPosition()->getY()).at(draught->getPosition()->getX()).first)->setPosition(s);
			nextPositions.push_back(nextPosition);
		}
		catch (std::out_of_range ex)
		{
		}

		nextPosition = new Position(*startPosition);
		try
		{
			Square* s = startPosition->getField()->searchSquare(draught->getPosition()->getY() - 2, draught->getPosition()->getX() - 2);

			try
			{
				nextPosition->getPieceMap().at(draught->getPosition()->getY() - 1).at(draught->getPosition()->getX() - 1);
				nextPosition->getPieceMap().at(draught->getPosition()->getY() - 1).erase(draught->getPosition()->getX() - 1);
			}
			catch (std::out_of_range ex)
			{
			}

			std::any_cast<Piece>(nextPosition->getPieceMap().at(draught->getPosition()->getY()).at(draught->getPosition()->getX()).first)->setPosition(s);
			nextPositions.push_back(nextPosition);
		}
		catch (std::out_of_range ex)
		{
		}
	}
	delete draught;
	return nextPositions;
};