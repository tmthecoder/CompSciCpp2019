/****
 * Name: Tejas Mehta
 * Date: October 4th, 2019
 * Lab Name: Lab3.3-Switch
 * Extra: Used an enum for the grade values
 */
#include <iostream>
using namespace std;
//Enum for the grade values
enum gradeValue {
    A,
    B,
    C,
    D,
    F,
    UNKNOWN
};
//to convert a string to grade value enum
gradeValue convert(const std::string& str)
{
    if(str == "A") return A;
    else if(str == "B") return B;
    else if(str == "C") return C;
    else if (str == "D") return D;
    else if (str == "F") return F;
    else return UNKNOWN;
}
int main() {
    while (true) {
        //ask for a lab choice
        cout << "Enter a lab choice(1-2) or any other key to quit" << endl;
        char choice; cin >> choice;
        //Switch for the lab choice
        switch (choice) {
            //Lab part 1, for the grade average
            case '1': {
                //Ask for average and convert it to enum
                cout << "Enter your grade average(A-F)" << endl;
                string avg;
                cin >> avg;
                gradeValue average = convert(avg);
                //Switch to print result based on average, and handles an invald input letter
                switch (average) {
                    case A :
                        cout << "Your work is outstanding!" << endl;
                        break;
                    case B :
                        cout << "You are doing good work!" << endl;
                        break;
                    case C:
                        cout << "Your work is satisfactory." << endl;
                        break;
                    case D:
                        cout << "You need to work a little harder." << endl;
                        break;
                    case F:
                        cout << "Please see me for extra help!" << endl;
                        break;
                    default:
                        cout << "Not a valid grade average!!" << endl;
                }
                break;
            }
            //Lab part 2 to show the number, and the description of the number the user entered
            case '2': {
                cout << "Enter a number between 1 and 10, inclusive" << endl;
                int entry;
                cin >> entry;
                //Check if the entry is good, and break off if not
                if (!cin.good()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "You didn't enter a number!" << endl;
                    break;
                }
                //Switch for the number entry, and print the description of the number they inputted, also handles invalid numbers
                switch (entry) {
                    case 1:
                        cout << "Your number is a low odd number." << endl;
                        break;
                    case 2:
                        cout << "Your number is a low even number." << endl;
                        break;
                    case 3:
                        cout << "Your number is a low odd number." << endl;
                        break;
                    case 4:
                        cout << "Your number is a low even number." << endl;
                        break;
                    case 5:
                        cout << "Your number is the middle odd number." << endl;
                        break;
                    case 6:
                        cout << "Your number is the middle even number." << endl;
                        break;
                    case 7:
                        cout << "Your number is a high odd number." << endl;
                        break;
                    case 8:
                        cout << "Your number is a high even number." << endl;
                        break;
                    case 9:
                        cout << "Your number is a high odd number." << endl;
                        break;
                    case 10:
                        cout << "Your number is a high even number." << endl;
                        break;
                    default:
                        cout << "Not a valid number!" << endl;
                }
                break;
            }
            default:
                return 0;
        }
    }
}