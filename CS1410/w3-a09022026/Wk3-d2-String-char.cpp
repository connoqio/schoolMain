/*
string is a class
in order to represent text data there are two options
1: charater array char fname[2] = "connor"
2: use the string class
    string fname = "connor"; indicies go from 0 to length - 1
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    string fname = "connor"; // fname is a string object
    string lname;

    cout << "Enter the last name: ";
    // cin >> lname;
    getline(cin, lname);

    string fullName = fname + " " + lname;
    cout << "\nMy full name is: " << fullName << endl;

    cout << fullName.at(1) << endl;
    cout << fullName.at(8) << endl;

    cout << fullName.size() << endl;
    cout << fname.length() << endl;

    cout << fullName. substr(0, 3) << endl;

    char fname1[6] = "james"; // C-string

    cout << "c-string -- " << fname1 << endl;

    cout << fname1[1] << ' ' << fname1[3] << endl;

    char c = fname[4];
    cout << "what is c: " << c << endl;






    return 0;
}