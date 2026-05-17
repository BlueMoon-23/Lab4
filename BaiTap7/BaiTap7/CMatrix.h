#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CMatrix {
private:
    int iSoDong;
    int iSoCot;
    vector<vector<double>> MaTran;
public:
    CMatrix(int Dong = 0, int Cot = 0);
    CMatrix operator+(CMatrix other);
    CMatrix operator-(CMatrix other);
    friend istream& operator>>(istream& in, CMatrix& mt);
    friend ostream& operator<<(ostream& out, CMatrix mt);
    CMatrix TinhTich(vector<double> v);
    CMatrix TinhTich(CMatrix other);
};

