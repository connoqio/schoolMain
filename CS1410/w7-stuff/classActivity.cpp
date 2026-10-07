#include <iostream>
using namespace std;

/*
1 2 # 4 5 6

2 3 4 # 6 7

3 4 5 6 # 8

4 5 6 7 8 #
*/

int main(){
    int val = 0;
    int arr[4][6];

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 6; j++){
            if(i + 2 == j){
                arr[i][j] = val;
            } else{
                arr[i][j] = i + j + 1;
            }
        }
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 6; j++){
            if (arr[i][j] == 0) {
                cout << "# ";
            } else {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
 
    cout << "DONE" << endl;
}