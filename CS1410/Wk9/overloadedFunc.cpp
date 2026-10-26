/*
overloaded functions
functinos by same name but different parameter lsit
not distinguished by return type
*/

#include <iostream>
#include <string>

#define sqr(x) x * x

using namespace std;

int Add(int a, int b){
    return a + b;
}

double Add(double a, double b, double c){
    return a + b + c;
}

char Add(char c, int a){
    return c + a;
}

double Area(double l, double w, double h = 1){
    return l * w * h;
}

int main() {

    int a = 10;
    int b = 15;
    int isum = Add(a, b);

    cout << "isum is: " << isum << endl;

    int c = 5;
    int add3Val = Add(a, b, c);
    cout << "add3Val is: " << add3Val << endl;

    cout << "add real vals: " << Add(3.3, 1.1, 1) << endl;

    cout << "add char and vals: " << Add('A', 2) << endl;

    cout << "the area of a box is: " << Area(5, 2, 2) << endl;

    cout << "area of 2d object: " << Area(3, 10) << endl;

    cout << "Macro used: " << sqr(10) << endl;

    cout << endl;
    return 0;
}