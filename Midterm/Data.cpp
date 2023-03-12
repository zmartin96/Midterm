#include "Data.h"
#include <vector> //using an array did not fix the problem

Data::Data(const string& inFileName, const string& outFileName)
{
    int i=0;
    inFile.open(inFileName);
    outFile.open(outFileName);

    if (!inFile) throw string("The file in could not be opened!\n\n");
    if (!outFile) throw string("The file out could not be opened!\n\n");

    vector<Shape*> shapes; //new vector of shapes
    //said "vector subscript is out of range" but still threw an
    //exception when I switched to arrays
    //using smart pointers had no noticable effect

    while (!inFile.fail())
    {
        //This is where I was getting an error when running
		//old code: "shapes[i]=this->readData(i);"
		//I forgot to use push_back
		shapes.push_back(this->readData(i));
        
        i++;
    }
    for (int j = 0; j < i-1; j++)
    {
        outFile << "Area: " << shapes[j]->getArea()
            << "\tPerimeter: " << shapes[j]->getPerimeter()
            << endl;
    }
    //this->outFile << "Area: " << r->getArea() << "\tPerimeter: " << r->getPerimeter();

    inFile.close();
    outFile.close();
}

Shape* Data::readData(int i)
{
    if (i % 2 == 0||i==0) //is even
    {
        Rectangle* r = new Rectangle;
        inFile >> *r; //switching overloaded insertion operator to use pointers yielded the same error
        return r;
    }
    else // is odd
    {
        Circle* c = new Circle;
        inFile >> *c;
        return c;
    }
    //throw string("There was an error reading the data\n"); //didn't throw
}
