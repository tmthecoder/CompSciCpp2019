/*
 * Name: Tejas Mehta
 * Date: November 11th, 2019
 * Lab Name: ProjectFunctionsCircles
 * Extra: Also gave the user the circumference of each circle, and the difference at the end
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
//Get the area of a circle given the radius (follows pi r squared)
double getArea(int radius) {
    return round(radius * radius * 3.14 * 10)/10;
}
//Get the circumference of a circle given the radius (follows 2 pi r)
double getCircumference(int radius) {
    return round(2 * radius * 3.14* 10)/10;
}
//Gte the volume given a radius of a sphere (4/3 pi r cubed)
double getVolume(double radius) {
    return round(((radius * radius * radius * 3.14 * 4)/3)*10)/10;
}
//Main to print all needed lab material
int main() {
    //Loop through numbers 1-10 and print them out in 3 nice formated column
    cout << "Area and Circumference of all numbers 1-10" << endl;
    cout << setw(10) << left << "Number" << right << setw(10) << "Circumference" << right << setw(10) << "Area" << endl;
    for(int i = 1; i <= 10; i++) {
        cout << setw(10) << left << i << right << setw(10) << getCircumference(i) << right << setw(10) << getArea(i) << endl;
    }
    //Print out the volume of all even numbers 1-10 using those as radii
    cout << "Volume of all even numbers 1-10" << endl;
    cout << setw(20) << left << "Number" << setw(10) << left << "Volume" << endl;
    for(int i = 2; i <= 10; i+=2) {
        cout << setw(20) << left << i << setw(10) << left << getVolume(i) << endl;
    }
    //Ask user for 2 radii, show them and show the difference
    cout << "Your choices:" << endl;
    cout << "Enter a radius of a sphere: ";
    double radius; cin >> radius;
    cout << "Enter a radius of another sphere: ";
    double radius2; cin >> radius2;
    cout << setw(10) << left << "Radius" << setw(10) << left << "Volume" << endl;
    cout << setw(10) << left << radius << setw(10) << left << getVolume(radius) << endl;
    cout << setw(10) << left << radius2 << setw(10) << left << getVolume(radius2) << endl;
    cout << "The difference of the radii are: " << getVolume(radius) - getVolume(radius2) << endl;
    return 0;
}