/*
Author: Connor Okey
Date: 11/25/2026
Purpose: To show how animals in the UCI Zoo dataset move, by using inheritance,
         virtual functions, an abstract base class and polymorphism
Time Invested: 1.5 hours
*/

#include <iostream>
#include <fstream>   // gives us ifstream, which reads from a file
#include <sstream>   // gives us stringstream, which cuts a line of text into pieces
#include <string>
#include <vector>

using namespace std;

// GIVEN: Abstract base class. Read it, but do not change it.
class Animal
{
private:
	string name;
	int legs;

public:
	Animal(string n, int l) : name(n), legs(l) {}

	// A virtual destructor lets delete work correctly through an Animal pointer
	virtual ~Animal() {}

	string GetName() const { return name; }
	int GetLegs() const { return legs; }

	// Pure virtual function: every kind of animal must say how it moves
	// It prints the movement with cout. It does not print a new line.
	virtual void GetMovement() = 0;

	// Virtual function with a default body: a derived class may override it
	// It prints the body cover with cout. It does not print a new line.
	virtual void GetBodyCover() { cout << "skin"; }
};

/*
TODO 1: Write class Mammal, derived from Animal (public inheritance)
  - Under private:, add one data member: bool airborne
  - Under public:, add the constructor: Mammal(string n, int l, bool a)
    Hint: pass n and l to the Animal constructor in the initializer list
  - Override GetMovement() so that it prints with cout, using these rules, in this order:
      if airborne is true, print "flies"
      else if GetLegs() is 0, print "swims"
      else print "walks on ", then GetLegs(), then " legs"
    Do not print endl inside GetMovement(). main() prints the line break.
  - Do NOT override GetBodyCover(). A Mammal uses the default, which prints "skin".
*/
class Mammal : public Animal {
private:
	bool airborne;

public:
	Mammal(string n, int l, bool a) : Animal(n, l), airborne(a) { }
	void Setairborne(bool a) { airborne = a; }
	bool Getairborne() const { return airborne; }

	void GetMovement() override {
		if (airborne == true){
			cout << "flies";
		} else if (GetLegs() == 0) {
			cout << "swims";
		} else {
			cout << "walks on " << GetLegs() << " legs";
		}
	}
};


/*
TODO 2: Write class Bird, derived from Animal
  - Under public:, add the constructor: Bird(string n, int l)
  - Override GetMovement() to print "flies"
  - Override GetBodyCover() to print "feathers"
*/

class Bird : public Animal {

public:
	Bird(string n, int l) : Animal(n, l) { }

	void GetMovement() override {
			cout << "flies";
	}
	void GetBodyCover() override {
			cout << "feathers";
	}
};

/*
TODO 3: Write class FlightlessBird, derived from Bird (a grandchild of Animal)
  - Under public:, add the constructor: FlightlessBird(string n, int l)
    Hint: pass n and l to the Bird constructor
  - Override GetMovement() to print "cannot fly, walks on ", then GetLegs(), then " legs"
  - Do NOT write GetBodyCover(). It is inherited from Bird, so it prints "feathers".
*/

class FlightlessBird : public Bird {
public:
	FlightlessBird(string n, int l) : Bird(n, l) { }

	void GetMovement() override {
		cout << "cannot fly, walks on " << GetLegs() << " legs";
	}
};

/*
TODO 4: Write class Fish, derived from Animal
  - Under public:, add the constructor: Fish(string n, int l)
  - Override GetMovement() to print "swims using fins"
  - Override GetBodyCover() to print "scales"
*/

class Fish : public Animal {

public:
	Fish(string n, int l) : Animal(n, l) { }

	void GetMovement() override {
			cout << "swims using fins";
	}
	void GetBodyCover() override {
			cout << "scales";
	}
};

/*
TODO 5: Finish CreateAnimal. Use a switch on type, like the shape switch in Part A.
  type 1: create a Mammal (pass name, legs, airborne)
  type 2: if airborne is true create a Bird, otherwise create a FlightlessBird
  type 4: create a Fish
  any other type: do nothing (those animals are not used in this project)
  Assign each new object to the Animal pointer a. Return a at the end.
  Hint: inside case 1, write: a = new Mammal(name, legs, airborne);
  then write break; to leave the switch. Case 4 works the same way.
  Inside case 2, use an if and an else to choose between Bird and FlightlessBird.
*/
Animal* CreateAnimal(int type, string name, int legs, bool airborne)
{
	Animal* a = nullptr;

	// Write your switch here
	switch (type)
	{
	case 1:
		a = new Mammal(name, legs, airborne);
		break;
	case 2:
		if (airborne == true) {
			a = new Bird(name, legs);
		} else {
			a = new FlightlessBird(name, legs);
		}
		break;
	case 4:
		a = new Fish(name, legs);
		break;
	default:
		break;
	}

	return a;
}

