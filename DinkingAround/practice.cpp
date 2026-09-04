#include <iostream>
#include <cmath>
using namespace std;



int main(){
    double tempf;
    cout << "what temperature do you want to convert to celsius?" << endl;
    cin >> tempf;
    double tempc = (tempf -32) * 5/9;

    cout << tempc;

    return 0;

};
