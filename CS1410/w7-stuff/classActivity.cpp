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

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            if(j != i + 2){
                arr[i][j] = j + 1 + i;
            }
        }
    }
}