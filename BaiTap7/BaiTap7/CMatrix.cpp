#include "CMatrix.h"
#include <iostream>
#include <vector>
using namespace std;

// Phương thức thiết lập tích hợp cả mặc định và truyền tham số
CMatrix::CMatrix(int Dong, int Cot) {
	iSoDong = Dong;
	iSoCot = Cot;
	MaTran.resize(iSoDong, vector<double>(iSoCot));
}
// Nạp chồng toán tử + để cộng hai ma trận có cùng kích thước
CMatrix CMatrix::operator+(CMatrix other) {
	if (iSoDong != other.iSoDong || iSoCot != other.iSoCot) {
		cout << "(Hai ma tran nay khong the cong voi nhau duoc)\n";
		return CMatrix(0, 0);
	}
	CMatrix KetQua(iSoDong, iSoCot);
	for (int i = 0; i < iSoDong; i++) {
		for (int j = 0; j < iSoCot; j++) {
			KetQua.MaTran[i][j] = MaTran[i][j] + other.MaTran[i][j];
		}
	}
	return KetQua;
}
// Nạp chồng toán tử + để cộng hai ma trận có cùng kích thước
CMatrix CMatrix::operator-(CMatrix other) {
	if (iSoDong != other.iSoDong || iSoCot != other.iSoCot) {
		cout << "(Hai ma tran nay khong the tru cho nhau duoc)\n";
		return CMatrix(0, 0);
	}
	CMatrix KetQua(iSoDong, iSoCot);
	for (int i = 0; i < iSoDong; i++) {
		for (int j = 0; j < iSoCot; j++) {
			KetQua.MaTran[i][j] = MaTran[i][j] - other.MaTran[i][j];
		}
	}
	return KetQua;
}
// Nạp chồng toán tử nhập ma trận
istream& operator>>(istream& in, CMatrix& mt) {
	cout << "Nhap so dong: ";
	in >> mt.iSoDong;
	cout << "Nhap so cot: ";
	in >> mt.iSoCot;
	cout << "Nhap ma tran:\n";
	mt.MaTran.resize(mt.iSoDong, vector<double>(mt.iSoCot));
	for (int i = 0; i < mt.iSoDong; i++) {
		for (int j = 0; j < mt.iSoCot; j++) {
			in >> mt.MaTran[i][j];
		}
	}
	return in;
}
// Nạp chồng toán tử xuất ma trận
ostream& operator<<(ostream& out, CMatrix mt) {
	for (int i = 0; i < mt.iSoDong; i++) {
		for (int j = 0; j < mt.iSoCot; j++) {
			cout << mt.MaTran[i][j] << ' ';
		}
		cout << '\n';
	}
	return out;
}
// Hàm tính tích của ma trận với vector
CMatrix CMatrix::TinhTich(vector<double> v) {
	if (iSoCot != (int)v.size()) {
		cout << "(Vector khong nhan duoc voi ma tran nay)\n";
		return CMatrix(0, 0);
	}
	CMatrix KetQua(iSoDong, 1);
	for (int i = 0; i < iSoDong; i++) {
		double Tong = 0;
		for (int j = 0; j < iSoCot; j++) {
			Tong += MaTran[i][j] * v[j];
		}
		KetQua.MaTran[i][0] = Tong;
	}
	return KetQua;
}
// Hàm tính tích giữa hai ma trận
CMatrix CMatrix::TinhTich(CMatrix other) {
	if (iSoCot != other.iSoDong) {
		cout << "(Hai ma tran nay khong the nhan voi nhau duoc)\n";
		return CMatrix(0, 0);
	}
	CMatrix KetQua(iSoDong, other.iSoCot);
	for (int i = 0; i < iSoDong; i++) {
		for (int j = 0; j < other.iSoCot; j++) {
			double tong = 0.0;
			for (int k = 0; k < iSoCot; k++) {
				tong += MaTran[i][k] * other.MaTran[k][j];
			}
			KetQua.MaTran[i][j] = tong;
		}
	}
	return KetQua;
}