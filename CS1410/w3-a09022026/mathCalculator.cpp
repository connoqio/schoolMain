/*this is connors calculator
today is 9/8/26
This program gets input from the user and allows the user to pick what math operation they want to use
and the program prints the output*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x, y;
    char userChoice = 'x';

    // this gets the numbers from the user
    cout << "Please enter number 1: ";
    cin >> x;
    cout << "Please enter number 2: ";
    cin >> y;

    cout << "please enter your choice of math: " << endl << "a for addition " << endl << "s for subtraction" 
    << endl << "m for multiplication" << endl << "d for division" << endl;
    cin >> userChoice; //gets the opperand for the calculator

    //this if else statement takes the input the user gave and the executes the code accordingly
    if (userChoice == 'a'){
        cout << "The result is: " << x + y << endl;
    }

    else if (userChoice == 's'){
        cout << "The result is: " << x - y << endl;
    }

    else if (userChoice == 'm'){
        cout << "The result is: " << x * y << endl;
    }

    else if (userChoice == 'd'){
        cout << "The result is: " << x / y << endl;
    }

    return 0;
}