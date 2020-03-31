#pragma once

class RGBColour
{
	int red;
	int green;
	int blue;
public:
	int getRed() { return red; };
	int getGreen() { return green; };
	int getBlue() { return blue; };
	void setRed(int _red) { red = _red; };
	void setGreen(int _green) { green = _green; };
	void setBlue(int _blue) { blue = _blue; };
	RGBColour(int _red, int _green, int _blue) { red = _red; green = _green; blue = _blue; };
	RGBColour(RGBColour& colour) { red = colour.getRed(); green = colour.getGreen(); blue = colour.getBlue(); };
	std::string to_string() { return "Red: " + std::to_string(red) + ", Green: " + std::to_string(green) + ", Blue: " + std::to_string(blue); };
};
