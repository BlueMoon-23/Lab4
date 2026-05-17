#include "CVector.h"
#include <iostream>
using namespace std;

// Phương thức thiết lập tích hợp cả mặc định và truyền tham số
CVector::CVector(int SoChieu) {
    iSoChieu = (SoChieu < 0) ? 0 : SoChieu;
    aDSToaDo.resize(iSoChieu);
}
// Hàm tính độ dài vector
double CVector::DoDai() {
    double sum = 0;
    for (double x : aDSToaDo) {
        sum += x * x;
    }
    return sqrt(sum);
}
// Nạp chồng toán tử + để cộng hai vector cùng số chiều
CVector CVector::operator+(CVector other) {
    CVector KetQua(iSoChieu);
    for (int i = 0; i < iSoChieu; i++) {
        KetQua.aDSToaDo[i] = aDSToaDo[i] + other.aDSToaDo[i];
    }
    return KetQua;
}
// Nạp chồng toán tử - để trừ hai vector cùng số chiều
CVector CVector::operator-(CVector other) {
    CVector KetQua(iSoChieu);
    for (int i = 0; i < iSoChieu; i++) {
        KetQua.aDSToaDo[i] = aDSToaDo[i] - other.aDSToaDo[i];
    }
    return KetQua;
}
// Nạp chồng toán tử * để nhân vector với một số thực k
CVector CVector::operator*(double k) {
    CVector KetQua(iSoChieu);
    for (int i = 0; i < iSoChieu; i++) {
        KetQua.aDSToaDo[i] = aDSToaDo[i] * k;
    }
    return KetQua;
}
// Nạp chồng toán tử * để tính tích vô hướng giữa 2 vector
double CVector::operator*(CVector other) {
    double Product = 0;
    for (int i = 0; i < iSoChieu; i++) {
        Product += aDSToaDo[i] * other.aDSToaDo[i];
    }
    return Product;
}
// Nạp chồng toán tử nhập vector
istream& operator>>(istream& in, CVector& v) {
    for (int i = 0; i < v.iSoChieu; i++) {
        cout << "Toa do thu " << i + 1 << ": ";
        in >> v.aDSToaDo[i];
    }
    return in;
}
// Nạp chồng toán tử xuất vector
ostream& operator<<(ostream& out, CVector v) {
    out << "(";
    for (int i = 0; i < v.iSoChieu; i++) {
        out << v.aDSToaDo[i];
        if (i < v.iSoChieu - 1) out << ", ";
    }
    out << ")";
    return out;
}