#pragma once
#define __declspec myExtern

class Draught : public Piece
{
	static double price;
	static std::vector<Draught> pieceStart;
public:
	std::vector<Piece*> getStartPosition(std::fstream &in);
	void setPrice(double _price) { price = _price; };
	double getPrice() const override { return price; };
	Draught(int _colourId, int _x, int _y);
	Draught(int _colourId, Square* _piecePosition);
	Draught(const Draught& draught);
};

std::vector<Piece*> Draught::getStartPosition(std::fstream& in)
{
	std::vector<Piece*> pieceStart;
	findPieceInStartPosFile(in);
	char a = ' ';
	in.ignore(2);
	price = getDoubleFromStream(in);
	while (!in.eof() && a != ';')
	{
		char a;
		in.get(a);
		while (a != '(' && a != ';' && !in.eof())
			in.get(a);

		char b = in.get();
		for (int cnt = 0; cnt < 2 && !std::isdigit(b); cnt++)
			b = in.get();
		in.unget();
		int colourId = getIntFromStream(in);

		b = in.get();
		for (int cnt = 0; cnt < 2 && !std::isdigit(b); cnt++)
			b = in.get();
		in.unget();
		int x = 0;
		try
		{
			x = getIntFromStream(in);
		}
		catch (std::invalid_argument e)
		{
			std::string errorExplanation = e.what();
			throw std::invalid_argument(errorExplanation + "There is a misteak in a start position file\n");
		}

		b = in.get();
		for (int cnt = 0; cnt < 2 && !std::isdigit(b) && !in.eof(); cnt++)
			b = in.get();
		in.unget();

		int y = 0;
		try
		{
			y = getIntFromStream(in);
		}
		catch (std::invalid_argument e)
		{
			std::string errorExplanation = e.what();
			throw std::invalid_argument(errorExplanation + "There is a misteak in a start position file\n");
		}
		pieceStart.push_back(reinterpret_cast<Piece*>(new Draught(colourId, x, y)));
		b = in.get();
		for (int cnt = 0; cnt < 2 && b != ')' && !in.eof(); cnt++)
			b = in.get();
		if (b != ')')
		{
			throw (std::invalid_argument("Place symbol(s) ')' correctly"));
		}
		b = in.get();

		for (int cnt = 0; cnt < 2 && b != ';' && !in.eof(); cnt++)
			b = in.get();
		if (b != ';')
		{
			throw (std::invalid_argument("Place symbol(s) ';' correctly"));
		}
	}
	return pieceStart;
}

Draught::Draught(int _colourId, int _x, int _y) : Piece("Draught", _colourId, new Square(_x, _y))
{}

Draught::Draught(const Draught& draught) : Piece(draught)
{
	price = draught.getPrice();
}

Draught::Draught(int _colourId, Square* _piecePosition) : Piece("Draught", _colourId, _piecePosition)
{}