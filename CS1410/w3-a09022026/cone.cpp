/*Connor is incharge of this program that calculates the volume and the surface area of a cone
I just got done with the roots part of this assignment

*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double V, S, r, h; 
    
    cout << "Enter the radius of the cone: "; //this gets input from the user for the radius and height of the cone
    cin >> r;
    cout << "Enter the height of the cone: ";
    cin >> h;

    V = (1.0 / 3.0) * M_PI * r * r * h; // this does the math to get the volume
    S = M_PI * r * sqrt( r * r + h * h) + M_PI * r * r;
    cout << "the volume of the cone is : " << V << endl << "the surface are of the cone is : " << S;



}