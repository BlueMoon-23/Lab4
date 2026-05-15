#include <iostream>
#include "SoPhuc.h"
using namespace std;

// Phương thức thiết lập cho phép thiết lập một số thực như một số phức đặc biệt
SoPhuc::SoPhuc(double Thuc, double Ao) {
	dThuc = Thuc;
	dAo = Ao;
}
// Nạp chồng toán tử cộng số phức này với số phức sp2
SoPhuc SoPhuc::operator+(SoPhuc sp2) {
	SoPhuc KetQua;
	KetQua.dThuc = dThuc + sp2.dThuc;
	KetQua.dAo = dThuc + sp2.dAo;
	return KetQua;
}
// Nạp chồng toán tử trừ số phức này với số phức sp2
SoPhuc SoPhuc::operator-(SoPhuc sp2) {
	SoPhuc KetQua;
	KetQua.dThuc = dThuc - sp2.dThuc;
	KetQua.dAo = dThuc - sp2.dAo;
	return KetQua;
}
// Nạp chồng toán tử nhân số phức này với số phức sp2
SoPhuc SoPhuc::operator*(SoPhuc sp2) {
	SoPhuc KetQua;
	KetQua.dThuc = dThuc * sp2.dThuc - dAo * sp2.dAo;
	KetQua.dAo = dThuc * sp2.dAo + sp2.dThuc * dAo;
	return KetQua;
}
// Nạp chồng toán tử chia số phức này với số phức sp2
SoPhuc SoPhuc::operator/(SoPhuc sp2) {
	SoPhuc KetQua;
	KetQua.dThuc = (dThuc * sp2.dThuc + dAo * sp2.dAo) / (sp2.dThuc * sp2.dThuc + sp2.dAo * sp2.dAo);
	KetQua.dAo = (sp2.dThuc * dAo - dThuc * sp2.dAo) / (sp2.dThuc * sp2.dThuc + sp2.dAo * sp2.dAo);
	return KetQua;
}
// Nạp chồng toán tử so sánh bằng giữa số phức này với số phức sp2
bool SoPhuc::operator==(SoPhuc sp2) {
	return dThuc == sp2.dThuc && dAo == sp2.dAo;
}
// Nạp chồng toán tử so sánh khác giữa số phức này với số phức sp2
bool SoPhuc::operator!=(SoPhuc sp2) {
	return dThuc != sp2.dThuc || dAo != sp2.dAo;
}
// Nạp chồng toán tử nhập số phức
istream& operator>>(istream& in, SoPhuc& sp) {
	cout << "Nhap phan thuc: ";
	in >> sp.dThuc;
	cout << "Nhap phan ao: ";
	in >> sp.dAo;
	return in;
}
// Nạp chồng toán tử xuất số phức
ostream& operator<<(ostream& out, SoPhuc sp) {
	out << noshowpos << sp.dThuc;
	// Nếu không có phần ảo thì không xuất thêm 'i' nữa
	if (sp.dAo == 0) return out;
	out << showpos << sp.dAo << "i";
	return out;
}