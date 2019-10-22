//
// Created by Tejas Mehta on 10/8/19.
//

#include "PiggyBank.h"
#include<iomanip>
#include <cmath>
//Constructor if they already know the amount of money they have
PiggyBank::PiggyBank(string o, double t, int w) {
    owner = std::move(o);
    total = t;
    average = getAverage(w, total);
    yearRate = getYear(average);
};
//Constructor if they already know the amount of money they have
PiggyBank::PiggyBank(string o, int q, int d, int n, int p, int w) {
    owner = std::move(o);
    total = getTotal(q, d, n, p);
    average = getAverage(w, total);
    yearRate = getYear(average);
}
//method to get the year
double PiggyBank::getYear(double a) {
    return a*52;
}
//method to get total from coin values
double PiggyBank::getTotal(int q, int d, int n, int p) {
    return q*0.25 + d*0.1 + n*0.05 + p*0.01;
}
//method to get average with total and weeks
double PiggyBank::getAverage(int weeks, double t) {
    return (int)round(t/weeks*100)/100.0;
}
ostream& operator<<(ostream& output, const PiggyBank &aPiggyBank) {
    char avg [50];
    sprintf(avg,"%.2f",aPiggyBank.average);
    char yr[50];
    sprintf(yr,"%.2f",aPiggyBank.yearRate);
    //return the string in the requested form
    output << aPiggyBank.owner << ", at this rate: $" << avg  << "/week, you can save $" << yr << " per year!";
    return output;
}