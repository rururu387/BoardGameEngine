#pragma once

class Position
{
	Field* field;
	std::map<int, std::map <int, std::pair <std::any*, std::string>>> pieceMap;
public:
	void getStartPosition(std::fstream &in);
	Position(Field* _field, std::map<int, std::map <int, std::pair <std::any*, std::string>>> _pieceMap);
	Position(Field* _field, std::vector<std::pair <std::any*, std::string>> pieceVector);
	Field* getField() { return field; };
	std::map<int, std::map <int, std::pair <std::any*, std::string>>> getPieceMap() { return pieceMap; };
	~Position();
};

void Position::getStartPosition(std::fstream &in)
{

}

Position::Position(Field* _field, std::map<int, std::map <int, std::pair <std::any*, std::string>>> _pieceMap)
{
	field = _field;
	pieceMap = _pieceMap;
}

Position::Position(Field* _field, std::vector<std::pair <std::any*, std::string>> pieceVector)
{
	field = _field;
	for (std::vector<std::pair <std::any*, std::string>>::iterator it = pieceVector.begin(); it != pieceVector.end(); it++)
	{
		//Load dll and cast 
		Draught* curDraught = myCast(*it);

		pieceMap[curDraught->getPosition()->getY()][curDraught->getPosition()->getX()] = *it;
	}
}

Position::~Position()
{
	for (std::map<int, std::map <int, std::pair <std::any*, std::string>>>::iterator it = pieceMap.begin(); it != pieceMap.end(); it++)
	{
		for (std::map <int, std::pair <std::any*, std::string>>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
			it2->second.first->reset();
	}
}