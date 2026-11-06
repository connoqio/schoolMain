// #include <iostream>
// #include <string>
// #include <iomanip>
// #include "Student.h"


// using namespace std;

// class Student {
//     private:
//         string name;
//         int id;
//         string major;
//         double overallGPA;

//     public:
//     Student() {
//         name = "";
//         id = -1;
//     }

//     Student(string n, int ID) : name(n), id(ID) {}

//     void SetMajor(string n) // setter or mutator
//     {
//         major = n;
//     }
//     void SetGPA(double n) // setter or mutator
//     {
//         overallGPA = n;
//     }

//     void SetName(string n) // setter or mutator
//     {
//         name = n;
//     }
//     string GetName() const // getter or accessor
//     {
//         return name;
//     }
//     string GetMajor() const // getter or accessor
//     {
//         return major;
//     }
//     double GetGPA() const // getter or accessor
//     {
//         return overallGPA;
//     }
//     void SetID(int i)
//     {
//         id = i;
//     }
//     int GetID() const
//     {
//         return id;
//     }
// };
// Creating an array of objects

// int main()
// {
//     const int NUM_STUDS = 2;
//     Student studs[NUM_STUDS];
//     string sName;
//     int sID;
//     string smajor;
//     double sGPA;

//     cout << "Populate student info: ";
//     cout << "\n========================";

//     for (int i = 0; i < NUM_STUDS; i++)
//     {
//         cout << "\nEnter name: ";
//         getline(cin, sName);
//         cout << "ID: ";
//         cin >> sID;
//         cin.ignore();
//         cout << "Enter major: ";
//         getline(cin, smajor);
//         cout << "Enter GPA: ";
//         cin >> sGPA;
//         cin.ignore();
//         studs[i].SetName(sName);
//         studs[i].SetID(sID);
//         studs[i].SetMajor(smajor);
//         studs[i].SetGPA(sGPA);
//     }

//     cout << "=================================================" << endl;
//     cout << "|Name            |ID|Major           |OverallGPA|" << endl;
//     cout << "=================================================" << endl;


//     for (int i = 0; i < NUM_STUDS; i++)
//     {
//         cout << "|" << left << setw(16) << studs[i].GetName() 
//              << "|" << left << setw(2)  << studs[i].GetID()
//              << "|" << left << setw(16) << studs[i].GetMajor() 
//              << '|' << left << setw(10) << studs[i].GetGPA()
//              << "|" 
//              << endl;
//     }


//     cout << "=================================================" << endl;
//     cout << endl;
//     return 0;
// }
// /*
// // Syntax help
// Student s1("Alice", 13);
// Student s2("Zak", 44);
// cout << s1.GetName() << " " << s1.GetID() << endl;
// cout << s2.GetName() << " " << s2.GetID() << endl;
// s2.SetID(46);
// cout << s1.GetName() << " " << s1.GetID() << endl;
// cout << s2.GetName() << " " << s2.GetID() << endl;
// */


