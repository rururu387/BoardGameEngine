#pragma once
#include "RGBColour.h"
#include <string>

class Player
{
	int colourId;
	std::string name;
	RGBColour* pieceColour;
	double points;
public:
	Player(int _colourId, std::string _name, RGBColour* _pieceColour, double _points);
	Player(Player &player);
	~Player();
	int getColourId() { return colourId; };
	std::string getName() { return name; };
	RGBColour* getRGB() { return pieceColour; };
	double getPoints() { return points; };
	void setPoints(double _points) { points = _points; };
};