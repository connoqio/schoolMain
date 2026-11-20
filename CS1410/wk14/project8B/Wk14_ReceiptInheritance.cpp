/*

This is connors receipt inheritance thing, todays date is nov 19
description: COME BACK

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class MenuItem {
protected:
    string name;
    double price;
public: 
    MenuItem(string n, double p) : name(n), price(p) {}

    string GetName()  const { return name; }
    double GetPrice() const { return price; }

    void Print() {
        cout << "Name: " << name << " and price($): " << price << endl;
    }
};

class SizedItem : public MenuItem {
private: 
    string size;
public: 
    SizedItem(string n, double p, string s) : MenuItem(n, p), size(s) {};

    string GetSize() { return size; }

    void Print() {
        cout << "Item: " << name << ", Size: " << size << ", Prices: " << price << endl;
    }

};

class Payment {
protected:
    double amount;
public:
    Payment(double a) : amount(a) {}; // conmstructor 

    double GetAmount() const { return amount; }
    void Print() {
        cout << "Payment due: " << amount << endl;
    }

};

class CardPayment : public Payment{
private:
    string cardType;
    double payment;
public: 
    CardPayment(double a, string ct) : Payment(a), cardType(ct) {};

    string GetCardType() const { return cardType; }

    void Print() {
        cout << "Payment amount: " << amount << ", Card Type: " << cardType << endl;
    }
    
};

int main() {

    // MenuItem sw("Sandwich", 5.99);
    // sw.Print();

    MenuItem taco("2 TACOS", 1.79);
    SizedItem scf("SEASONED CURLY FRIES", 3.69, "RG");
    Payment pay(5.93);
    CardPayment carpay(5.93, "Visa");


    //group 1
    taco.Print();
    scf.Print();

    //group 2
    pay.Print();
    carpay.Print();



    cout << endl;
    return 0;
}