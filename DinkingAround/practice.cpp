#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   string inputString;

   getline(cin, inputString);

   if (isalpha(inputString[0]) && isalpha(inputString[1]) && isalpha(inputString[2])){
      cout << "Valid string" << endl;
   } else {
      cout << "Invalid string" << endl;  
   }

   return 0;
}