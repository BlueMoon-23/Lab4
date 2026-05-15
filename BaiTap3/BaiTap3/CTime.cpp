#include <iostream>
#include "CTime.h"
using namespace std;

// Phương thức thiết lập tích hợp cả mặc định và truyền tham số
CTime::CTime(int Gio, int Phut, int Giay) {
	iGio = Gio;
	iPhut = Phut;
	iGiay = Giay;
	ChuanHoa();
}
// Hàm chuẩn hóa thời gian
void CTime::ChuanHoa() {
	long int total = iGio * 3600 + iPhut * 60 + iGiay;
	if (total < 0) total = 0;
	iGio = (total / 3600) % 24;
	iPhut = (total % 3600) / 60;
	iGiay = total % 60;
}
// Nạp chồng toán tử + để cộng thêm một số nguyên giây
CTime CTime::operator+(int Giay) {
	return CTime(iGio, iPhut, iGiay + Giay);
}
// Nạp chồng toán tử - để trừ đi một số nguyên giây
CTime CTime::operator-(int Giay) {
	return CTime(iGio, iPhut, iGiay - Giay);
}
// Nạp chồng toán tử ++ (cộng trước, rồi gán vào biến)
CTime& CTime::operator++() {
	++iGiay;
	ChuanHoa();
	return *this;
}
// Nạp chồng toán tử -- (trừ trước, rồi gán vào biến)
CTime& CTime::operator--() {
	--iGiay;
	ChuanHoa();
	return *this;
}
// Nạp chồng toán tử ++ (trả về giá trị cũ, rồi mới cộng)
CTime CTime::operator++(int) {
	CTime old = *this;
	iGiay++;
	ChuanHoa();
	return old;
}
// Nạp chồng toán tử -- (trả về giá trị cũ, rồi mới trừ)
CTime CTime::operator--(int) {
	CTime old = *this;
	iGiay--;
	ChuanHoa();
	return old;
}
// Nạp chồng toán tử nhập thời gian
istream& operator>>(istream& in, CTime& time) {
	cout << "Nhap gio: ";
	in >> time.iGio;
	cout << "Nhap phut: ";
	in >> time.iPhut;
	cout << "Nhap giay: ";
	in >> time.iGiay;
	return in;
}
// Nạp chồng toán tử xuất thời gian
ostream& operator<<(ostream& out, CTime time) {
	out << time.iGio << ':' << time.iPhut << ':' << time.iGiay;
	return out;
}
