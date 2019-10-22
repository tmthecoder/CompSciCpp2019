/****
 * Name: Tejas Mehta
 * Date: September 23rd, 2019
 * Lab Name: Lab3-Worksheet Division and Modulus
 * Extra: Added an option for the user to give the team number
 */
#include <iostream>
using namespace std;
//Team counter function
int teamSplit() {
    //Ask for the amount of players
    cout << "Enter the amount of players" << endl;
    int players; cin >> players;
    //Ask for the amount of players on a team
    cout << "Enter the amount of players on a team" << endl;
    int teamMax; cin >> teamMax;
    //Show the output by division and modulus
    cout << "There will be " << players/teamMax << " teams and " << players%teamMax << " left over" << endl;
    return 0;
}
//Function to split the 3 digit number
int threeDigitNum() {
    //Ask for number
    cout << "Enter a 3 digit number" << endl;
    int number; cin >> number;
    //integer division by 100 for first num
    int num1 = number/100;
    //modulus and division for 2nd num
    int num2 = number%100/10;
    //modulus by 10 for last num
    int num3 = number%10;
    //Print numbers and sum
    cout << "First number: " << num1 << "\nSecond Number: " << num2 << "\nThird Number: " << num3 << endl;
    cout << "Sum of all 3 numbers: " << num1+num2+num3 << endl;
    return 0;
}
int main() {
    //Loop to constantly go through labs
    while (true) {
        //Ask for lab
        cout << "Enter a lab number from 1-2 or any other key to quit" << endl;
        char entry; cin >> entry;
        switch (entry) {
            //goto lab 1
            case '1':
                teamSplit();
                break;
            //goto lab 2
            case '2':
                threeDigitNum();
                break;
            default:
                //Exit
                return 0;
        }
    }
}