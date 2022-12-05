#include "ComplexMatrix.h"
#include "ComplexVector.h"
#include <math.h>

const double range = 1.e-5;

MatrixDouble::MatrixDouble(int n1) {
	if (n < 0 || n > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		n = n1;
		DoubleArray = new VectorDouble[n];
		for (int i = 0; i < n; i++) {
			DoubleArray[i] = VectorDouble(n);
		}
	}
}
MatrixDouble::MatrixDouble(int n1, int size1) {
	if (n < 0 || n > 1.e+100 || size1 < 0 || size1 > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		n = n1;
		size = size1;
		DoubleArray = new VectorDouble[n];
		for (int i = 0; i < n; i++) {
			DoubleArray[i] = VectorDouble(size1);
		}
	}
}
MatrixDouble::MatrixDouble(int n1, int size1, double a){
	if (n < 0 || n > 1.e+100 || size1 < 0 || size1 > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		n = n1;
		size = size1;
		DoubleArray = new VectorDouble[n];
		for (int i = 0; i < n; i++) {
			DoubleArray[i] = VectorDouble(size1, a);
		}
	}
}
MatrixDouble::MatrixDouble(const MatrixDouble* s){
	n = s->n;
	DoubleArray = new VectorDouble[n];
	for (int i = 0; i < n; i++) 
		DoubleArray[i] = s->DoubleArray[i];
	codeError = s->codeError;
}
double MatrixDouble::GetN() {
	return n;
}
double MatrixDouble::GetSIZE() {
	return size;
}
double MatrixDouble::GetCodeError() {
	return codeError;
}
MatrixDouble& MatrixDouble::operator++(int) {
	for (int i = 0; i < n; i++) DoubleArray[i]++;
	return *this;
}
MatrixDouble& MatrixDouble::operator--(int) {
	for (int i = 0; i < n; i++) DoubleArray[i]--;
	return *this;
}
bool MatrixDouble::operator!() const {
	for (int i = 0; i < n; i++)
		if (!DoubleArray[i] == false)
			return false;
		else
			return true;
}
MatrixDouble MatrixDouble::operator-() {
	for (int i = 0; i < n; i++) -DoubleArray[i];
	return *this;
}
MatrixDouble& MatrixDouble::operator=(MatrixDouble& s) {
	for (int i = 0; i < n; i++) DoubleArray[i] = s.DoubleArray[i];
	return *this;
}
MatrixDouble MatrixDouble::operator+(MatrixDouble b) {
	for (int i = 0; i < n; i++)  DoubleArray[i] += b.DoubleArray[i];
	return *this;
}
MatrixDouble MatrixDouble::operator+(int b) {
	for (int i = 0; i < n; i++) DoubleArray[i] += b;
	return *this;
}
MatrixDouble MatrixDouble::operator+(float b) {
	for (int i = 0; i < n; i++) DoubleArray[i] += b;
	return *this;
}
MatrixDouble MatrixDouble::operator-(MatrixDouble b) {
	for (int i = 0; i < n; i++)  DoubleArray[i] -= b.DoubleArray[i];
	return *this;
}
MatrixDouble MatrixDouble::operator-(int b) {
	for (int i = 0; i < n; i++) DoubleArray[i] -= b;
	return *this;
}
MatrixDouble MatrixDouble::operator-(float b) {
	for (int i = 0; i < n; i++) DoubleArray[i] -= b;
	return *this;
}
MatrixDouble MatrixDouble::operator*(float b) {
	for (int i = 0; i < n; i++) DoubleArray[i] *= b;
	return *this;
}
MatrixDouble MatrixDouble::operator/(int b) {
	for (int i = 0; i < n; i++) DoubleArray[i] /= b;
	return *this;
}
MatrixDouble MatrixDouble::operator+=(MatrixDouble b) {
	for (int i = 0; i < n; i++)  DoubleArray[i] += b.DoubleArray[i];
	return *this;
}
MatrixDouble MatrixDouble::operator+=(float b) {
	for (int i = 0; i < n; i++) DoubleArray[i] += b;
	return *this;
}
MatrixDouble MatrixDouble::operator-=(MatrixDouble b) {
	for (int i = 0; i < n; i++)  DoubleArray[i] -= b.DoubleArray[i];
	return *this;
}
MatrixDouble MatrixDouble::operator-=(float b) {
	for (int i = 0; i < n; i++) DoubleArray[i] -= b;
	return *this;
}
MatrixDouble MatrixDouble::operator*=(float b) {
	for (int i = 0; i < n; i++) DoubleArray[i] *= b;
	return *this;
}
MatrixDouble MatrixDouble::operator/=(int b) {
	for (int i = 0; i < n; i++) DoubleArray[i] /= b;
	return *this;
}

double& MatrixDouble::operator[](int index) {
	if (index >= 0 || index < size) {
		double DD = DoubleArray[0].GetVec(index);
		return DD;
	}
	else {
		cout << " Error : operator[] - index out of range \n";;
		codeError = 1;
		double Dd = DoubleArray[0].GetVec(0);
		return Dd;
	}
}

void MatrixDouble::OutputMat() {

	for (int i = 0; i < n; i++) {
		std::cout << "   ";
		DoubleArray[i].Output(); 
		std::cout << "\n";
	}

}