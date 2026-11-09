#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a;
    int v;
    int u;
    int t;

    cout << "enter the final velocity, initial velocity, and the time: " << endl;
    cin >> v >> u >> t;
    a = (v - u) / t;
    cout << "the acceleration is: " << a << endl;
    return 0;
}