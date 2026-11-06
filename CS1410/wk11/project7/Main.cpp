#include <iostream>
#include <string>
#include <iomanip>
#include "Student.h"

using namespace std;

int main()
{
    const int NUM_STUDS = 10;
    Student studs[NUM_STUDS];
    string sName;
    int sID;
    string smajor;
    double sGPA;

    cout << "Populate student info: ";
    cout << "\n========================";

    for (int i = 0; i < NUM_STUDS; i++)
    {
        cout << "\nEnter name: ";
        getline(cin, sName);
        cout << "ID: ";
        cin >> sID;
        cin.ignore();
        cout << "Enter major: ";
        getline(cin, smajor);
        cout << "Enter GPA: ";
        cin >> sGPA;
        cin.ignore();
        
        studs[i].SetName(sName);
        studs[i].SetID(sID);
        studs[i].SetMajor(smajor);
        studs[i].SetGPA(sGPA);
    }

    cout << "=================================================" << endl;
    cout << "|Name            |ID|Major           |OverallGPA|" << endl;
    cout << "=================================================" << endl;


    for (int i = 0; i < NUM_STUDS; i++)
    {
        cout << "|" << left << setw(16) << studs[i].GetName() 
             << "|" << left << setw(2)  << studs[i].GetID()
             << "|" << left << setw(16) << studs[i].GetMajor() 
             << '|' << left << setw(10) << studs[i].GetGPA()
             << "|" 
             << endl;
    }


    cout << "=================================================" << endl;
    cout << endl;
    return 0;
}