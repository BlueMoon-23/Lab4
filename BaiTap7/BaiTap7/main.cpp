#include <iostream>
#include "CMatrix.h"
#include <vector>
using namespace std;

void NhapVector(vector<double>& v) {
    int size;
    cout << "Nhap so phan tu: ";
    cin >> size;
    cout << "Nhap cac phan tu:\n";
    v.resize(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

int main()
{
    CMatrix A, B;
    cout << "Nhap ma tran A\n";
    cin >> A;
    cout << "Nhap ma tran B\n";
    cin >> B;
    cout << "Ket qua cua A + B la\n" << A + B;
    cout << "Ket qua cua A - B la\n" << A - B;
    cout << "Ket qua cua A * B la\n" << A.TinhTich(B);
    cout << "Nhap vector v de nhan voi A va B: ";
    vector<double> v;
    NhapVector(v);
    cout << "Ket qua cua A * v la\n" << A.TinhTich(v);
    cout << "Ket qua cua B * v la\n" << B.TinhTich(v);
}
