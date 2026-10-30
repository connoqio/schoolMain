/*
Week 10

Class instruction
member data - field - attributes - class members

behavior - functions - operations - 

private public
*/

#include <iostream>
#include <string>
#include "student.h"

using namespace std;


// encapsulation - user defined data type

class Student {

private:
    string name = "unknown";
    int numCredits = -1;
    double gpa = -2;

public:
// member functions
    // setters - mutators
    void SetName(string sname) {
        name = sname;
    }

    void SetNumCredits(int nCredits) {
        numCredits = nCredits;
    }

    void SetGPA(double sGpa){
        gpa = sGpa;
    }

    // getters - accessors


    string GetName() const {
        return name;
    }

    int GetNumCredits() const {
        return numCredits;
    }

    double GetGPA() const {
        return gpa;
    }

    void PrintInfo() {
        cout << endl << name << ": " << numCredits << ' ' << gpa << endl;
    }

};

int main(){

    int i = 12;
    double numCredits = 3.3;
    Student alice; // object or instance of a class -- variable of the class Student
    Student bond;


    string word = "hello"; // !

    cout << word.size() << endl; // . member access operator

    cout << word.substr(1,2) << endl;

    cout << word << endl;
    word.push_back('!');
    cout << "\nafter push " << word << endl;

    cout << "name: " << alice.GetName() << endl;
    cout << "credits: " << alice.GetNumCredits() << endl;
    cout << "GPA: " << alice.GetGPA() << endl;


    cout << i << endl;
    cout << numCredits << endl;


    cout << "\nLets put data inside the object" << endl;
    alice.SetName("alice wonderland");
    alice.SetNumCredits(34);
    alice.SetGPA(4);
    bond.SetName("James Bond");
    bond.SetNumCredits(3);
    bond.SetGPA(0.7);


    cout << "\nShow what is alice's data: " << endl;
    // cout << "name: " << alice.GetName() << endl;
    // cout << "credits: " << alice.GetNumCredits() << endl;
    // cout << "GPA: " << alice.GetGPA() << endl;  

    // cout << "\nShow what is bond's data: " << endl;
    // cout << "b name: " << bond.GetName() << endl;
    // cout << "b credits: " << bond.GetNumCredits() << endl;
    // cout << "b GPA: " << bond.GetGPA() << endl;  

    alice.PrintInfo();

    bond.PrintInfo();
    

    cout << endl;
    return 0;

}