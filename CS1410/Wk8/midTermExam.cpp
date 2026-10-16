
#include <iostream>
using namespace std;

int main(){
    int array[3][4] = {};
    int rSum = 0;
    int cSum= 0;
    double sum = 0;
    double avg = 0;

    cout << "Enter the elements of the arrays: \n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> array[i][j];
        }
    }

    cout << "\nCompute and print the sum of each row:";

    for (int i = 0; i < 3; i++) {
        rSum = 0;
        for (int j = 0; j < 4; j++) {
            rSum += array[i][j];
        }
        sum += rSum;
        cout << "\nSum of row " << i << ": " << rSum;
    }

    cout << "\n\nCompute and print the sum of each column:\n";

    for (int j = 0; j < 4; j++) {
        cSum = 0;
        for (int i = 0; i < 3; i++) {
            cSum += array[i][j];
        }
        cout << "Sum of column " << j << ": " << cSum << endl;
    }

    cout << "\nTotal sum of all elements = " << sum << endl;

    avg = sum / 12;
    cout << "\nAverage of all elements = " << avg << endl;

    return 0;
}