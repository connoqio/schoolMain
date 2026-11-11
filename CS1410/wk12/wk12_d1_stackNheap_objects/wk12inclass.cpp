#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point {

public:
    //parameterized constructor
    Point(double a, double b): x(a), y(b) {}

    //default constructor
    Point(): x(0), y(0){}

    void ShowthePoint() {
        cout << "[x, y] = " << "[" << x << ", " << y << "]" << endl;
    }

    //setter function
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

    int* ptr = nullptr; //pointer to an int, currently points to nothing
    ptr = &a; //ptr now points to a

    int* hint = new int;

    *hint = 99;

    cout << "show the value of the heap integer: " << *hint << endl; //show the value of the heap integer

    int* bDump = new int[100000]; //seeking space for 100,000 integers on the heap
    (*bDump) = 77777; //assigning value to the first integer in the array

    cout << "bDump starting data: " << *bDump << endl; //show the value of the first integer in the array

    *bDump++; //increment the pointer to point to the next integer in the array
    (*bDump) = 11111;

    cout << "bDump next data: " << *bDump << endl;

    delete hint; //free the memory allocated for the heap integer
    delete[] bDump; //free the memory allocated for the heap array

    cout << "value using a: " << a << endl;
    cout << "value of a using ptr: " << *ptr << endl;

    cout << "value using ptr: " << ptr << endl; // ptr has memory address value
    cout << "Where ptr is: " << &ptr << endl; // where ptr variable residing

    // double gpa = 2;

    // char ch = 'z';

    Point p1(3, 3);
    Point p2(5, 5);


    p1.ShowthePoint();
    p2.ShowthePoint();

    Point* hpt = new Point(-11, 33); //heap object - this point is on the heap
    //address of the point is under stack stored is hpt

    (*hpt).ShowthePoint();
    hpt->ShowthePoint();

    Point *ap = new Point();
    ap->ShowthePoint();

    delete ap; //free the memory allocated for the heap object
    delete hpt; //free the memory allocated for the heap object

    cout << endl;
    return 0;
}