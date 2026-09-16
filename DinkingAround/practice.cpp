
#include <iostream>
using namespace std;

int main() {
   int userValue;
   int minNumber;

   cin >> userValue;

   minNumber = userValue;

   while (userValue > 0) {
      if (userValue < minNumber) {
         minNumber = userValue;
      }
      cin >> userValue;
   }

   cout << "Min value: " << minNumber;

   return 0;
}