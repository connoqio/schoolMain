#include <iostream>
using namespace std;

class Airplane {
   public:
      Airplane();
      void AddPassengers(int passengers);
      int GetAvailableSeats() const;
   private:
      int totalSeats;
      int passengers;
};

Airplane::Airplane() {
   totalSeats = 400;
   passengers = 0;
}

void Airplane::AddPassengers(int passengers) {
   this->passengers = this->passengers + passengers;
}

int Airplane::GetAvailableSeats() const {
   return totalSeats - passengers;
}

int main() {
   Airplane airbus330;

   airbus330.AddPassengers(7);
   airbus330.AddPassengers(10);

   cout << airbus330.GetAvailableSeats() << " seats" << endl;

   return 0;
}