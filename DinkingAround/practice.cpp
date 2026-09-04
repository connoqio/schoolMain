#include <iostream>
#include <cmath>
using namespace std;



// int main(){
//     double tempf;
//     cout << "what temperature do you want to convert to celsius?" << endl;
//     cin >> tempf;
//     double tempc = (tempf -32) * 5/9;

//     cout << tempc;

//     return 0;

// };


int main(){
    double x1, x2, y1, y2 = 0;
    cout << "enter the coordinates of the first point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "enter the coordinates of the second point (x2 y2): ";
    cin >> x2 >> y2;

    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "the distance between the two points is: " << distance << endl;

    return 0;
}