#include <iostream>
#include <string>
using namespace std;

class Students {
   public:
      Students();
      Students(int);
      int GetTotal() const { return  numStudents; }

   private:
      int numStudents;
};

Students::Students() : numStudents(0) {}
Students::Students(int num) : numStudents(num) {}

class Tutor {
   public:
      Tutor(string);
      Tutor(string, int);
      void Print() const;

   private:
      string name;
      Students students;
};

Tutor::Tutor(string tutorName) : name(tutorName) {}
Tutor::Tutor(string tutorName, int numStudents) : name(tutorName), students(numStudents) {}

void Tutor::Print() const {
   if (students.GetTotal() == 0){
      cout << name << " is alone" << endl;
   }
   else {
      cout << name << " teaches " << students.GetTotal() << " students" << endl;
   }
}

int main() {
   Tutor myTutor("Leo");
   Tutor yourTutor("Aya", 2);

   myTutor.Print();
   yourTutor.Print();

   return 0;
}