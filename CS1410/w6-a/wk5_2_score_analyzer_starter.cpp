// Score Analyzer - STARTER CODE
// Name: _Connor Okey______
// Arrays & Vectors hands-on project (~30 minutes)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ---------- Part A: Array (fixed number of labs) ----------
    const int NUM_LABS = 5;
    int labs[NUM_LABS];

    // TODO A1: Use a for loop to read NUM_LABS lab scores into labs[]

    cout << "Enter lab scores(0-100): " << endl;

    for (int i = 1; i <= 5; i++){
        cout << "Lab " << i << ": ";
        cin >> labs[i];
    }

    // TODO A2: Loop over the array to compute the sum and the highest score

    int HS = labs[0];
    int sum = 0;

    for (int j = 0; j <= 5; j++){
        sum += labs[j];
        if (labs[j] > HS){
            HS = labs[j];
        }
    }
    

    // TODO A3: Print every lab ("Lab 1: 88"), the lab average, and the highest lab
    //          Hint: use static_cast<double>(labSum) / NUM_LABS for the average

 
    cout << "--- Lab Report ---" << endl;

    for (int i = 0; i < NUM_LABS; i++){
        cout << "Lab " << (i + 1) << ": " << labs[i] << " ";
    }
    cout << endl;
    cout << "Avg: " << static_cast<double>(sum) / NUM_LABS << "\nHigh: " << HS << "\n";


    // ---------- Part B: Vector (unknown number of quizzes) ----------
    vector<int> quizzes;
    int score;

    // TODO B1: Read quiz scores until the user enters -1.
    //          Add each score with quizzes.push_back(score);

    cout << "Enter quiz scores(0-10) -1 to quit: ";

    while (cin >> score && score != -1){
        quizzes.push_back(score);
    }

    // TODO B2: If no quizzes were entered, print a message and return 0

    if (quizzes.empty()) return cout << "No quizzes\n", 0;

    // TODO B3: Print how many quizzes, every score, and the quiz average
    //          (a range-based for loop works great here)

    int quizSum = 0;
    cout << "Count: " << quizzes.size() << "\nScores: ";
    for (int q : quizzes) cout << q << " ", quizSum += q;
    double quizAvg = static_cast<double>(quizSum) / quizzes.size();
    cout << "\nAvg: " << quizAvg << "\n";

    // TODO B4: Print only the scores that are ABOVE the quiz average

    cout << "Above Avg: ";
    for (int q : quizzes) if (q > quizAvg) cout << q << " ";
    cout << "\n";

    return 0;
}
