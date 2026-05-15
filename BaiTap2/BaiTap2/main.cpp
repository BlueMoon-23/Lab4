#include <iostream>
#include "PhanSo.h"
using namespace std;

int main()
{
    PhanSo A, B;
    cout << "Nhap phan so A:\n";
    cin >> A;
    cout << "Nhap phan so B:\n";
    cin >> B;
    cout << "\nPhan so A: ";
    cout << A;
    cout << "\nPhan so B: ";
    cout << B;
    // Tính toán
    cout << "\nA + B = " << A + B;
    cout << "\nA - B = " << A - B;
    cout << "\nA * B = " << A * B;
    cout << "\nA / B = " << A / B;
    // So sánh
    if (A == B)
        cout << "\nA = B";
    else if (A > B)
        cout << "\nA > B";
    else
        cout << "\nA < B";
    return 0;
}
