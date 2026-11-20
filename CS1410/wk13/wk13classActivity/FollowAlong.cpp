/*
a simple class with three
-> different access specifiers
\/ \/ \/ \/ \/
private, protected, public

data members ( attributes properties fields )
member functions (interface/behavior,
functions inside class)

*/

#if 0
#include <iostream>
#include <string>

using namespace std;


class Simple {

    private:
        int x;

    protected:
        int y;

    public:
        int z;

//Simple(): x(1), y(2), z(3){} 
//this is a constructor

        Simple(){ //this is a constructor
            x = 1;
            y = 2;
            z = 3;
        }
        //mutators and accessors
        void DummyFn() {
            cout << "x: " << x << " y: " << y
            << " z: " << z << endl;
        }
        void F2() {
            cout << "doing something more.. " 
            << endl;
            DummyFn();
        }

}; //only z is accessible outside the class


int main() {

    Simple obj;

    cout << obj.z << endl;

    //obj.DummyFn(); DummyFn() is private so no access
    //to the outside world
    obj.F2(); //F2 is public so it can be accesed anywhere


    cout << endl;
    return 0;
}

#endif