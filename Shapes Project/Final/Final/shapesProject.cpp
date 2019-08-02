#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include "shapes.h"

using namespace std;
void redrawShape();
void writeToFile();

vector<Shape *> shapeList;
Shape * shapePtr;
fstream shapefile;

void main() {
	string inString1, inString2;
	float inValue1, inValue2;
	double doubleValue1, doubleValue2;
	int choice;
	Rectangle * rectPtr;
	Circle * cirPtr;
	Triangle * triPtr;
	string line;

	cout << "*** Welcome to Shapes program ***\n";

	do {
		cout << "\nMenu for entering shape:\n";
		cout << "1: To enter a rectangle\n";
		cout << "2: To enter a circle\n";
		cout << "3: To enter a triangle\n";
		cout << "4: To delete last entered shape\n";
		cout << "5: To display all shapes\n";
		cout << "90: Read shapes from file (input.txt)\n";
		cout << "91: Save shapes to file (output.txt)\n";
		cout << "92: Create save file (output.txt)\n";
		cout << "99: Finish.\n";
		cout << "Please enter your choice (#): ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Rectangle Name: ";
			cin >> inString1;
			cout << "Rectangle Color: ";
			cin >> inString2;
			cout << "Rectangle Width: ";
			cin >> inValue1;
			cout << "Rectangle Height: ";
			cin >> inValue2;
			rectPtr = new Rectangle(inString1, inString2, inValue1, inValue2);
			shapeList.push_back(rectPtr);
			break;
		case 2:
			cout << "Circle Name: ";
			cin >> inString1;
			cout << "Circle Color: ";
			cin >> inString2;
			cout << "Circle Radius: ";
			cin >> inValue1;
			cirPtr = new Circle(inString1, inString2, inValue1);
			shapeList.push_back(cirPtr);
			break;
		case 3:
			cout << "Triangle Name: ";
			cin >> inString1;
			cout << "Triangle Color: ";
			cin >> inString2;
			cout << "Triangle Base: ";
			cin >> doubleValue1;
			cout << "Triangle Height: ";
			cin >> doubleValue2;
			triPtr = new Triangle(inString1, inString2, doubleValue1, doubleValue2);
			shapeList.push_back(triPtr);
			break;
		case 4:
			//Add option in user menu to delete last entered shape
			shapeList.pop_back();
			break;
		case 5:
			if (shapeList.size()) redrawShape();
			break;
		case 90:
			//Add option in user menu to read shapes from file
			shapefile.open("shapes.txt");
			while (getline(shapefile, line))
			{
				cout << line << endl;
			}
			shapefile.close();
			
			break;
		case 91:
			//Add option in user menu to output shapes to file
			shapefile.open("shapes.txt");

			writeToFile();

			shapefile.close();
			break;

		case 92:
			ofstream shapefile;
			shapefile.open("shapes.txt");
			shapefile.close();
			break;
		}


	} while (choice != 99);

	cout << "\nThank you for using this program.\n\n";
	system("pause");

}

//Change redrawShape() function to use iterator, instead of using "int i" to index into the vector of shapeList.
void redrawShape() {

	cout << "\nThese are the shapes: " << endl;
	for (vector<Shape *>::iterator it = shapeList.begin(); it != shapeList.end();it++) 
	{
		shapePtr = *it;
		cout<<shapePtr->display();
	}

}
//Add option in user menu to output shapes to file
void writeToFile()
{
	
	for (vector<Shape *>::iterator it = shapeList.begin(); it != shapeList.end(); it++)
	{
		shapePtr = *it;
		shapefile << shapePtr->display();
	}
}

