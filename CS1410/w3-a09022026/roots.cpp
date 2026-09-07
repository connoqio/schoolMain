/*
This is Connor's program on calculating the roots of a quadratic equation
today is currently 09/07/2026, labor day, me and austin just got back from winco buying candy.
this took about 15ish minutes to write.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, x1, x2;
    cout << "Enter the value for a: "; //this gets input from the user for the value of a, b, and c
    cin >> a;
    cout << "Enter the value for b: ";
    cin >> b;
    cout << "Enter the value for c: ";
    cin >> c;

    x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a); // this part does the math to calculate the roots of the quadratic equation using the quadratic formula
    x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

    cout << "x1 is equal to : " << x1 << endl;
    cout << "x2 is equal to : " << x2 << endl; //this prints the output of the roots

    return 0;
}