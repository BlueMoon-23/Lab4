#pragma once
#include <iostream>
using namespace std;
class PhanSo {
private:
    int iTu, iMau;
public:
    PhanSo(int iTu = 0, int iMau = 1);
    void RutGon();
    PhanSo operator+(PhanSo ps2);
    PhanSo operator-(PhanSo ps2);
    PhanSo operator*(PhanSo ps2);
    PhanSo operator/(PhanSo ps2);
    bool operator==(PhanSo ps2);
    bool operator>(PhanSo ps2);
    bool operator<(PhanSo ps2);
    friend istream& operator>>(istream& in, PhanSo& ps);
    friend ostream& operator<<(ostream& out, PhanSo ps);
};

