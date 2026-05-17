#include "CDate.h"
#include <iostream>
#include <cmath>
using namespace std;
// Khai báo ngày tối đa trong tháng thứ i, tiện lợi cho việc tra cứu
const int CDate::NgayTrongThang[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Phương thức thiết lập tích hợp cả mặc định và truyền tham số
CDate::CDate(int Ngay, int Thang, int Nam) {
	iNgay = Ngay;
	iThang = Thang;
	iNam = Nam;
	ChuanHoa();
}
// Hàm tính ngày trong tháng
int CDate::SoNgayTrongThang(int Thang, int Nam) {
	int extra = 0;
	if (Thang == 2 && ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0)) extra = 1;
	return NgayTrongThang[Thang] + extra;
}
// Hàm chuẩn hóa ngày tháng năm
void CDate::ChuanHoa() {
	// Đảm bảo tháng nằm trong khoảng từ 1 - 12
	while (iThang > 12) { iThang -= 12; iNam++; }
	while (iThang < 1) { iThang += 12; iNam--; }
	// Xử lý ngày quá số ngày trong tháng
	while (iNgay > SoNgayTrongThang(iThang, iNam)) {
		iNgay -= SoNgayTrongThang(iThang, iNam);
		iThang++;
		if (iThang > 12) { iThang = 1; iNam++; }
	}
	// Xử lý ngày bé hơn 1
	while (iNgay < 1) {
		iThang--;
		if (iThang < 1) { iThang = 12; iNam--; }
		iNgay += SoNgayTrongThang(iThang, iNam);
	}
}
// Nạp chồng toán tử + để cộng thêm một số ngày
CDate CDate::operator+(int Ngay) {
	return CDate(iNgay + Ngay, iThang, iNam);
}
// Nạp chồng toán tử - để trừ đi một số ngày
CDate CDate::operator-(int Ngay) {
	return CDate(iNgay - Ngay, iThang, iNam);
}
// Nạp chồng toán tử != để so sánh khác 2 ngày
bool CDate::operator!=(CDate date2) {
	return (iNgay != date2.iNgay || iThang != date2.iThang || iNam != date2.iNam);
}
// Nạp chồng toán tử - để tính khoảng cách giữa 2 CDate
int CDate::operator-(CDate date) {
	date.ChuanHoa();
	int count = 0;
	for (CDate date1 = *this, date2 = *this; date1 != date && date2 != date; date1++, date2--) {
		count++;
	}
	return count;
}
// Nạp chồng toán tử ++ (cộng trước, rồi gán vào biến)
CDate& CDate::operator++() {
	++iNgay;
	ChuanHoa();
	return *this;
}
// Nạp chồng toán tử ++ (trả về giá trị cũ, rồi mới cộng)
CDate CDate::operator++(int) {
	CDate old = *this;
	iNgay++;
	ChuanHoa();
	return old;
}
// Nạp chồng toán tử -- (trừ trước, rồi gán vào biến)
CDate& CDate::operator--() {
	--iNgay;
	ChuanHoa();
	return *this;
}
// Nạp chồng toán tử -- (trả về giá trị cũ, rồi mới trừ)
CDate CDate::operator--(int) {
	CDate old = *this;
	iNgay--;
	ChuanHoa();
	return old;
}
// Nạp chồng toán tử nhập ngày tháng năm
istream& operator>>(istream& in, CDate& date) {
	cout << "Nhap ngay: ";
	in >> date.iNgay;
	cout << "Nhap thang: ";
	in >> date.iThang;
	cout << "Nhap nam: ";
	in >> date.iNam;
	return in;
}
// Nạp chồng toán tử xuất ngày tháng năm
ostream& operator<<(ostream& out, CDate date) {
	out << date.iNgay << '/' << date.iThang << '/' << date.iNam;
	return out;
}