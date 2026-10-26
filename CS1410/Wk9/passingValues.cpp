
#if 0
#include <iostream>
#include <string>

using namespace std;

int Swap(int x, int y){
    int tempVar = 0;
    tempVar = x;
    x = y;
    y = tempVar;

    cout << "after swap x : " << x << " y: " << y << endl;

    return 1;
}

int SwapR(int& x, int& y){
    int tempVar = 0;
    tempVar = x;
    x = y;
    y = tempVar;

    cout << "after swap x : " << x << " y: " << y << endl;

    return 2;
}

int main(){

    int x = 3;
    int y = 5;

    cout << "swap values: " << Swap(x, y) << endl;
    cout << "after swap x : " << x << " y: " << y << endl; // 3 5

    cout << "pass by reference: swap values: " << SwapR(x, y)<< endl;
    cout << "after SwapR x: " << x << " y: " << y << endl;


    cout << endl;
    return 0;
}

#endif

