
/*
This is connors project on car class. I actually really like this assignment a lot.

this took me about 30 minutes to complete

This program takes cars makes, models and years and outputs it to the screen.
*/
#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string model = "unknown";
    string make = "unknown";
    int year = 0;

public:

    void SetModel (string cModel){
        model = cModel;
    }

    void SetMake (string cMake){
        make = cMake;
    }

    void SetYear (int cYear){
        year = cYear;
    }

    string GetModel() const {
        return model;
    }

    string GetMake() const {
        return make;
    }

    int GetYear() const {
        return year;
    }

    void PrintInfo() const {
        cout << endl << make << " " << model << ", " << year << endl;
    }

};

int main() {

    Car dreamCar1;
    Car dreamCar2;

    dreamCar1.SetMake("Koenigsegg");
    dreamCar1.SetModel("Jesko");
    dreamCar1.SetYear(2025);
    dreamCar1.PrintInfo();

    dreamCar2.SetMake("Nissan");
    dreamCar2.SetModel("Skyline GT-R R34");
    dreamCar2.SetYear(2000);
    dreamCar2.PrintInfo();

    cout << endl;
    return 0;
}