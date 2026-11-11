/*

week 11
Constructors: special functions that are not called by you
means called automatically when an object is created 

constructors do not have a return type

it is used to initialize data members

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point {

public:
    // Point() {
    //     x = -11;
    //     y = -22;
    // }
    void ShowthePoint() {
        cout << "[x, y] = " << "[" << x << ", " << y << "]" << endl;
    }

    // Point(double a, double b) {
    //     x = a;
    //     y = b;
    // }
   //Point(double a, double b): x(a), y(b) {}

   Point(double a = 0, double b = 0) {
    x = a;
    y = b;
   }

    void SetPoint(double inX, double inY) {
        x = inX;
        y = inY;
    }

    private:
        double x;
        double y;

};


int main() {

    int val = 10;
    double gpa = 3.999;

    Point p1, p2;
    Point p3(10, 10);

    vector<Point> pts(10);

    p1.SetPoint(2.5, 2);
    p2.SetPoint(5, 5);

    cout << "Display point 1: " << endl;
    p1.ShowthePoint();

    cout << "Display point 2: " << endl;
    p2.ShowthePoint();


    for(Point p: pts)
        p.ShowthePoint();

    cout << endl;
    return 0;
}