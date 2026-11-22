/*
Name: Connor Okey
Date: nov. 20
Project: Programming Project 8 (Inheritance)
Description: (write 1 or 2 sentences about what your program does)

Week 14
zyBooks Chapter 10: Inheritance
*/

#include <iostream>
#include <string>

using namespace std;

// Pure virtual class, aka Abstract class
class Shape
{
	string name;
public:
	Shape(string n) : name(n) { }

	string GetName() { return name; }
	void SetName(string n) { name = n; }

	virtual double GetArea() = 0;
};

class Circle : public Shape
{
	double radius;

public:
	Circle(string n, double r) : Shape(n), radius(r) { }

	void SetRadius(double r) { radius = r; }
	double GetRadius() const { return radius; }

	double GetArea()
	{
		return 3.14159 * radius * radius;
	}
};

class Rectangle : public Shape
{
	double length;
	double width;

public:
	Rectangle(string n, double l, double w) : Shape(n), length(l), width(w) { }

	void SetLength(double l) { length = l; }
	void SetWidth(double w) { width = w; }

	double GetLength() const { return length; }
	double GetWidth() const { return width; }

	double GetArea() { return  length * width; }
};

class Triangle : public Shape
{
	double base;
	double height;

public:

	Triangle(string n, double b, double h) : Shape(n), base(b), height(h) { }

	void SetBase(double b) { base = b; }
	void SetHeight(double h) { height = h; }

	double GetBase() const { return base; }
	double GetHeight() const { return height; }

	double GetArea() { return  (1 / 2.0 * base * height); }

};

// Circular cylinder
// If you see the hierarchy this class is a grand child
class Cylinder : public Circle
{
	double height;

public:

	Cylinder(string n, double r, double h) : Circle(n, r), height(h) { }

	void SetHeight(double h) { height = h; }

	double GetHeight() const { return height; }

	double GetArea()
	{
		/*
		double temp = Circle::GetArea();
		return   temp * height;
		*/ // OR the below
		return Circle::GetArea() * height;
	}

};

/*
TODO 1: Add the class RectCylinder (a rectangular box shape).
Hint: it inherits from Rectangle, just like Cylinder inherits from Circle.
Hint: add a data member for height, a constructor, SetHeight(), GetHeight(),
and GetArea().
Hint: the constructor takes (string n, double l, double w, double h) and
passes n, l, w to the Rectangle constructor.
Hint: GetArea() returns (area of the rectangle) * height. Use Rectangle::GetArea().
*/
class RectCylinder : public Rectangle {};

/*
TODO 2: Add the class TriPrism (a triangular prism).
Hint: it inherits from Triangle.
Hint: add a data member for depth, a constructor, SetDepth(), GetDepth(),
and GetArea().
Hint: the constructor takes (string n, double b, double h, double d) and
passes n, b, h to the Triangle constructor.
Hint: GetArea() returns (area of the triangle) * depth. Use Triangle::GetArea().
*/


int main()
{
	cout << "Please choose a shape." << endl;
	cout << "Type c or C for Circle" << endl;
	cout << "Type r or R for Rectangle" << endl;
	cout << "Type t or T for Triangle" << endl;
	cout << "Type d or D for Cylinder" << endl;

	/*
	TODO 3: Add two more menu lines, in the same style as the lines above.
	Hint: n or N for RectCylinder
	Hint: p or P for TriPrism
	*/

	char	choice;
	cin >> choice;
	cin.ignore();

	Circle* c = nullptr;
	Rectangle* r = nullptr;
	Triangle* t = nullptr;
	Cylinder* d = nullptr;

	/*
	TODO 4: Declare two more pointers, set to nullptr.
	Hint: one RectCylinder pointer and one TriPrism pointer.
	*/

	// Creating a shape according to user choice
	switch (choice)
	{
	case 'C':
	case 'c':
		c = new Circle("Circle", 2.2);
		break;

	case 'R':
	case 'r':
		r = new Rectangle("Rectangle", 10.0, 5.5);
		break;

	case 'T':
	case 't':
		t = new Triangle("Triangle", 5.5, 10.5);
		break;

	case 'd':
	case 'D':
		d = new Cylinder("Cylinder", 2, 10);
		break;

		/*
		TODO 5: Add two more cases that create the new shapes with new.
		Hint: cases 'n' and 'N' create a RectCylinder; cases 'p' and 'P' create a TriPrism.
		Hint: write the sizes of the test cases right here in the code.
		*/

	default:
		cout << "There is no such choice." << endl;
		break;
	}

	// Displaying the area of the shape selected by the user
	switch (choice)
	{
	case 'C':
	case 'c':
		cout << c->GetName() << ", area: " << c->GetArea() << endl << endl;
		break;

	case 'R':
	case 'r':
		cout << r->GetName() << ", area: " << r->GetArea() << endl << endl;
		break;

	case 'T':
	case 't':
		cout << t->GetName() << ", area: " << t->GetArea() << endl << endl;
		break;

	case 'd':
	case 'D':
		cout << d->GetName() << ", area: " << d->GetArea() << endl << endl;
		break;

		/*
		TODO 6: Add two more cases that print the name and area of the new shapes.
		Hint: copy the pattern of the case just above.
		*/

	default:
		cout << "There is no such choice." << endl;
		break;
	}

	cout << endl;
	return 0;
}
