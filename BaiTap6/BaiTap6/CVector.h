#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class CVector {
private:
    int iSoChieu;
    vector<double> aDSToaDo;
public:
    CVector(int Bac = 0);
    double DoDai();
    CVector operator+(CVector other);
    CVector operator-(CVector other);
    CVector operator*(double k);
    double operator*(CVector other);
    friend istream& operator>>(istream& in, CVector& v);
    friend ostream& operator<<(ostream& out, CVector v);
};

