#ifndef SHAPES_H
#define SHAPES_H

#include <string>
using namespace std;

class Shape {
public:
	Shape();
	Shape(string sName, string sColor);

	string getName();
	void setName(string);
	string getColor();
	void setColor(string);
	virtual string display();
	//Add a Pure Virtual Function in Shape Class - calculateArea() and implement calculateArea() for each shape.
	virtual double calculateArea() { return calculateArea(); };
protected:
	string name;
	string color;

private:
};

class Rectangle : public Shape {
public:
	Rectangle();
	Rectangle(string rName, string rColor, int rWidth, int rHeight);
	int getWidth();
	void setWidth(int rWidth);
	int getHeight();
	void setHeight(int rHeight);
	double calculateArea() override;
	string display() override;
private:
	int width;
	int height;
	double area;
};

class Circle : public Shape {
public:
	Circle();
	Circle(string cName, string cColor, int cRadius);
	int getRadius();
	void setRadius(int);
	//Add a Pure Virtual Function in Shape Class - calculateArea() and implement calculateArea() for each shape.
	double calculateArea() override;
	string display() override;

	
private:
	int radius;
	double area;
};

//Add Triangle shape to the program, with height and width.
//Change from "int" to "double" for height, width, radius, etc.
class Triangle: public Shape {
public:
	Triangle();
	Triangle(string tName, string tColor, double tBase, double tHeight);
	double getBase();
	void setBase(double);
	double getHeight();
	void setHeight(double);
	//Add a Pure Virtual Function in Shape Class - calculateArea() and implement calculateArea() for each shape.
	double calculateArea() override;
	string display() override;

private:
	double base;
	double height;
	double area;
	
};

#endif 
