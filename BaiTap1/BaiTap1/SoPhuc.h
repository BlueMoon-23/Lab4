#include <iostream>
using namespace std;
#pragma once
class SoPhuc
{
private:
	double dThuc, dAo;
public:
	SoPhuc(double Thuc = 0, double Ao = 0);
	SoPhuc operator+(SoPhuc sp2);
	SoPhuc operator-(SoPhuc sp2);
	SoPhuc operator*(SoPhuc sp2);
	SoPhuc operator/(SoPhuc sp2);
	bool operator==(SoPhuc sp2);
	bool operator!=(SoPhuc sp2);
	friend istream& operator>>(istream& in, SoPhuc & sp);
	friend ostream& operator<<(ostream& out, SoPhuc sp);
};


