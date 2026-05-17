#include <iostream>
#include "CVector.h"
using namespace std;

int main()
{
    int SoChieu;
    cout << "Nhap so chieu: ";
    cin >> SoChieu;
    CVector A(SoChieu), B(SoChieu);
    cout << "Nhap vector A:\n";
    cin >> A;
    cout << "Nhap vector B:\n";
    cin >> B;
    double k;
    cout << "Nhap so thuc k de nhan A voi k, B voi k: ";
    cin >> k;
    // Tính độ dài
    cout << "\nDo dai A: " << A.DoDai();
    cout << "\nDo dai B: " << B.DoDai();
    cout << "\nA + B = " << A + B;
    cout << "\nA - B = " << A - B;
    cout << "\nA * k = " << A * k;
    cout << "\nB * k = " << B * k;
    cout << "\nTich vo huong: " << A * B;
}
