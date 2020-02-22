/*#include <iostream>
#include <fstream>
class A
{
public:
	int a;
	A(int _a) { a = _a; };
	virtual void setSixteen() { std::cout << "Goose"; };
	void print() { std::cout << a; };
};

class B : public A
{
public:
	int b;
	B(int _b) : A(_b) { b = _b; };
	void setSixteen() { b = 16; };
	void print() { std::cout << b; };
};

int main()
{
	A* aelem;
	B* belem = new B(2);
	aelem = belem;
	aelem->setSixteen();
	belem->print();
	delete aelem;
}*/

//#include "stdafx.h"
#include "Windows.h"
#include <iostream>
#include <filesystem>

void main()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	LPCWSTR curPath = std::filesystem::current_path().c_str();
	hf = FindFirstFile(curPath, &FindFileData);
	if (hf != INVALID_HANDLE_VALUE)
	{
		do
		{
			std::cout << FindFileData.cFileName << std::endl;
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
}