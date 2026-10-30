#include <string>
#include <iostream>
#include "student.h"

using namespace std;

void Student::SetName(string sname) {
        name = sname;
    }

    void Student::SetNumCredits(int nCredits) {
        numCredits = nCredits;
    }

    void Student::SetGPA(double sGpa) {
        gpa = sGpa;
    }

    // getters - accessors


    string Student::GetName() const {
        return name;
    }

    int Student::GetNumCredits() const {
        return numCredits;
    }

    double Student::GetGPA() const {
        return gpa;
    }

    void Student::PrintInfo() {
        cout << endl << name << ": " << numCredits << ' ' << gpa << endl;
    }
