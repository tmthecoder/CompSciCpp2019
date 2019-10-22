//
// Created by Tejas Mehta on 9/25/19.
//
#import <iostream>
#include <cmath>
using namespace std;

class PiggyBank {
    //public methods
    public:
        //Constructor if they already know the amount of money they have
        PiggyBank(string o, double t, int w) {
            owner = std::move(o);
            total = t;
            average = getAverage(w, total);
            yearRate = getYear(average);
        }
        //Constructor if they already know the amount of money they have
        PiggyBank(string o, int q, int d, int n, int p, int w) {
            owner = std::move(o);
            total = getTotal(q, d, n, p);
            average = getAverage(w, total);
            yearRate = getYear(average);
        }
        //toString method
        string toString() {
            //convert to money-style char arrays for average and year rate
            char avg [50];
            sprintf(avg,"%.2f",average);
            char yr[50];
            sprintf(yr,"%.2f",yearRate);
            //return the string in the requested form
            return owner + ", at this rate: $" + avg  + "/week, you can save $" + yr + " per year!";
        }
    private:
        //private variables
        string owner;
        double total;
        double average;
        double yearRate;
        //method to get total from coin values
        double getTotal(int q, int d, int n, int p) {
             return q*0.25 + d*0.1 + n*0.05 + p*0.01;
        }
        //method to get average with total and weeks
        double getAverage(int weeks, double t) {
            return (int)round(t/weeks*100)/100.0;
        }
        //method to get the year
        double getYear(double a) {
            return a*52;
        }
};
