/*
Name: Connor Okey
Minutes invested: 70
Description: Week 10 Class Activity. Practice C-strings, std::string, and
             function overloading.
Date: 10/27/26

The string Class (from <string>)
C++ provides the std::string class, which handles memory and operations
automatically.

Advantages of std::string
- No need to manage memory manually.
- Safer, because it resizes automatically.
- Supports operators like +, ==, <, etc.
- Easy to use with the STL and streams.

YOUR TASK
Define eight functions. There are four tasks, and each task needs two
overloaded versions: one for a character array and one for a string object.
   FindNumAlpha   - count the letters (a to z, A to Z)
   FindNumDigits  - count the digits (0 to 9)
   FindNumVowels  - count the vowels (a, e, i, o, u, in upper or lower case)
   FindNumWords   - count the words (words are separated by one or more spaces)

Rules
- The character array versions must stop at the null terminator '\0'.
- Use a loop in every function. You may use the functions isalpha, isdigit,
  and tolower from <cctype>.
- Do not change main(). Run the program and compare your output with the
  expected output at the bottom of this file.
*/

#include <iostream>
#include <string>   // for std::string
#include <cctype>   // for isalpha, isdigit, tolower
using namespace std;

// Given: returns the number of characters before the null terminator '\0'
int FindLenofstring(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

/*
TODO 1: define the function FindNumAlpha that takes in a character array
        and returns the number of letters.
*/
int FindNumAlpha(const char arr[]){
        int countL = 0;
        for (int i = 0; arr[i] != '\0'; i++){
                if (isalpha(arr[i])){
                        countL++;
                }
        }
    return countL;
}
/*
TODO 2: define the function FindNumAlpha that takes in a string object
        and returns the number of letters.
*/
int FindNumAlpha(string str){
        int tLetters = 0;
        for (int i = 0; i < str.size(); i++){
                if (isalpha(str.at(i))){
                        tLetters++;
                }
        }
        return tLetters;
}

/*
TODO 3: define the function FindNumDigits that takes in a character array
        and returns the number of digits.
*/
int FindNumDigits(const char arr1[]){
        int countD = 0;
                for (int i = 0; arr1[i] != '\0'; i++){
                        if (isdigit(arr1[i])){
                                countD++;
                        }
                }
        return countD;
}

/*
TODO 4: define the function FindNumDigits that takes in a string object
        and returns the number of digits.
*/
int FindNumDigits(string str){
        int countD = 0;
        for (int i = 0; i < str.length(); i++){
                if (isdigit(str.at(i))){
                        countD++;
                }
        }
        return countD;
}
/*
TODO 5: define the function FindNumVowels that takes in a character array
        and returns the number of vowels (a, e, i, o, u, in any case).
*/
int FindNumVowels(char arr2[]){
        int countD = 0;
        for (int i = 0; arr2[i] != '\0'; i++){
                char c = tolower(arr2[i]);
                if (arr2[i] == 'a' || arr2[i] == 'e' || arr2[i] == 'i' || arr2[i] == 'o' || arr2[i] == 'u'){
                        countD++;
                } else {
                        continue;
                }
        }
        return countD;
}
/*
TODO 6: define the function FindNumVowels that takes in a string object
        and returns the number of vowels (a, e, i, o, u, in any case).
*/
int FindNumVowels(string strV){
        int countV = 0;
        for (int i = 0; i < strV.size(); i++){
                strV.at(i) = tolower(strV.at(i));
                if (strV.at(i) == 'a' || strV.at(i) == 'e' || strV.at(i) == 'i' || strV.at(i) == 'o' || strV.at(i) == 'u'){
                        countV++;
                } else {
                        continue;
                }
        }
        return countV;
}
/*
TODO 7: define the function FindNumWords that takes in a character array
        and returns the number of words.
Hint: a new word starts when you see a non-space character
      and the character before it is a space (or it is the first character).
*/
int FindNumWords(const char arr[]){
    int countW = 0;
    for (int i = 0; arr[i] != '\0'; i++){
        if (arr[i] != ' ' && (i == 0 || arr[i - 1] == ' ')) {
            countW++;
        }
    }
    return countW;
}
/*
TODO 8: define the function FindNumWords that takes in a string object
        and returns the number of words.
*/
int FindNumWords(string& str){
    int countW = 0;
    for (int i = 0; i < str.length(); i++){
        if (str.at(i) != ' ' && (i == 0 || str.at(i - 1) == ' ')) {
            countW++;
        }
    }
    return countW;
}

int main() {
    string firstName = "Alice";
    string lastName = "Smith";

    cout << "\nDeclare C-string: " << endl;
    char userName[] = "james b0nd 007";   // the last character of a C-string is '\0'
    // '\0' is called the null terminator

    char pword[5] = { 'a', 'b', 'c', 'd', '\0' };
    // Same as: char pword[] = "abcd";

    cout << "userName is: " << userName << "   password is: " << pword << endl;

    // Concatenation
    string fullName = firstName + " " + lastName;
    cout << "Full Name: " << fullName << endl;

    cout << "\nWhat is the length of userName: " << FindLenofstring(userName) << endl;

    // The functions work on a character array...
    char mesg[] = "Hello CS 1410 class!";

    int numAlpha = 0;
    int numDigits = 0;
    int numVowels = 0;
    int numWords = 0;

    numAlpha = FindNumAlpha(mesg);
    numDigits = FindNumDigits(mesg);
    numVowels = FindNumVowels(mesg);
    numWords = FindNumWords(mesg);

    cout << "\nCharacter array message: \"" << mesg << "\"" << endl;
    cout << "Number of alphabets: " << numAlpha << endl;
    cout << "Number of digits: " << numDigits << endl;
    cout << "Number of vowels: " << numVowels << endl;
    cout << "Number of words: " << numWords << endl;

    // ...and on a string object
    string mesg2 = "  Overloads rock in CS 1410  ";

    numAlpha = FindNumAlpha(mesg2);
    numDigits = FindNumDigits(mesg2);
    numVowels = FindNumVowels(mesg2);
    numWords = FindNumWords(mesg2);

    cout << "\nString object message: \"" << mesg2 << "\"" << endl;
    cout << "Number of alphabets: " << numAlpha << endl;
    cout << "Number of digits: " << numDigits << endl;
    cout << "Number of vowels: " << numVowels << endl;
    cout << "Number of words: " << numWords << endl;

    // Length
    cout << "\nLength: " << fullName.length() << endl;

    // Comparison
    if (firstName == "Alice")
        cout << "First name is Alice" << endl;

    // Substring
    cout << "First 3 letters: " << fullName.substr(0, 3) << endl;

    // Insert and erase
    fullName.insert(0, "Ms. ");
    cout << "With title: " << fullName << endl;

    fullName.erase(0, 4);
    cout << "After erase: " << fullName << endl;

    return 0;
}

/*
| Feature             | C-string (char[])                | std::string          |
| ------------------- | -------------------------------- | -------------------- |
| Header              | <cstring>                        | <string>             |
| Memory              | Fixed size                       | Dynamically managed  |
| Concatenation       | strcat()                         | + operator           |
| Comparison          | strcmp()                         | ==, <, etc.          |
| Input (with spaces) | cin.getline()                    | getline(cin, s)      |
| Safety              | Prone to overflow                | Safe and flexible    |
| Use case            | Low-level code, embedded systems | Modern C++ programs  |
*/

/*
EXPECTED OUTPUT

Declare C-string:
userName is: james b0nd 007   password is: abcd
Full Name: Alice Smith

What is the length of userName: 14

Character array message: "Hello CS 1410 class!"
Number of alphabets: 12
Number of digits: 4
Number of vowels: 3
Number of words: 4

String object message: "  Overloads rock in CS 1410  "
Number of alphabets: 17
Number of digits: 4
Number of vowels: 6
Number of words: 5

Length: 11
First name is Alice
First 3 letters: Ali
With title: Ms. Alice Smith
After erase: Alice Smith
*/
