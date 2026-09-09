/*this is connors calculator
today is 9/8/26
This program gets input from the user and allows the user to pick what math operation they want to use
and the program prints the output*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x, y;
    double result = 999999;
    char userChoice = 'x';

    // this gets the numbers from the user
    cout << "Please enter number 1: ";
    cin >> x;
    cout << "Please enter number 2: ";
    cin >> y;

    cout << "please enter your choice of math: " << endl;
    cout << "a or A or + for addition " << endl;
    cout << "s or S or - for subtraction" << endl;
    cout << "m or M or * for multiplication" << endl;
    cout << "d or D or / for division" << endl;

    cin >> userChoice; //gets the opperand for the calculator

    //this if else statement takes the input the user gave and the executes the code accordingly
    switch(userChoice){
    case 'a':
    case 'A':
    case '+':
        result = x + y;
        break;
    case 's':
    case 'S':
    case '-':
            result = x - y;
        break;
    case 'm':
    case 'M':
    case '*':
            result = x * y;
        break;
    case 'd':
    case 'D':
    case '/':
            result = x / y;
        break;
    default:
        cout << "Not a valid choice." << endl;
    }
    cout << "The result is: " << result << endl;
    
    return 0;
}