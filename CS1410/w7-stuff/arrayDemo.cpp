#include <iostream>
using namespace std;

int main(){
    const int R = 3;
    const int C = 3;

    int arr[R][C] = {
                {1, 2, 3},
                {-1, 0, 6},
                {2, 3, 5}
        };

        //sum of all the elements
        int allSum = 0;
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                allSum += arr[r][c];
            }
        } // 21

        cout << "Sum of all the elements: " << allSum << endl;
            

        //sum of all the right diagonal elements
        int rightDiagSum = 0;
        for(int r=0; r<R; r++){
            for(int c = 0; c < C; c++)
                rightDiagSum += ;
        }
        cout << "Sum of all the right diagonal elements: " << rightDiagSum << endl;


        //sum of all the left diagonal elements


    cout << "DONE!" << endl;
}
