//
// Created by Tejas Mehta on 10/8/19.
//

#ifndef PIGGYBANKOOP_PIGGYBANK_H
#define PIGGYBANKOOP_PIGGYBANK_H

#include <iostream>
using namespace std;

class PiggyBank {
private:
    string owner;
    double total;
    double average;
    double yearRate;
    double getTotal(int q, int d, int n, int p);
    double getAverage(int weeks, double t);
    double getYear(double a);

public:
    PiggyBank(string o, double t, int w);
    PiggyBank(string o, int q, int d, int n, int p, int w);
    friend ostream& operator<<(ostream&, const PiggyBank&);
};


#endif //PIGGYBANKOOP_PIGGYBANK_H
