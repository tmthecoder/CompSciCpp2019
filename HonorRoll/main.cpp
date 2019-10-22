/****
 * Name: Tejas Mehta
 * Date: October 18th, 2019
 * Lab Name: HonorRoll
 * Extra:
 */
#include <iostream>
#include <map>
#include <random>
#include <iterator>
#include <iomanip>

using namespace std;

//Return a map with the courses mapped to the student's grade in that course
 map<string, int> getCourses (int count) {
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
                break;
            }
        }
        //Map name to grade in the map
        courses[name] = grade;
    }
    //Return the course
    return courses;
}

//Method to get the student's average
double getAverage(map<string, int> courses) {
     double average = 0;
     //Loop through the courses and add the final grades
    for(auto & course : courses)
    {
        int grade =  course.second;
        average+=grade;
    }
    //Return the average of the final grades
    return (double)average/courses.size();
 }

 //Print the output in a nice formatted display as wanted
 void printOutput(string name, double average, map<string, int> courses, bool infraction) {
     //Print name followed by a blank line
     cout << name << endl << endl;
     //Formatted 2 column print for the grades and class
     cout << setw(20) << left << "Class" << setw(10) << left << "Grade";
     //Loop through map and print the course and it's grade
     for(auto & course : courses) {
         string courseName = course.first;
         int grade =  course.second;
         cout << setw(20) << left << courseName << setw(10) << left << grade;
     }
     //Print the average to 2 decimal points
     cout << endl << "Average: " << setprecision(2) << average << endl;
     //Get the disciplinary infraction value and put it to a nice readable one
     string disciplinary = infraction ? "YES" : "NO";
     cout << "Disciplinary Infraction: " << disciplinary << endl;
     //Check whether the user made the honor roll and print accordingly
     if (average >= 90 && !infraction && courses.size() >= 5) {
        cout << "Congratulations " << name << "! You have made the honor roll." << endl;
     } else {
         cout << "I’m sorry " << name << " but you didn’t qualify for the honor roll." << endl;
     }
 }

int main() {
    //Ask for full nmae
    cout << "Enter your first and last name" << endl;
    string name;
    //get name via getline
    getline(cin, name);
    //get the course count
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
    //Get the map with the course and its grade
    map<string, int> courseGrade = getCourses(courseCount);
    random_device rd;
    //Get a random for the disciplinary infraction
    default_random_engine e( rd() );
    bool infraction = e() % 2;
    //Get average from map
    double average = getAverage(courseGrade);
    //Print output in a nice format
    printOutput(name, average, courseGrade, infraction);
    return 0;
}