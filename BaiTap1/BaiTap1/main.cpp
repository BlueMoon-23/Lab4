#include <iostream>
#include "SoPhuc.h"
using namespace std;

int main()
{
    SoPhuc A;
    SoPhuc B;
    // Nhập số phức
    cout << "Nhap So phuc A\n";
    cin >> A;
    cout << "Nhap So phuc B\n";
    cin >> B;
    // Xuất số phức
    cout << "\nSo phuc A: " << A;
    cout << "\nSo phuc B: " << B;
    // Tính toán
    cout << "\nA + B = " << A + B;
    cout << "\nA - B = " << A - B;
    cout << "\nA * B = " << A * B;
    cout << "\nA / B = " << A / B;
    // So sánh
    if (A == B) cout << "\nA va B bang nhau";
    else cout << "\nA va B khong bang nhau";
    return 0;
}
