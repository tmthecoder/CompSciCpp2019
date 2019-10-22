#include <iostream>
#include "Student.h"
using namespace std;
int main() {
    //Get name via getline
    cout << "Enter your full name:" << endl;
    string name;
    getline(cin, name);
    cout << "How many courses are you taking?" << endl;
    int courseCount; cin>>courseCount;
    if (cin.good()) {
        //Validate cin and and exit upon invalid count
        if (courseCount > 8) {
            cout << "Invalid course count!\n Exiting!" << endl;
            return 0;
        }
    } else {
        cout << "Invalid course entry! Exiting..." << endl;
    }
    //make student with name and count
    Student student(name, courseCount);
    //get course grades
    student.getCourseGrade();
    //get average
    student.getAverage();
    //print formatted output
    cout << student << endl;
    return 0;
}