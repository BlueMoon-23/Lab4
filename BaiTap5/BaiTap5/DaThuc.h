#pragma once
#include <iostream>
#include <vector>
using namespace std;

class DaThuc {
private:
    int iBac;
    vector<double> aDSHeSo;
public:
    DaThuc(int Bac = 0);
    double TinhGiaTri(double x);
    DaThuc operator+(DaThuc other);
    DaThuc operator-(DaThuc other);
    DaThuc operator*(DaThuc other);
    bool operator==(DaThuc other);
    friend istream& operator>>(istream& in, DaThuc& dt);
    friend ostream& operator<<(ostream& out, DaThuc dt);
};

