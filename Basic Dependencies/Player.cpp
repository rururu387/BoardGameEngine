#include "Player.h"

Player::Player(Player& player)
{
	colourId = player.getColourId();
	name = player.getName();
	pieceColour = new RGBColour(*(player.getRGB()));
	points = player.getPoints();
}

Player::~Player()
{
	delete pieceColour;
}

Player::Player(int _colourId, std::string _name, RGBColour* _pieceColour, double _points)
{
	colourId = _colourId;
	name = _name;
	pieceColour = _pieceColour;
	points = _points;
}