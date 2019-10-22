/****
 * Name: Tejas Mehta
 * Date: October 1st, 2019
 * Lab Name: PiggyBankOOP
 * Extra: Gave the option to directly enter a dollar amount if they knew, and proceed as normally
 */
#include <iostream>
#include "PiggyBank.h"
using namespace std;
int main() {
    //Intro screen
    cout << "*********************" << endl;
    cout << "*     Welcome to    *" << endl;
    cout << "*   the Piggy Bank  *" << endl;
    cout << "*********************" << endl;
    //Ask and get name
    cout << "What is your name?" << endl;
    string name; cin >> name;
    //Ask and get weeks saving
    cout << "How many weeks have you been saving?" << endl;
    int weeks; cin >> weeks;
    if (weeks <= 0 || weeks >52) {
        cout << "Invalid week count! Exiting...";
        return 0;
    }
    //Ask if they know how much money they have
    cout << "Do you know how much money you have?(defaults to no)" << endl;
    string entry; cin >> entry;
    double money = 0;
    if (entry == "y" || entry == "yes") {
        //Ask them how much money they have
        cout << "Enter your money amount" << endl;
        cout << "$";
        cin >> money;
        PiggyBank bank(name, money, weeks);
        cout << bank;
    } else {
        //Ask for quarters and append to money
        cout << "How many quarters do you have?" << endl;
        int q; cin >> q;
        //Ask for dimes and append to money
        cout << "How many dimes do you have?" << endl;
        int d; cin >> d;
        //Ask for nickels and append to money
        cout << "How many nickels do you have?" << endl;
        int n; cin >> n;
        //Ask for pennies and append to money
        cout << "How many pennies do you have?" << endl;
        int p; cin >> p;
        PiggyBank bank(name, q, d, n, p, weeks);
        cout << bank;
    }
    return 0;
}