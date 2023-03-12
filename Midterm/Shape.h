#include <iostream>
#include <fstream>
#include "Data.h"
#include <cmath>
using namespace std;

class Shape
{
protected:
    double perimeter, area;
public:
    //Shape(const string& inFileName, const string& outFileName);
    static const double PI;
    double getArea() { return this->area; }
    double getPerimeter() { return this->perimeter; }
    virtual void calcPerimeter() = 0;
    virtual void calcArea() = 0;

    //Overloaded stream insertion
    // 
};

//Rectangle class
class Rectangle : public Shape
{
private:
    double length, width;
    virtual void calcPerimeter() override
    {
        this->perimeter = 2 * (this->length + this->width);
    }
    virtual void calcArea() override
    {
        this->area = this->length * this->width;
    }
public:
    friend istream& operator>>(istream& in, Rectangle&);
        //Rectangle(const string& inFileName, const string& outFileName,double l,double w)
        //: Shape(inFileName, outFileName) 
        //{
        //    this->length=l;
        //    this->width = w;
        //}

};

//Circle class
class Circle : public Shape
{
private:
    double radius=0;
    virtual void calcPerimeter() override
    {
        this->perimeter = 2 * this->radius * PI;
    }
    virtual void calcArea() override
    {
        this->area = pow(this->radius, 2) * PI;
    }
public:
    friend istream& operator>>(istream& in, Circle&);
    //Circle(const string& inFileName, const string& outFileName, double r)
    //    : Shape(inFileName, outFileName) 
    //{
    //    this->radius=r;
    //}
};
