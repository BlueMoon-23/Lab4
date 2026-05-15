#pragma once
#include <iostream>
using namespace std;

class CTime
{
private:
    int iGio, iPhut, iGiay;
    void ChuanHoa();
public:
    CTime(int Gio = 0, int Phut = 0, int Giay = 0);
    CTime operator+(int Giay);
    CTime operator-(int Giay);
    CTime& operator++();
    CTime& operator--();
    CTime operator++(int);
    CTime operator--(int);
    friend istream& operator>>(istream& in, CTime& time);
    friend ostream& operator<<(ostream& out, CTime time);
};

