#include <iostream>
using namespace std;

int main() {
   // int col;
   // int row;

   // for (row = 1; row <= 4; row++){
   //    for (col = row; col <= row + 5; col++){
   //       if (col == 2 * row + 1){
   //          cout << "# ";
   //          continue;
   //       }
   //       cout << col << " ";
   //    }
   //    cout << endl;
   // }

   // int score = 0;
   // int sum = 0;
   // double avg = 0.0;
   // int count = 0;
   
   // cout << "Enter a score (-1 to end): ";
   // cin >> score;

   // while(score != -1){
   //    cout << "Enter a score (-1 to end): ";
   //    sum += score;
   //    count++;
   //    cin >> score;
   // }
   // avg = double(sum) / count;
   // cout << "The average is: " << avg;

   // int row = 0;
   // int col = 0;

   // for (row = 1; row <= 7; row++){
   //    for (col = 1; col <= row; col++){
   //    cout << row;
   //    }
   // cout << endl;

   // }

   // for (int row = 0; row < 4; row++) {
   //      for (int col = 0; col < 4; col++) {
   //          if (row + col == 3) {
   //              cout << "* ";
   //          } else {
   //              cout << (3 * row + col + 1) << " ";
   //          }
   //      }
   //      cout << endl;
   //  }

   int row = 0;
   int col = 0;

   for (row = 0; row < 4; row++){
      for (col = 0; col < 4; col++){
         if(col + row == 3){
            cout << "* ";
         } else{
            cout << (3 * row + col + 1) << " "; 
         }
      }
      cout << endl;
   }

   return 0;
}

/*


1 2 3 *

4 5 * 7

7 * 9 10

* 11 12 13


*/