/*
data types
arithmetic operators

*/

#include <iostream>
using namespace std;

int main() {
    double exam1;
    double exam2;
    double exam3;

    cout << "Enter exam score 1: "; // prompts user to enter the first exam score
    cin >> exam1; // gets user input for the three exam scores
    cout << "Enter exam score 2: "; // prompts user to enter the second exam score
    cin >> exam2; // gets user input for the three exam scores
    cout << "Enter exam score 3: "; // prompts user to enter the third exam score
    cin >> exam3; // gets user input for the three exam scores
    cout << "The scores you entered are: " << exam1 << ", " << exam2 << ", " << exam3 << endl; // prints out the scores that were entered
    cout << "Your average score is: " << (exam1 + exam2 + exam3) / 3.0 << endl; // calculates the average score and prints it out

    return 0;
};