/*
class
public and private access specifiers

struct = replace class with struct, make sure access specifiers are there
given access specifiers class is same as struct

destructor
same name as that of class
~ tilde
has no parameters
one destructor per class

*/

#include <iostream>
#include <string>

using namespace std;

class Student{
private:
    int ID;
    string name;
    int *bData;

public:
    Student() {
        ID = -111;
        name = "No Name";
        bData = nullptr;
    }
    Student(int id, string n, int num) : ID(id), name(n) {
        bData = new int;
        *bData = num;
    };

    void ShowStudentInfo(){
        cout << "Name: " << name << ", ID: " << ID << ", BData: " << *bData << endl;
    }
    ~Student() {
        cout << name << " is being destroyed." << endl;
        delete bData;
    }
};

int main() {
    Student s1(1, "alice", 54321); //stack object
    Student s2(1, "bob", 98765);

    for(int i = 0; i < 2; i++){
        Student s3(44, "zoya", 11111); //stack object
        s3.ShowStudentInfo();
    } // destriuctor is called

    s1.ShowStudentInfo();
    s2.ShowStudentInfo();


    cout << endl;
    return 0;
}