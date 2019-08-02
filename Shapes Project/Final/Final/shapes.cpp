#include <iostream>
#include <iomanip>
#include <string>
#include "shapes.h"
using namespace std;

Shape::Shape() {}
Shape::Shape(string sName, string sColor) {
	name = sName;
	color = sColor;
}

string Shape::getName() { return name; }
void Shape::setName(string sName) { name = sName; }

string Shape::getColor() { return color; }
void Shape::setColor(string sColor) { color = sColor; }

string Shape::display() {
	return +"\nShape: " + name + " with " + color + " color.";
}

Rectangle::Rectangle() {}
Rectangle::Rectangle(string rName, string rColor, int rWidth, int rHeight)
	: Shape::Shape(rName, rColor)
{
	width = rWidth;
	height = rHeight;
}
int Rectangle::getWidth() { return width; }
void Rectangle::setWidth(int W) { width = W; }
int Rectangle::getHeight() { return height; }
void Rectangle::setHeight(int H) { height = H; }

double Rectangle::calculateArea()
{
	//implement calculateArea() for each shape.
	area = (width * height);
	return area;
}
string Rectangle::display() 
{
	//Enhance display() to include the calculated area
	return + "\nRectangle: " + name + " with " + color + " color, "
		+ "and width = " + to_string(width) + ", height = " + to_string(height) + " and calculated area = " + to_string(calculateArea());
}

Circle::Circle() {}
Circle::Circle(string cName, string cColor, int cRadius)
	: Shape::Shape(cName, cColor) {
	radius = cRadius;
}
int Circle::getRadius() { return radius; }
void Circle::setRadius(int R) { radius = R; }

double Circle::calculateArea()
{
	//implement calculateArea() for each shape.
	area = 3.14*(radius * radius);
	return area;
}
string Circle::display() 

{
	//Enhance display() to include the calculated area
	return + "\nCircle: " + name + " with " + color + " color, "
		+ "and radius = " + to_string(radius) + " and calculated area = " + to_string(calculateArea());
}

Triangle::Triangle() {}
Triangle::Triangle(std::string tName, std::string tColor, double tBase, double tHeight)
	:Shape::Shape(tName, tColor)
{
	base = tBase;
	height = tHeight;

}

double Triangle::getBase() { return base; }
void Triangle::setBase(double tBase) { base = tBase; }
double Triangle::getHeight() { return height; }
void Triangle::setHeight(double tHeight) { height = tHeight; }
double Triangle::calculateArea()
{
	////implement calculateArea() for each shape.
	area = 0.5*(base * height);
	return area;
}
string Triangle::display()
{
	//Enhance display() to include the calculated area
	return + "\nTriangle: " + name + " with " + color + " color, "
		+ "base = " + to_string(base) + ", height = " + to_string(height) + " and calculated area = " + to_string(calculateArea());
}

