#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point {

public:

    Point(double a, double b): x(a), y(b) {}

    Point(): x(0), y(0){}

    void ShowthePoint() {
        cout << "[x, y] = " << "[" << x << ", " << y << "]" << endl;
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

    int a = 12;

    double gpa = 2;

    char ch = 'z';

    Point p1(3, 3);
    Point p2(5, 5);


    cout << endl;
    return 0;
}