// Create a student report
#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        string name;
        int id;
    public:
    Student() {
        name = "";
        id = -1;
    }

    Student(string n, int ID) : name(n), id(ID) {}

    void SetName(string n) // setter or mutator
    {
        name = n;
    }
    string GetName() const // getter or accessor
    {
        return name;
    }
    void SetID(int i)
    {
        id = i;
    }
    int GetID() const
    {
        return id;
    }
};
// Creating an array of objects

int main()
{
    const int NUM_STUDS = 3;
    Student studs[NUM_STUDS];
    string sName;
    int sID;

    cout << "Populate student info: ";
    cout << "\n========================";

    for (int i = 0; i < NUM_STUDS; i++)
    {
        cout << "\nEnter name: ";
        getline(cin, sName);
        cout << "ID: ";
        cin >> sID;
        cin.ignore();
        studs[i].SetName(sName);
        studs[i].SetID(sID);
    }

    cout << "\nDisplay student info: " << endl;

    for (int i = 0; i < NUM_STUDS; i++)
    {
        cout << studs[i].GetName() << " " << studs[i].GetID() << endl;
    }

    cout << endl;
    return 0;
}
/*
// Syntax help
Student s1("Alice", 13);
Student s2("Zak", 44);
cout << s1.GetName() << " " << s1.GetID() << endl;
cout << s2.GetName() << " " << s2.GetID() << endl;
s2.SetID(46);
cout << s1.GetName() << " " << s1.GetID() << endl;
cout << s2.GetName() << " " << s2.GetID() << endl;
*/
