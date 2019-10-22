//
// Created by Tejas Mehta on 10/22/19.
//

#ifndef HONORROLLOOP_STUDENT_H
#define HONORROLLOOP_STUDENT_H
#include <iostream>
#include <map>
using namespace std;
class Student {
private:
    map<string, int> courseGrade;
    int count;
    double average;
    bool infraction;
    string name;
public:
    Student(string name, int count);
    void getCourseGrade();
    void getAverage();
    friend ostream& operator<<(ostream&, const Student&);
};


#endif //HONORROLLOOP_STUDENT_H
