/*
This is connors program that takes input from the user and asigns it to an array
This program finds the mimimum Sum and the max sum of the integers entered
took about 20 minutes
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr(5);

    for (int i = 0; i < 5; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long min_sum = 0, max_sum = 0;

    for (int i = 0; i < 4; ++i) {
        min_sum += arr[i];
        max_sum += arr[i + 1];
    }

    cout << min_sum << " " << max_sum << endl;

    return 0;
}