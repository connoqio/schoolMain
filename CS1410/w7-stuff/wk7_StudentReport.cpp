/*
connor edited this code
week 7
Generate the student report as instructed in the class
Section 5.5 Multiple vectors --- aka parallel vectors
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for alignment of data

using namespace std;

int main() {
	const int NUM_OF_STUDS = 5;

	vector<string> names(NUM_OF_STUDS);
	vector<int> numCredits(NUM_OF_STUDS);
	vector<double> gpas(NUM_OF_STUDS);

	cout << "\nPopulate Data: " << endl;

	for (int i = 0; i < names.size(); i++) {		
		cout << "\nEnter Name: ";
		getline(cin, names.at(i));

		cout << "\nEnter number of credits (whole number): ";
		cin >> numCredits.at(i);

		cout << "\nEnter GPA (real number): ";
		cin >> gpas.at(i);

		// Consume the leftover newline character after reading
		// numeric entries
		cin.ignore();
	}


	/*
-----------------------------------------
| Name            |   Credits |     GPA |
-----------------------------------------
| Markim Ann      |       15  |    2.85 |
-----------------------------------------
| John Smith      |       12  |    3.45 |
-----------------------------------------
| Zoya Lee        |       18  |    2.95 |
-----------------------------------------
| Dave   Johnsen  |       14  |    3.60 |
-----------------------------------------
| Emma Rose       |       16  |    3.75 |
-----------------------------------------
	*/

	cout << "\n-----------------------------------------" << endl;
	cout << left << setw(20) << "Name" << " | "
		<< right << setw(8) << "Credits" << " | "
		<< right << setw(7) << "GPA" << "|";


	for (int i = 0; i < names.size(); i++) {
		cout << "\n-----------------------------------------" << endl;
		cout << left << setw(20) << names.at(i) << " | "
			<< right << setw(8) << numCredits.at(i) << " | "
			<< right << setw(7) << fixed << setprecision(2) << gpas.at(i) << "|";
	}
	cout << "\n-----------------------------------------" << endl;


	//cout << names.at(0) << " " << numCredits.at(0) << " " << gpas.at(0);




	cout << endl;
	return 0;

}