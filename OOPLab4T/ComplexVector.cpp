#include "ComplexVector.h"

const double range = 1.e-5;

VectorDouble::VectorDouble(int n) {
	if (n <= 0) n = 1;
	num = n;
	Vec = new double[n];
	for (int i = 0; i < n; i++) {
		Vec[i] = 0.0;
	}
}
VectorDouble::VectorDouble(int n, double b) : VectorDouble(n) {
	for (int i = 0; i < num; i++) {
		Vec[i] = b;
	}
}
VectorDouble::VectorDouble(VectorDouble& s){
	num = s.num;
	Vec = new double[num];
	for (int i = 0; i < num; i++) {
		Vec[i] = s.Vec[i];
	}
}
VectorDouble::VectorDouble(VectorDouble&& s) {
	num = s.num;
	Vec = new double[num];
	for (int i = 0; i < num; i++) {
		Vec[i] = s.Vec[i];
	}
}
VectorDouble& VectorDouble::operator++(int){
	for (int i = 0; i < num; i++) Vec[i] += 1;
	return *this;
}
VectorDouble& VectorDouble::operator--(int) {
	for (int i = 0; i < num; i++) Vec[i] -= 1;
	return *this;
}
bool VectorDouble::operator!() const {  // true : exist v[i] != 0{
	for (int i = 0; i < num; i++)
		if (fabs(Vec[i]) > range)
			return true;
	return false;
}
VectorDouble VectorDouble::operator-(){
	VectorDouble tmp(*this);

	for (int i = 0; i < num; i++)
		tmp[i] = -Vec[i];
	for (int i = 0; i < num; i++)
		Vec[i] = tmp[i];
	return *this;
}
VectorDouble& VectorDouble::operator=(VectorDouble& s) {
	if (this == &s) return *this;
	if (num != s.num){
		if (Vec) delete[] Vec;
		num = s.num;
		Vec = new double[num];
		codeError = 1;
	}
	for (int i = 0; i < num; i++)   Vec[i] = s.Vec[i];
	return *this;
}
VectorDouble& VectorDouble::operator=(VectorDouble&& s) {
	if (this == &s) return *this;
	if (num != s.num) {
		if (Vec) delete[] Vec;
		num = s.num;
		Vec = new double[num];
		codeError = 1;
	}
	for (int i = 0; i < num; i++)   Vec[i] = s.Vec[i];
	return *this;
}
VectorDouble VectorDouble::operator+(VectorDouble b){
	VectorDouble tmp(*this);
	tmp += b;
	return tmp;
}
VectorDouble VectorDouble::operator+(double b) {
	VectorDouble tmp(*this);
	for (int i = 0; i < num; i++) tmp[i] += b;
	return tmp;
}
VectorDouble VectorDouble::operator-(VectorDouble b){
	VectorDouble tmp(*this);
	tmp -= b;
	return tmp;
}
VectorDouble VectorDouble::operator-(double b) {
	VectorDouble tmp(*this);
	for (int i = 0; i < num; i++) tmp[i] -= b;
	return tmp;
}
VectorDouble VectorDouble::operator*(int b) {
	VectorDouble tmp(*this);
	for (int i = 0; i < num; i++) tmp[i] *= b;
	return tmp;
}
VectorDouble VectorDouble::operator*(double b) {
	VectorDouble tmp(*this);
	for (int i = 0; i < num; i++) tmp[i] *= b;
	return tmp;
}
VectorDouble VectorDouble::operator/(int b) {
	VectorDouble tmp(*this);
	for (int i = 0; i < num; i++) tmp[i] /= b;
	return tmp;
}
VectorDouble VectorDouble::operator/(double b) {
	VectorDouble tmp(*this);
	for (int i = 0; i < num; i++) tmp[i] /= b;
	return tmp;
}
VectorDouble& VectorDouble::operator+=(VectorDouble& b){
	int i;
	if (num == b.num) 
		for (i = 0; i < num; i++) Vec[i] += b.Vec[i];
	else{
		cout << " Warning: vectors of different sizes are used in operation += \n";
	}
	return *this;
}
VectorDouble& VectorDouble::operator+=(VectorDouble&& b) {
	int i;
	if (num == b.num)
		for (i = 0; i < num; i++) Vec[i] += b.Vec[i];
	else {
		cout << " Warning: vectors of different sizes are used in operation += \n";
	}
	return *this;
}
VectorDouble& VectorDouble::operator+=(int b){
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] += b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator+=(float b){
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] += b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator-=(VectorDouble& b){
	int i;
	if (num == b.num) for (i = 0; i < num; i++) Vec[i] -= b.Vec[i];
	else {
		cout << " Warning: vectors of different sizes are used in operation -= \n";
	}
	return *this;
}
VectorDouble& VectorDouble::operator-=(VectorDouble&& b) {
	int i;
	if (num == b.num) for (i = 0; i < num; i++) Vec[i] -= b.Vec[i];
	else {
		cout << " Warning: vectors of different sizes are used in operation -= \n";
	}
	return *this;
}
VectorDouble& VectorDouble::operator-=(int b){
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] -= b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator-=(float b){
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] -= b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator*=(int b) {
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] *= b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator*=(float b) {
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] *= b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator/=(int b) {
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] /= b;
	}
	return *this;
}
double& VectorDouble::operator[](int index) {
	if (index >= 0 || index < num)
		return Vec[index];
	else {
		cout << " Error : operator[] - index out of range \n";;
		codeError = 1;
		return Vec[0];
	}
}
void VectorDouble::Output() {
	if (num != 0) {
		for (int i = 0; i < num; i++) {
			cout << Vec[i] << "     ";
		}
	}
}
double VectorDouble::GetNum() {
	return num;
}
double VectorDouble::GetVec(int k) {
	return Vec[k];
}