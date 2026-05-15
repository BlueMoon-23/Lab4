#include <iostream>
#include "CTime.h"
using namespace std;

int main()
{
	CTime time;
	cout << "Nhap thoi gian: \n";
	cin >> time;
    // Tính toán phép cộng, trừ với số nguyên giây
	int Giay1, Giay2;
	cout << "Nhap so giay can tang: ";
	cin >> Giay1;
	cout << "time + " << Giay1 << " = " << time + Giay1 << endl;
	cout << "Nhap so giay can giam: ";
	cin >> Giay2;
	cout << "time - " << Giay2 << " = " << time - Giay2 << endl;
    // Tính toán phép thêm, bớt 
    // Tiền tố ++
    cout << "Gia tri time ban dau: " << time << endl;
    cout << "Gia tri khi goi ++time: " << ++time << endl;
    // Hậu tố ++
    cout << "Gia tri khi goi time++: " << time++ << endl;
    cout << "Gia tri time sau khi thuc thi: " << time << endl;
    // Tiền tố --
    cout << "Gia tri khi goi --time: " << --time << endl;
    // Hậu tố --
    cout << "Gia tri khi goi time--: " << time-- << endl;
    cout << "Gia tri time sau khi thuc thi: " << time << endl;
}
