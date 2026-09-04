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
    double farenheit = 0;
    double celcius = 0;

    cout << "what temperature do you want to convert to celsius?" << endl;
    cin >> farenheit;

    celcius = 5 / 9 * (farenheit - 32);
    cout << "the celsius temperature is: " << celcius << endl;

    return 0;
}