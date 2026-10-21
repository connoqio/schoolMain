#include <iostream>
#include <iomanip>

using namespace std;

double ComputeAverage(int numCount);
//signature/Prototype of a function

int main1() {
   int numValues;
   double averageVal;

   cout << "Enter number of values: ";
   cin >> numValues;
   cout << "Value read for " << numValues << endl;
   averageVal = ComputeAverage(numValues);

   cout << "Average: ";
   cout << fixed << setprecision(3) << averageVal << endl;
   return 0;
}

double ComputeAverage(int numValues) {

   cout << "Value incoming" << numValues << endl;


   double valuesSum = 0;
   int currValue = 0;

   for (int i = 0; i < numValues; ++i) {
      cout << "Enter number: ";
      cin >> currValue;
      valuesSum += currValue;
   }
   return valuesSum / numValues;
}