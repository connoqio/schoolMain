/*

*/
#include <iostream>
#include <vector>
#include <string>

#include "BasicMath.h"

using namespace std;

void DisplayNames(vector<string> names){
    for (string n: names){
        cout << n << endl;
    }
}

int main(){

    int a = 12;
    int b = 13;

    double rad = 1.1;
    double len = 10;
    double w = 2.2;

    cout << "sum of ints: " << Add(a, b) << endl;
    cout << "sum of real values: " << Add(a, b, 3.3) << endl;
    cout << "area of circle: " << Area(rad) << endl;
    cout << "area of rectangle: " << Area(len, w) << endl;

    vector<string> list = {"bob", "dwight", "sara"};
    cout << "\nDisplay names: " << endl;

    DisplayNames(list);

    cout << endl;
    return 0;
}