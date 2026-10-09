/*
A1 A2 A3 A4 A5
B1 B2 B3 B4 B5
C1 C2 C3 C4 C5
D1 D2 D3 D4 D5
*/

#include <iostream>
using namespace std;

int main(){

    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 5; c++){
            cout << char('A' + r) << (c + 1) << " ";
        }
        cout << endl;
    }
    return 0;
}