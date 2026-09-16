
#include <iostream>
#include <string>
using namespace std;

int main() {
   // a1 b1 c1 d1 
   // A1 B2 C3 D4

   int i = 1;

   for (char c = 'A'; c < 'H'; c += 2, i += 2){
      cout << c << i << " ";
   }

cout << endl << endl;

   for (int i = 2; i <= 2000; i *= 10){
      cout << i << ' ';
      }
   

   return 0;
}