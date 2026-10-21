#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Add(int& v1, int& v2){
    return v1 + v2;
}

int main(){
    int id = 007;

    cout << "My name is bond... " << id << endl;

    int &bondID = id;

    cout << "My name is bond... " << bondID << endl;

    id = id * 100;
    cout << "id: " << id << endl;
    cout << "bondID: " << bondID << endl;

    int a = 12, b = 13;
    cout << "The sum is: " << Add(a, b) << endl;


    cout << endl;
    return 0;
}





// double Add(double inVal1, double inVal2){

//     return inVal1 + inVal2;
// }

// void showNames(vector<string> list){
//     for (string n: list){
//         cout << n << endl;
//     }
// }

// bool AnyNameWithA(vector<string> list){
//     for (string n : list)
//         if(n.at(0) == 'a' || n.at(0) == 'A')
//             return true;

//     return false;
// }

// int main (){

    

//     vector<string> names = {"B Smith", "shrek", "fiona", "woody"};

//     cout << "display the list of names: " << endl;
//     showNames(names);

//     cout << "\nSearch if there is any name that starts with A " << endl;
//     if(AnyNameWithA(names)){
//         cout << "there is a name with A" << endl;
//     } else{
//         cout << "There is NO name with A" << endl;
//     }

//     double res1 = Add(3, 3.3);
//     cout << "Add(3, 3.3) " << res1 << endl;

//     cout << "Add(80, 3.3) " << Add(80, 3.3) << endl;

//     double v1 = 5.5, v2 = 5.6;
//     cout << Add(v1, v2) << endl;

//     cout << endl;
//     return 0;
// }