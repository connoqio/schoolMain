#include <iostream>
#include <string>
#include <iomanip>
#include "Student.h"

using namespace std;

Student::Student() {
    name = "";
    id = -1;
    major = "";
    overallGPA = -1;
}

Student::Student(string n, int ID) : name(n), id(ID) {
    major = "";
    overallGPA = -1;
}

void Student::SetMajor(string n) // setter or mutator
{
        major = n;
}
void Student::SetGPA(double n) // setter or mutator
{
    overallGPA = n;
}

void Student::SetName(string n) // setter or mutator
{
    name = n;
}
void Student::SetID(int i)
{
    id = i;
}
string Student::GetName() const // getter or accessor
{
    return name;
}
string Student::GetMajor() const // getter or accessor
{
    return major;
}
double Student::GetGPA() const // getter or accessor
{
    return overallGPA;
}
int Student::GetID() const
{
    return id;
}
