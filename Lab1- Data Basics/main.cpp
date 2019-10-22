/****
 * Name: Tejas Mehta
 * Date: September 17th, 2019
 * Lab NameL Lab1_Data_Basics
 * Extra: added fahrenheit to celcius conversions and looped the lab
 */
#include <iostream>
using namespace std;

//Temperature function
int temp() {
    //Ask for conversion choice
    cout << "Do you want to convert fahrenheit to celsius(fc) or celsius to fahrenheit(cf). Defaults to fc" << endl;
    //Get conv choice and declare other vars
    string conv;
    cin >> conv;
    double toCon;
    double result;
    //Check which choice
    if (conv == "cf") {
        //Enter temp and follow formula
        cout << "Enter a celsius temperature" << endl;
        cin >> toCon;
        result = toCon * 1.8 + 32;
        cout << "The temperature in fahrenheit is: " << result << endl;
    } else {
        //Enter temp and follow formula
        cout << "Enter a fahrenheit temperature" << endl;
        cin >> toCon;
        result = (toCon-32) * 5 / 9;
        cout << "The temperature in celsius is: " << result << endl;
    }
    return 0;
}
//Pizza function
int pizza() {
    //Ask for slices
    int slices;
    cout << "How many slices of pizza did you have? " << endl;
    cin >> slices;
    //Get amount needed to travel and print
    double needToTravel = slices*375/100.0;
    cout << "You need to travel " << needToTravel << " miles" << endl;
    return 0;
}

int main() {
    //Loop for ongoing lab choice
    while (true) {
        //Ask for choice
        cout << "Enter a lab choice(1 or 2) or press any other key to quit" << endl;
        char choice;
        cin >> choice;
        //Based on choice execute the method
        switch (choice) {
            case '1' : temp(); break;
            case '2': pizza(); break;
            default:
                //Exit on other input
                return 0;
        }

    }
}

