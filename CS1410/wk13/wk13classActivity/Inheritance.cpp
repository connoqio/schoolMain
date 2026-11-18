/*
INHERITANCE
parent -> base class -> super class -> ancestor
child -> (inherits) -> derived -> sub class
-> descendant

a class is extended
a class recieves attributes/properties and behaviors/functions
from other classes

why do we need it?
redundancy
*/

#include <iostream>
#include <string>

using namespace std;

class Person {

private:
    string name;
    int ID = -99;

public:
    Person(string n, int i): name(n), ID(i){}

    //setters/mutators
    void SetName(string s) { name = s; }
    void SetID(int i) { ID = i; }

    //getters/accessors
    string GetName() const { return name; }
    int GetID() const { return ID; }

    void ShowData() {
        cout << "Name: " << name << " ID: "
        << ID << '\t';
    }

};
//Person is base class
//Student is derived class
class Student : public Person { //student inherits person
private:
    // string name; aquire these from Person
    // int ID;
    string major;
    double GPA;

    //setters and getters and more functions 
public:
    Student(string n, int i, string m, double g)
    : Person(n, i), major(m), GPA(g){}

    //overridden function: same return type, 
    //same parameters, it is used in inheritance
    void ShowData() {

        Person::ShowData();

        cout << " Major: " << major 
        << "GPA: " << GPA << endl;
    }


};


int main() {
    
    Person p ("alice", 1);
    Student s("jamesbond", 7, "fantasy", 3.99);

    p.ShowData();
    s.ShowData();

    cout << endl;
    return 0;
}


// class Staff : public Person{
// private:
//     // string name;
//     // int ID;
//     string dept;

//     //setters and getters and more functions
//     public: 

// };