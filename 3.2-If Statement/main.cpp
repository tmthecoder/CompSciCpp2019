/****
 * Name: Tejas Mehta
 * Date: October 4th, 2019
 * Lab Name: Lab3.2-If Statement
 * Extra: Type validation for both integers that are entered
 */

#include <iostream>

using namespace std;
int main() {
    //Loop to keep going though labs
    while (true) {
        //Ask for choice
        cout << "Enter a lab choice(1-2) or any other key to quit" << endl;
        char choice; cin >> choice;
        //Send to correct lab based on choice
        switch (choice) {
            //1st choice
            case '1':
                //Ask for a number
                cout << "Enter a number" << endl;
                int userChoice; cin >> userChoice;
                //Validate input, check if it's bad
                if (!cin.good()) {
                    //Clear cin and the newline
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "You didn't enter a number!" << endl;
                } else {
                    //Perform lab if statement check and print appropriate response
                    if (userChoice ==  57) {
                        cout << "This is a Heinz number!" << endl;
                    } else {
                        cout << "Just a plain old number" << endl;
                    }
                }
                break;
            //2nd choice
            case '2':
                //Ask for a number
                cout << "Enter a number between 5 and 10, inclusive" << endl;
                int number; cin >> number;
                //Validate it, check it its bad first
                if (!cin.good()) {
                    //Just as before, clear cin and the newline
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "You didn't enter a number!" << endl;
                } else {
                    //Perform number checks for the lab and output the appropriate result
                    if (number > 10) {
                        cout << "Number is too big!" << endl;
                    } else if (number < 5) {
                        cout << "Number is too small!" << endl;
                    } else if (number == 7) {
                        cout << "Lucky Number 7!" << endl;
                    } else {
                        cout << "Just a plain old number" << endl;
                    }
                }
                break;
            default:
                //Exit the program upon input that doesn't lead to labs
                cout << "Exiting ..." << endl;
                return 0;
        }
    }
}