#pragma once
#include <iostream>
using namespace std;

class CDate
{
private:
    static const int NgayTrongThang[13];
    int iNgay, iThang, iNam;
    void ChuanHoa();
public:
    CDate(int Ngay = 0, int Thang = 0, int Nam = 0);
    static int SoNgayTrongThang(int Thang, int Nam);
    CDate operator+(int Ngay);
    CDate operator-(int Ngay);
    int operator-(CDate date);
    CDate& operator++();
    CDate operator++(int);
    CDate& operator--();
    CDate operator--(int);
    bool operator!=(CDate date);
    friend istream& operator>>(istream& in, CDate& date);
    friend ostream& operator<<(ostream& out, CDate date);
};