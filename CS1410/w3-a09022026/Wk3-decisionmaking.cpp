#include <iostream>
using namespace std;

int main(){

    int num1 = 10;

    int num2 = 20;
    {
        int num1 = 33;
        cout << "Number 1 inside of the curly braces is: " << num1 << endl;
    }

    cout << "Number 1 is: " << num1 << endl;
    cout << "Number 2 is: " << num2 << endl;

    return 0;

}