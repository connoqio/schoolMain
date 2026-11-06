#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
private:
    string name;
    int id;
    string major;
    double overallGPA;

public:
    Student();
    Student(string n, int ID);

    void SetName(string n);
    string GetName() const;
    void SetMajor(string n);
    string GetMajor() const;
    void SetGPA(double n);
    double GetGPA() const;
    void SetID(int i);
    int GetID() const;
};

#endif