/*
This is Connor's program on calculating the roots of a quadratic equation
today is currently 09/07/2026, labor day, me and austin just got back from winco buying candy.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, x1, x2;
    cout << "Enter the value for a: ";
    cin >> a;
    cout << "Enter the value for b: ";
    cin >> b;
    cout << "Enter the value for c: ";
    cin >> c;

    x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

    cout << "x1 is equal to : " << x1 << endl;
    cout << "x2 is equal to : " << x2 << endl;

    return 0;
}