#include "PhanSo.h"
#include <cmath>

// Tìm ước chung lớn nhất
int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}
// Ham rút gọn phân số
void PhanSo::RutGon() {
    int ucln = UCLN(iTu, iMau);
    iTu /= ucln;
    iMau /= ucln;
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}
// Phương thức thiết lập cho phép một số nguyên như một phân số đặc biệt
PhanSo::PhanSo(int iTu, int iMau) {
    this->iTu = iTu;
    this->iMau = iMau;
    this->RutGon();
}
// Nạp chồng toán tử cộng hai phân số
PhanSo PhanSo::operator+(PhanSo ps2) {
    PhanSo KetQua;
    KetQua.iTu = this->iTu * ps2.iMau + ps2.iTu * this->iMau;
    KetQua.iMau = this->iMau * ps2.iMau;
    KetQua.RutGon();
    return KetQua;
}
// Nạp chồng toán tử trừ hai phân số
PhanSo PhanSo::operator-(PhanSo ps2) {
    PhanSo KetQua;
    KetQua.iTu = this->iTu * ps2.iMau - ps2.iTu * this->iMau;
    KetQua.iMau = this->iMau * ps2.iMau;
    KetQua.RutGon();
    return KetQua;
}
// Nạp chồng toán tử nhân hai phân số
PhanSo PhanSo::operator*(PhanSo ps2) {
    PhanSo KetQua;
    KetQua.iTu = this->iTu * ps2.iTu;
    KetQua.iMau = this->iMau * ps2.iMau;
    KetQua.RutGon();
    return KetQua;
}
// Nạp chồng toán tử chia hai phân số
PhanSo PhanSo::operator/(PhanSo ps2) {
    PhanSo KetQua;
    KetQua.iTu = this->iTu * ps2.iMau;
    KetQua.iMau = this->iMau * ps2.iTu;
    KetQua.RutGon();
    return KetQua;
}
// Nạp chồng toán tử so sánh bằng giữa hai phân số
bool PhanSo::operator==(PhanSo ps2) {
    return (this->iTu * ps2.iMau == ps2.iTu * this->iMau);
}
// Nạp chồng toán tử so sánh bé hơn giữa hai phân số
bool PhanSo::operator>(PhanSo ps2) {
    return (double)this->iTu / this->iMau > (double)ps2.iTu / ps2.iMau;
}
// Nạp chồng toán tử so sánh lớn hơn giữa hai phân số
bool PhanSo::operator<(PhanSo ps2) {
    return (double)this->iTu / this->iMau < (double)ps2.iTu / ps2.iMau;
}
// Nạp chồng toán tử nhập phân số
istream& operator>>(istream& in, PhanSo& ps) {
    cout << "Nhap tu so: ";
    in >> ps.iTu;
    cout << "Nhap mau so: ";
    in >> ps.iMau;
    if (ps.iMau == 0) ps.iMau = 1;
    ps.RutGon();
    return in;
}
// Nạp chồng toán tử xuất phân số
ostream& operator<<(ostream& out, PhanSo ps) {
    if (ps.iTu == 0) out << 0;
    else if (ps.iMau == 0) cout << "Phan so khong hop le.";
    else if (ps.iMau == 1) out << ps.iTu;
    else out << ps.iTu << "/" << ps.iMau;
    return out;
}