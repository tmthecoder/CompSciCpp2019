//
// Created by Tejas Mehta on 10/22/19.
//

#include <iomanip>
#include "Student.h"

using namespace std;
//Constructor
Student::Student(std::string name, int count) {
    //Set name and count
    this->name = name;
    this->count = count;
}

//Method to map courses to grades
void Student::getCourseGrade() {
    map<string, int> courses;
    //Loop through the given course count asking for courses
    for(int i = 0; i < count; i++) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //Clear cin and ask for the course name
        cout << "Please enter course " << i+1 << "'s name: " << endl;
        string name;
        while (true) {
            //Validate the length and make them enter again if needed
            if (name.length() > 20){
                cout << "Course name too long, please try again" << endl;
                cin >> name;
            } else {
                break;
            }
        }
        //Get the name via getline
        getline(cin, name);
        //Ask for a final grade
        cout << "Please enter final grade for course " << i+1 << ":" << endl;
        int grade; cin >> grade;
        while (true) {
            //Validate that as well
            if (!cin.good()) {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Invalid entry... Please try again" << endl;
                cin >> grade;
            } else {
                if (grade > 110) {
                    cout << "Invalid grade. Please enter a valid grade" << endl;
                    cin >> grade;
                } else {
                    break;
                }
            }
        }
        //Map name to grade in the map
        courses[name] = grade;
    }
    this->courseGrade = courses;
}
//Method to get average
void Student::getAverage() {
    double avg = 0;
    //Loop through the courses and add the final grades
    for(auto & course : this->courseGrade)
    {
        int grade =  course.second;
        avg+=grade*1.0;
    }
    //Return the average of the final grades
    this->average = avg/(double)count;
}
//ostream to print out
ostream &operator<<(ostream& output, const Student& student) {
    //append name followed by a blank line
    output << student.name << endl << endl;
    //Formatted 2 column append for the grades and class
    output << setw(20) << left << "Class" << setw(10) << left << "Grade" << endl;
    //Loop through map and append output with the course and it's grade
    for(auto & course : student.courseGrade) {
        string courseName = course.first;
        int grade =  course.second;
        output << setw(20) << left << courseName << setw(10) << left << grade << endl;
    }
    //append the average with a precision 2 decimal points
    output << endl << "Average: " << setprecision(2) << student.average << endl;
    //Get the disciplinary infraction value and put it to a nice readable word
    string disciplinary = student.infraction ? "YES" : "NO";
    output << "Disciplinary Infraction: " << disciplinary << endl;
    //Check whether the user made the honor roll and append accordingly
    if (student.average >= 90 && !student.infraction && student.count >= 5) {
        output << "Congratulations " << student.name << "! You have made the honor roll." << endl;
    } else {
        output << "I’m sorry " << student.name << " but you didn’t qualify for the honor roll." << endl;
    }
    //return output to print
    return output;
}
