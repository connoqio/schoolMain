/*This is connors guessing game 
This program is a guessing game
started 9/18/2026, this took about 15 minutes to write*/

#include <iostream>
#include <random>
#include <chrono>
using namespace std;

int main()
{
	default_random_engine rng((unsigned)(chrono::system_clock::now().time_since_epoch().count()));
	uniform_int_distribution<int> range(1, 100);
	int target = range(rng);
    int guess = 0;


    do{
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;
        if (guess == 0){
            cout << "You quit";
            break;
        } else if (guess == target){
            cout << "You guessed it!";
        } else if (guess < target){
            cout << "Higher, try again\n";
        } else if (guess > target){
            cout << "Lower, try again\n";
        }
    } while(guess != target);


    return 0;
}