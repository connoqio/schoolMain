/*this is connor's tree project, started this september 21 around 12:30
I finished this at */

#include <iostream>
using namespace std;

int main() {
    int height;

    cout << "How tall do you want the tree to be? ";
    cin >> height;

    if (height < 3 || height > 15) {
        cout << "Error: height must be between 3 and 15. Try again. " << endl;
        return 1;
    }

    // this is the code for printing the tree
   for (int row = 1; row <= height; row++) {
        int frontSpaces = height - row;
        int innerSpaces = 2 * (row - 1);

        for (int i = 0; i < frontSpaces; i++){
            cout << ' ';
        }
        cout << "/";

        for (int j = 0; j < innerSpaces; j++) {
            cout << ' ';
        }
        cout << "\\";
        cout << "\n";
    }

int baseWidth = height * 2;
    for (int i =  0; i < baseWidth; i++){
        cout << "-";
    }
    cout << "\n";


    // this is the code for the trunk
int trunkWidth = 2;
int trunkSpaces = (baseWidth - trunkWidth) / 2;
int trunkHeight = height / 2;

    for (int row = 0; row < trunkHeight; row++) {
        for (int i = 0; i < trunkSpaces; i++) {
            cout << ' ';
        }
        cout << "||";
        cout << '\n';
    }

    return 0;
}