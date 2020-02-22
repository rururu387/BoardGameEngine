#pragma once

#define myExport __declspec(dllimport)
extern "C" myExport void helloWorld();

class A : public Basic
{
public:
	double value;
	myExport A(int _variable, double _value);
	myExport std::string print();
};