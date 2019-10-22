/****
 * Name: Tejas Mehta
 * Date: September 23rd, 2019
 * Lab Name: Lab2.4-Piggy Bank Program
 * Extra: Gave the option to directly enter a dollar amount if they knew
 */
#include <iostream>
#include <cmath>
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
    //Ask if they know how much money they have
    cout << "Do you know how much money you have?(defaults to no)" << endl;
    char entry; cin >> entry;
    double money = 0;
    if (entry == 'y') {
        //Ask them how much money they have
        cout << "Enter your money amount" << endl;
        cout << "$";
        cin >> money;
    } else {
        //Ask for quarters and append to money
        cout << "How many quarters do you have?" << endl;
        int q; cin >> q;
        money += q*.25;
        //Ask for dimes and append to money
        cout << "How many dimes do you have?" << endl;
        int d; cin >> d;
        money += d*.1;
        //Ask for nickels and append to money
        cout << "How many nickels do you have?" << endl;
        int n; cin >> n;
        money += n*.05;
        //Ask for pennies and append to money
        cout << "How many pennies do you have?" << endl;
        int p; cin >> p;
        money += p*.01;
    }
    //Ask and get weeks saving
    cout << "How many weeks have you been saving?" << endl;
    int weeks; cin >> weeks;
    //Print total money, average and how much they can save per year
    cout << "You have $" << money << endl;
    cout << "You average $" << round(money/weeks * 100) / 100 << " per week" << endl;
    cout << name << ", You can save $" << (round(money/weeks * 100) / 100)*52 << " per year" << endl;

    return 0;
}