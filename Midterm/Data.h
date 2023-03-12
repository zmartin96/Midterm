#pragma once
#include "Shape.h"
#include <string>
using namespace std;

class Data
{
private:
	ifstream inFile;
	ofstream outFile;
public:
	Data() {}
	Data(const string& inFileName, const string& outFileName);
	Shape* readData(int i);
};
