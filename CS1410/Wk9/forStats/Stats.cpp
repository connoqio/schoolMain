/* 
This is Connors stats assignment, it is currently 10/25/26
Time alloted to this assignment: 
1 hour
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

//this is the functino prototypes
double Mean(const vector<int>& scores);
double Deviation(const vector<int>& scores);
void Histogram(const vector <int>& scores, vector <int>& bins);


int main(){
    vector<int> scores;
    int vecInput = 0;

    cout << "Enter the positive values you want in the vector (enter -1 to stop): " << endl;

    //this while loop makes sure that the number of elements taken from input is not above 100
    while (scores.size() < 100){
        cin >> vecInput;

        if (vecInput == -1){ //this is what ends the users input 
            break;
        }

        if (vecInput >= 0){ // the >= makes sure non of the vaules are negative.
            scores.push_back(vecInput); //this statement is what adds the input to the vector
        }
    }

    //this checks if the function was given no values it says that to the user.
    if (scores.empty()){
        cout << "there were no values entered." << endl;
        return 0;
    }

    vector<int> bins;
    Histogram(scores, bins);

    // Print histogram from bin 9 down to bin 0
    for (int i = 9; i >= 0; --i) {
        cout << setw(2) << i << "| ";
        
        // Print asterisks for the frequency
        for (int j = 0; j < bins[i]; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    double stdDev = Deviation(scores);
    cout << "SD: " << stdDev << endl;

    return 0;
}

double Mean(const vector<int>& scores){
    if (scores.empty()) return 0.0;
    
    double sum = 0.0;
    for (int score : scores) {
        sum += score;
    }
    // this returns the average of the vector
    return sum / scores.size();
}

double Deviation(const vector<int>& scores){
    if (scores.empty()) return 0.0;

    double meanVal = Mean(scores);
    double sumSquaredDiff = 0.0;
    for (int score : scores) {
        double diff = score - meanVal;
        sumSquaredDiff += diff * diff;
    }

    // Population standard deviation divided by N
    return sqrt(sumSquaredDiff / scores.size());
}

void Histogram(const vector<int>& scores, vector<int>& bins){
    bins.assign(10, 0);

    for (int score : scores) {
        int binIndex = score / 10;
        if (binIndex >= 10) {
            binIndex = 9; // Cap at the last bin for scores >= 90
        }
        bins[binIndex]++;
    }
}


