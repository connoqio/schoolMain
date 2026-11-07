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

    // sum of all the elements
    int allSum = 0;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            allSum += arr[r][c];
        }
    }
    cout << "Sum of all the elements: " << allSum << endl; // 21

    // sum of the right diagonal (top-left to bottom-right)
    int rightDiagSum = 0;
    for(int i = 0; i < R; i++){
        rightDiagSum += arr[i][i];
    }
    cout << "Sum of the right diagonal elements: " << rightDiagSum << endl; // 1 + 0 + 5 = 6

    // sum of the left diagonal (top-right to bottom-left)
    int leftDiagSum = 0;
    for(int i = 0; i < R; i++){
        leftDiagSum += arr[i][C - 1 - i];
    }
    cout << "Sum of the left diagonal elements: " << leftDiagSum << endl; // 3 + 0 + 2 = 5

    cout << "DONE!" << endl;
}