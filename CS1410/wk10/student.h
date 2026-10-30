#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
private:
    string name = "unknown";
    int numCredits = -1;
    double gpa = -2;

public:
    void SetName(string sname);
    void SetNumCredits(int nCredits);
    void SetGPA(double sGpa);
    
    string GetName() const;
    int GetNumCredits() const;
    double GetGPA() const;
    
    void PrintInfo();
};

#endif