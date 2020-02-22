#pragma once

#include <fstream>
#include <string>
#include "../Basic Dependencies/CorrectStreamInput.h"

void transformFile(std::ifstream &in)
{
	std::ofstream out;
	out.open("transformedStartingFile.h", std::ofstream::out | std::ofstream::trunc);

	while (!in.eof())
	{
		if (in.get() == '>')
		{
			std::string pieceName = "";
			char a = in.peek();
			while (a != ' ' && a != '\n' && a != in.eof() && a != ',')
			{
				pieceName += in.get();
				a = in.peek();
			}
			
			in.ignore(2);
			double price = getIntFromStream(in);
			out << pieceName + "::price = " << std::to_string(price) << ";\n";

			a = in.peek();
			int cnt = 0;
			while (a != '>' && !in.eof())
			{
				if (in.peek() == '(')
				{
					in.ignore();
					std::string params = "";
					while (in.peek() != ')')
					{
						params += in.get();
					}
					out << pieceName + " piece" + std::to_string(cnt) + " =  new " + pieceName + '(' + params + ");\n";
					cnt++;
				}
				a = in.get();
			}
			if (a == '>')
				in.unget();
		}
	}
}

int main()
{
	std::ifstream in;
	in.open("../BoardGameEngine/StartingPosition.txt");
	transformFile(in);
	return 0;
}