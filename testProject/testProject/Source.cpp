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
/*#include "Windows.h"
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
}*/

/*#include <iostream>
#include <map>

using namespace std;

int main()
{
	std::map<int, char> myMap;
	myMap[0] = 'a';
	myMap.erase(myMap.end());
	std::cout << myMap[0];

	return 0*/

/*#include <functional>
#include <iostream>

int main()
{
	std::hash<int> hashFn;
	std::hash<int> hashFn2;
	int a = 5;
	std::cout << hashFn(a) << '\t' << hashFn2(a);
	return 0;
}*/

/*#include <iostream>
#include "../../Basic Dependencies/CircleQueueNode.h"
#include "../../Basic Dependencies/CircleQueue.h"

int main()
{
	CircleQueue<int>* queue = new CircleQueue<int>();
	int* a = new int(5);
	queue->addElement(0, a);
	int* b = new int(10);
	queue->addElement(1, b, 1);
	int* c = new int(7);
	queue->addElement(1, c, 1);
	int* d = new int(11);
	queue->addElement(1, d, 1);
	queue->removeElement(3, 1);
	queue->print();
	queue->~CircleQueue();
	return 0;
}*/

/*#include <iostream>
#include <map>

int main()
{
	std::multimap<int, char> m;
	m.insert(std::pair<int, char> (1, 'a'));
	m.insert(std::pair<int, char> (1, 'b'));
	m.insert(std::pair<int, char> (1, 'c'));
	auto c = m.equal_range(1);
	for (auto it = c.first; it != c.second; it++)
	{
		std::cout << it->second;
	}
	return 0;
}*/

/*#include "time.h"
#include <iostream>
#include <unordered_set>
#include <string>

int main()
{
	std::unordered_set<int> s1;
	std::unordered_set<int> s2;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		s1.insert(rand() % 100);
	for (auto it = s1.begin(); it != s1.end(); it++)
	{
		s2.insert(*it);
	}
	s1.clear();
	for (auto it = s2.begin(); it != s2.end(); it++)
	{
		std::cout << std::to_string(*it) << " ";
	}
	return 0;
}*/

#include <iostream>
#include <string>
#include "PrintHeader.hpp"

int main()
{
	myPrintEFR();
	return 0;
}