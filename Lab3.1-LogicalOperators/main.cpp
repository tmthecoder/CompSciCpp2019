/****
 * Name: Tejas Mehta
 * Date: October 2nd, 2019
 * Lab Name: Lab3_1_LogicalOperators
 * Extra: Type Checked the entry for the integer
 */
#include <iostream>

using namespace std;
int main() {
    //Loop through labs so you can test over and over
    while (true) {
        //clear any failbits
        cin.clear();
        //ask for a choice
        cout << "Enter a lab choice (1-2) or any other key to quit" << endl;
        char choice; cin>>choice;
        switch(choice) {
            //first lab
            case '1': {
                //Ask the question and print the output based on their answer
                cout << "This program may reformat your hard drive.  Do you wish to continue (y/n)?" << endl;
                string reformat;
                cin >> reformat;
                //lowercase string to reduce checking
                transform(reformat.begin(), reformat.end(), reformat.begin(), ::tolower);
                cout << (reformat == "y" || reformat == "yes" ? "Adios data!" : "Wise Choice!!") << endl;
                break;
            }
            //second part
            case '2': {
                //Ask for an integer
                cout << "Enter an integer between 50 and 100" << endl;
                int entry; cin >> entry;
                //type check if it is a number
                if (isnumber(entry)) {
                    //Check if it fits the conditional and print accordingly
                    if (entry >= 50 && entry <= 100) {
                        cout << "Congrats! You won $" << entry << endl;
                    } else {
                        cout << "Sorry, not following directions will cost you dearly :-(" << endl;
                    }
                } else {
                    //Wrong typed entry
                    cout << "You didn't enter a number! How dare you!" << endl;
                }
                break;
            }
            default:
                //Exit on other keypress
                return 0;

        }
    }
}