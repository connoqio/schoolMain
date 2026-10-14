/*
A1 A2 A3 A4 A5
B1 B2 B3 B4 B5
C1 C2 C3 C4 C5
D1 D2 D3 D4 D5
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

    const int NUM_REC = 2;
    // vector<string> names(NUM_REC);
    // vector<int> phoneNum(NUM_REC);
    // vector<string> company(NUM_REC);

    vector<string> names;
    vector<int> phoneNum;
    vector<string> company;
    
    int count = 0;

    cout << "Enter the size of collection: ";
    cin >> count;
    cin.ignore();

    names.resize(count);
    phoneNum.resize(count);
    company.resize(count);


    cout << "\n POPULATE DATA: " << endl;
    for (int i = 0; i < names.size(); i++){

        cout << "Enter name: ";
        getline(cin, names.at(i));

        cout << "\nEnter phone number: ";
        cin >> phoneNum.at(i);
        cin.ignore();

        cout << "Enter company: ";
        getline(cin, company.at(i));
    }

    cout << "\n DISPLAY DATA: " << endl;
    for (int i = 0; i < names.size(); i++){
        cout << "Name: " << names.at(i) << endl;
        cout << "Phone Number: " << phoneNum.at(i) << endl;
        cout << "Company: " << company.at(i) << endl;
    }



    // for(int r = 0; r < 4; r++){
    //     for(int c = 0; c < 5; c++){
    //         cout << char('A' + r) << (c + 1) << " ";
    //     }
    //     cout << endl;
    // }
    cout << endl;
    return 0;
}