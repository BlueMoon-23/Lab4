#include <iostream>
#include "CDate.h"
using namespace std;

int main()
{
    CDate d1, d2;
    cout << "Nhap ngay thu nhat (d1):" << endl;
    cin >> d1;
    cout << "Ngay ban vua nhap: " << d1 << endl;
    // Tính toán kết quả cộng, trừ đi một số nguyên ngày
    int add;
    cout << "\nNhap so ngay muon cong them: ";
    cin >> add;
    cout << "Ket qua sau khi cong " << add << " ngay: " << d1 + add << endl;
    int minus;
    cout << "\nNhap so ngay muon tru di: ";
    cin >> minus;
    cout << "Ket qua sau khi tru " << minus << " ngay: " << d1 - minus << endl;
    // Tính toán kết quả thêm, bớt đi 1 ngày
    cout << "\nKiem tra tang/giam:" << endl;
    CDate temp = d1;
    temp++;
    cout << "d1++: " << temp << endl;
    temp--;
    cout << "d1--: " << temp << endl;
    // Tính khoảng cách giữa 2 ngày
    cout << "\nNhap ngay thu hai (d2) de tinh khoang cach:" << endl;
    cin >> d2;
    cout << "Khoang cach giua " << d1 << " va " << d2 << " la: " << d1 - d2 << " ngay." << endl;
}