/*
GIVEN: LoadZoo reads the file zoo.data. Do not change it.
We have not covered file operations yet, so this comment explains each step.

The file zoo.data has one animal per line, with 18 values separated by commas:
    dolphin,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1
We use only four of the values:
    Value 0  = the name
    Value 5  = airborne (1 means it flies, 0 means it does not)
    Value 13 = the number of legs
    Value 17 = the class type (1 mammal, 2 bird, 4 fish)

What LoadZoo does, in order:
    1. ifstream opens the file so that our program can read from it.
    2. getline(file, line) reads ONE whole line of the file into the string line.
       The while loop repeats this until there are no lines left (end of the file).
    3. stringstream lets us treat the string line like a small input stream.
       getline(ss, item, ',') reads the text up to the next comma, so the line
       is cut into 18 pieces. Each piece is saved in the vector f.
    4. stoi turns a piece of text such as "4" into the number 4.
    5. CreateAnimal (you write it) builds the right kind of animal from the values.
       Each new animal is added to the vector zoo.
    6. The file closes by itself when the function ends.
*/
vector<Animal*> LoadZoo(string fileName)
{
	vector<Animal*> zoo;
	ifstream file(fileName);                 // open the file for reading
	string line;

	while (getline(file, line))              // read one line; stop at the end of the file
	{
		vector<string> f;                    // the pieces of this line
		stringstream ss(line);               // treat the line as a stream of text
		string item;
		while (getline(ss, item, ','))       // read up to the next comma
			f.push_back(item);               // save the piece

		if (f.size() < 18)                   // skip any line that is too short
			continue;

		Animal* a = CreateAnimal(stoi(f[17]), f[0], stoi(f[13]), f[5] == "1");
		if (a != nullptr)
			zoo.push_back(a);
	}
	return zoo;
}

int main()
{
	vector<Animal*> zoo = LoadZoo("zoo.data");
	cout << "Loaded " << zoo.size() << " animals." << endl << endl;

	/*
	TODO 6: Print the first five animals in the vector, one per line, like this:
	    aardvark: walks on 4 legs
	Do not use if statements to check the kind of animal. Polymorphism does that for you.
	Hint: use a for loop with i from 0 to 4, and reach each animal with zoo.at(i).
	GetMovement() prints by itself, so do it in this order for each animal:
	  1. print zoo.at(i)->GetName() and then ": " with cout
	  2. call zoo.at(i)->GetMovement()
	  3. print endl
	*/

	for (int i = 0; i < 5; i++){
		cout << zoo.at(i)->GetName() << ": ";
		zoo.at(i)->GetMovement();
		cout << endl;
	}

	cout << endl << "Type an animal name (example: dolphin): ";
	string choice;
	getline(cin, choice);


	/*
	TODO 7: Search the vector for the animal whose name equals choice.
	  If you find it, print: name: movement, body cover: cover
	  Example: ostrich: cannot fly, walks on 2 legs, body cover: feathers
	  If you do not find it, print: There is no such animal.
	  Hint: start with Animal* found = nullptr; Then use a for loop with zoo.at(i).
	  If zoo.at(i)->GetName() equals choice, save zoo.at(i) in found and break.
	  After the loop, use if and else on found (is it nullptr or not?).
	  GetMovement() and GetBodyCover() print by themselves, so print the pieces in order:
	  the name and ": ", then call GetMovement(), then print ", body cover: ",
	  then call GetBodyCover(), then print endl.
	*/
	Animal* found = nullptr;
	for (int i = 0; i < zoo.size(); i++) {
		if (zoo.at(i)->GetName() == choice) {
			found = zoo.at(i);
			break;
		}
	}
		if (found != nullptr){
			cout << found->GetName() << ": ";
			found->GetMovement();
			cout << ", body cover: ";
			found->GetBodyCover();
			cout << endl;
		} else {
			cout << "There is no such animal.";
		} 
		

	/*
	TODO 8: Give the memory back. Delete every Animal pointer in the vector,
	one at a time, using zoo.at(i).
	*/
	for (int i = 0; i < zoo.size(); i++){
		delete zoo.at(i);
	}


	cout << endl;
	return 0;
}
