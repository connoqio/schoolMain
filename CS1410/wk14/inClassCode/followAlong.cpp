/*
What do we mean by static members?
Static data members, static member functions

data that does not belong to any object
that is, data about the class

Overriding a function

For polymorphism to work:
1. inheritance
2. upcasting
3. overriding a function
4. abstract class
5. virtual functions

*/

#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string name;
private:
    static int count; //this is a static data member
public:
    Animal(string n): name(n) { count++; }
    ~Animal(){ count--; }

    string GetName() const { return name; }
    
    //virtual tells the compiler that the child has its version of speak
    virtual void Speak() {
        cout << " makes a sound " << endl;
    }
    //overriding - generic behavior is overriden
    void Speak(string s) {
        cout << " makes " << s << " sound " << endl;
    }

    //static member function
    static int GetCount()  { return count; }

};

//Initialize the static data member
int Animal::count = 0;

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {};

    void Speak() {
        cout << " Woofs " << endl;
    }

};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {};

    void Speak() {
        cout << " Meowwwwwwws " << endl;
    }
};

int main() {

    cout << "The universe is empty: " << Animal::GetCount() << endl;

    Animal a("toothless");
    Dog sc ("scooby");
    Cat tom("tom");

    //some more concepts about pointer
    Animal* ap = new Animal("Chewy");
    cout << ap->GetName() << endl;
    ap->Speak();
    
    Animal * dp = new Dog("charles ");
    cout << dp->GetName() << endl;
    dp->Speak();
    
    Animal* cp = new Cat("garfield ");
    cout << cp->GetName() << endl;
    cp->Speak();
    
    cout << "How many animals so far: " << Animal::GetCount() << endl;
    
    
    cout << endl;
    return 0;
}

