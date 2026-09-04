#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    double length1, width1, height1, length2, width2, height2;
    cout << "enter the dimensions of the first box: (length, width, height)"  << endl;
    cin >> length1 >> width1 >> height1;

    cout << "enter the dimensions of the second box: (length, width, height)" << endl;
    cin >> length2 >> width2 >> height2;

    double volume1 = length1 * width1 * height1;
    double volume2 = length2 * width2 * height2;
    double totalVol = volume1 + volume2;
    cout << "the total volume of the two boxes is: " << fixed << setprecision(2) << totalVol << endl;
    return 0;
}