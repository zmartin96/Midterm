#include "Data.h"

//pi
const double Shape::PI = 3.141592653359;

//overloaded stream insertion operator for Rectangle
istream& operator>>(istream& in, Rectangle& a)
{
    in >> a.length;
    in >> a.width;
	a.calcArea();
	a.calcPerimeter();
    //if (a.length == 50 || a.width == 50) throw string("Not Permitted Data Detected.");
    return in;
}

//overloaded stream insertion operator for Circle
istream& operator>>(istream& in, Circle& a)
{
    in >> a.radius;
	a.calcArea();
	a.calcPerimeter();
    if (a.radius == 50) throw string("Not Permitted Data Detected.");
    return in;
}

int main()
{
	string location="/Users/zacharymartin/Documents/XCode Projects/Midterm/Midterm/",
	//		inFileName="inputData.txt",
	//		outFileName="answers.txt";
	 inFileName, outFileName;
	
    try
    {
        cout << "Enter name of the base file to manipulate: ";
        cin >> inFileName;
        cout << "Enter name of file to receive the encrypted text: ";
        cin >> outFileName;
        Data d(location+inFileName, location+outFileName); //files entered fine and try-catch block worked
    }
    
    catch (string s)
    {
        cout<<s;
        exit(-1);
    }
    
    return 0;
}
