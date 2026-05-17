#include "DaThuc.h"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// Phương thức thiết lập tích hợp cả mặc định và truyền tham số
DaThuc::DaThuc(int Bac) {
    iBac = Bac;
    aDSHeSo.resize(iBac + 1);
}
// Hàm tính giá trị đa thức tại giá trị x
double DaThuc::TinhGiaTri(double x) {
    double GiaTri = 0;
    for (int i = iBac; i >= 0; i--) {
        GiaTri += aDSHeSo[i] * pow(x, i);
    }
    return GiaTri;
}
// Nạp chồng toán tử + để cộng 2 đa thức
DaThuc DaThuc::operator+(DaThuc other) {
    DaThuc KetQua(max(iBac, other.iBac));
    for (int i = KetQua.iBac; i >= 0; i--) {
        if (i <= iBac) KetQua.aDSHeSo[i] += aDSHeSo[i];
        if (i <= other.iBac) KetQua.aDSHeSo[i] += other.aDSHeSo[i];
    }
    return KetQua;

}
// Nạp chồng toán tử - để trừ 2 đa thức
DaThuc DaThuc::operator-(DaThuc other) {
    DaThuc KetQua(max(iBac, other.iBac));
    for (int i = KetQua.iBac; i >= 0; i--) {
        if (i <= iBac) KetQua.aDSHeSo[i] += aDSHeSo[i];
        if (i <= other.iBac) KetQua.aDSHeSo[i] -= other.aDSHeSo[i];
    }
    return KetQua;

}
// Nạp chồng toán tử * để nhân 2 đa thức
DaThuc DaThuc::operator*(DaThuc other) {
    int bacMoi = iBac + other.iBac;
    DaThuc kq(bacMoi);
    for (int i = 0; i <= iBac; i++) {
        for (int j = 0; j <= other.iBac; j++) {
            kq.aDSHeSo[i + j] += aDSHeSo[i] * other.aDSHeSo[j];
        }
    }
    return kq;
}
// Nạp chồng toán tử == để so sánh 2 đa thức
bool DaThuc::operator==(DaThuc other) {
    if (iBac != other.iBac) return false;
    for (int i = 0; i <= iBac; i++) {
        if (aDSHeSo[i] != other.aDSHeSo[i]) return false;
    }
    return true;
}
// Nạp chồng toán tử nhập đa thức
istream& operator>>(istream& in, DaThuc& dt) {
    cout << "Nhap bac cua da thuc: ";
    in >> dt.iBac;
    dt.aDSHeSo.resize(dt.iBac + 1);
    for (int i = dt.iBac; i >= 0; i--) {
        cout << "He so x^" << i << ": ";
        in >> dt.aDSHeSo[i];
    }
    return in;
}
// Nạp chồng toán tử xuất đa thức
ostream& operator<<(ostream& out, DaThuc dt) {
    bool isEmpty = true;
    for (int i = dt.iBac; i >= 0; i--) {
        if (dt.aDSHeSo[i] == 0) continue; 
        isEmpty = false;
        cout << showpos << dt.aDSHeSo[i]; 
        if (i != 0) {
            if (i == 1) cout << "x"; 
            else cout << "x^" << noshowpos << i;
        }
    }
    if (isEmpty) cout << 0;
    cout << noshowpos;
    return out;
}