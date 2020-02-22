#pragma once

int getUnsignedIntFromStream(std::istream& stream)
{
	char a;
	stream.get(a);
	int result = 0;
	if (!std::isdigit(a))
	{
		throw (std::invalid_argument("Couldn't get integer from stream =("));
	}
	while (std::isdigit(a))
	{
		result *= 10;
		result += a - '0';
		stream.get(a);
	}
	stream.unget();
	return result;
}

int getIntFromStream(std::istream &stream)
{
	int result = 0;
	char a;
	stream.get(a);
	bool isNegative = 0;
	if (a == '-')
	{
		isNegative = 1;
	}
	else
	{
		stream.unget();
	}
	result = getUnsignedIntFromStream(stream);
	if (isNegative)
	{
		result *= -1;
	}
	return result;
}

double myCeil(double num)
{
	double round = 1;
	for (int i = 0; floor(num) != 0; i++)
	{
		num /= 10;
		round *= 10;
	}
	return round;
}

double getDoubleFromStream(std::istream& stream)
{
	double result = getIntFromStream(stream);
	char a;
	stream.get(a);
	if (a == '.')
	{
		int fractional = getUnsignedIntFromStream(stream);
		result += fractional / myCeil(fractional);
	}
	else
	{
		stream.unget();
	}
	return result;
}