#include <iostream>
#include "DaThuc.h"
using namespace std;

int main()
{
    DaThuc DaThucA, DaThucB;
    cout << "Nhap da thuc A:\n";
    cin >> DaThucA;
    cout << "Nhap da thuc B:\n";
    cin >> DaThucB;
    cout << "Da thuc A: ";
    cout << DaThucA;
    cout << "\nDa thuc B: ";
    cout << DaThucB;
    // Tính giá trị tại x
    double x;
    cout << "\nNhap gia tri x: ";
    cin >> x;
    cout << "Gia tri cua da thuc A tai x: ";
    cout << DaThucA.TinhGiaTri(x);
    cout << "\nGia tri cua da thuc B tai x: ";
    cout << DaThucB.TinhGiaTri(x);
    // Tính toán
    cout << "\nA + B = " << DaThucA + DaThucB;
    cout << "\nA - B = " << DaThucA - DaThucB;
    cout << "\nA * B = " << DaThucA * DaThucB;
    // So sánh
    if (DaThucA == DaThucB) cout << "\nKet qua so sanh: A = B";
    else cout << "\nKet qua so sanh: A != B";
    return 0;
}
