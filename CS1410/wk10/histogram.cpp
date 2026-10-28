#if 0

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Histogram(const vector <int>& scores, vector <int>& bins){
   for (int i = 0; i < scores.size(); i++){
      if (scores.at(i) >= 75){
         bins.at(2)++;
      } else if (scores.at(i) >= 70){
         bins.at(1)++;
      } else {
         bins.at(0)++;
      }
   }

}

int main()
{
   vector<int> scores = { 10, 75, 20, 80, 90, 60, 1};
   vector<int> bins(3);

   Histogram(scores, bins);

   for (int i = bins.size() - 1; i >= 0; i--){
      cout << " " << i << "| ";

      for (int st = 0; st < bins.at(i); st++){
         cout << "*";
      }
      cout << endl;
   }

   return 0;
}
#endif