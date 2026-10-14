#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int max_of_four(int a, int b, int c, int d){
   int max = a;

   for(int i = 0; i < 4; i++){
      if (b > max){
         max = b;
      }else if(c > max){
         max = c;
      }else if(d > max){
         max = d;
      }
   }
return max;
}

int main(){
   int a, b, c, d;
   cout << "enter 4 values: \n" ;
   cin >> a >> b >> c >> d;

   cout << "the highest value is: " << max_of_four(a, b, c, d) << "\n";
}