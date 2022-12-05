#include <iostream>
#include "Lab4Exmaple.h"
#include "ComplexVector.h"
#include "ComplexMatrix.h"
#include "MyAssoc.h"

int mainExample1() {
	VectorDouble B1(4, 10), B2(4, 50), B3(4, 5.5);
	VectorDouble A1, A2(5), A3(4, 5);
	std::cout << "Конструктор без параметрів: \n";
	A1.Output(); 
	std::cout << "\nКонструктор з одним параметром: \n";
	A2.Output();
	std::cout << "\nКонструктор з двома параметрами: \n";
	A3.Output();
	std::cout << "\nУнарний префікс ++: \n";
	A3++;
	A3.Output();
	std::cout << "\nУнарний постфікс --: \n";
	A3--;
	A3.Output();
	std::cout << "\nУнарне логічне ! : \n";
	std::cout << !A3;
	std::cout << "\nУнарний арифметичний - : \n";
	-A3;
	A3.Output();
	std::cout << "\nПрисвоєння: копіює вектор : \n";
	A3 = B2;
	A3.Output();
	std::cout << "\nДодавання двох векторів: \n";
	A3 = B1 + B2;
	A3.Output();
	std::cout << "\nДодавання вектора і скаляра типу double: \n";
	A3 = B1 + 90;
	A3.Output();
	std::cout << "\nВіднімання двох векторів: \n";
	A3 = B2 - B1;
	A3.Output();
	std::cout << "\nВіднімання вектора і скаляра типу double: \n";
	A3 = B2 - 30;
	A3.Output();
	std::cout << "\nМноження вектора і скаляра типу int: \n";
	A3 = B2 * 10;
	A3.Output();
	std::cout << "\nМноження вектора і скаляра типу double: \n";
	A3 = B2 * 2.4;
	A3.Output();
	std::cout << "\nДілення вектора і скаляра типу int: \n";
	A3 = B2 / 10;
	A3.Output();
	std::cout << "\nДілення вектора і скаляра типу double: \n";
	A3 = B2 / 2.5;
	A3.Output();
	std::cout << "\nПрисвоєння з додаванням двох векторів: \n";
	A3 += B2;
	A3.Output();
	std::cout << "\nПрисвоєння з додаванням для вектора і скаляра типу int: \n";
	A3 += 10;
	A3.Output();
	std::cout << "\nПрисвоєння з додаванням для вектора і скаляра типу float: \n";
	A3 += (float)2.2;
	A3.Output();
	std::cout << "\nПрисвоєння з відніманням двох векторів: \n";
	A3 -= B1;
	A3.Output();
	std::cout << "\nПрисвоєння з відніманням для вектора і скаляра типу int: \n";
	A3 -= 10;
	A3.Output();
	std::cout << "\nПрисвоєння з відніманням для вектора і скаляра типу float: \n";
	A3 -= (float)2.2;
	A3.Output();
	std::cout << "\nПрисвоєння з множення для вектора і скаляра типу int: \n";
	A3 *= 3;
	A3.Output();
	std::cout << "\nПрисвоєння з множення для вектора і скаляра типу float: \n";
	A3 *= (float)2.2;
	A3.Output();
	std::cout << "\nПрисвоєння з ділення для вектора і скаляра типу int: \n";
	A3 /= 3;
	A3.Output();
	std::cout << "\nOперацію індексації: \n";
	std::cout << A3[3] << "\n";

	return 1;
}
int mainExample2() {

	MatrixDouble A1(3), A2(3, 5), A3(3, 5, 15);
	MatrixDouble B2(3, 2), B4(3, 5, 20), B5(3, 5, 0), B6(5, 3, 2),B3(A3);
	std::cout << "Конструктор без параметрів: \n";
	A1.OutputMat();
	std::cout << "Конструктор з двома параметрами: \n";
	A2.OutputMat();
	std::cout << "Конструктор з трьома параметрами: \n";
	A3.OutputMat();
	std::cout << "Конструктор копій: \n";
	B3.OutputMat();
	std::cout << "n : ";
	std::cout << A3.GetN();
	std::cout << "\nsize : ";
	std::cout << A3.GetSIZE();
	std::cout << "\ncodeError : ";
	std::cout << A3.GetCodeError();
	std::cout << "\n";
	std::cout << "Унарних префікс ++: \n";
	A3++;
	A3.OutputMat();
	std::cout << "Унарних постфікс --: \n";
	A3--;
	A3.OutputMat();
	std::cout << "\nУнарне логічне ! : \n";
	std::cout << !A3;
	std::cout << "\n";
	std::cout << "\nУнарний арифметичний - : \n";
	-A3;
	A3.OutputMat();
	std::cout << "\nПрисвоєння: копіює вектор : \n";
	B4 = A3;
	B4.OutputMat();
	std::cout << "Додавання для двох матриць : \n";
	(A3 + B4).OutputMat();
	std::cout << "Додавання для матриці та скаляра типу int : \n";
	(A3 + 10).OutputMat();
	std::cout << "Додавання для матриці та скаляра типу float : \n";
	(A3 + (float)2.5).OutputMat();
	std::cout << "Віднімання для двох матриць : \n";
	(A3 - B4).OutputMat();
	std::cout << "Віднімання для матриці та скаляра типу int : \n";
	(A3 - 10).OutputMat();
	std::cout << "Віднімання для матриці та скаляра типу float : \n";
	(A3 - (float)2.5).OutputMat();
	std::cout << "Множення для матриці та скаляра типу float : \n";
	(B4 * 50).OutputMat();
	std::cout << "Ділення для матриці та скаляра типу int : \n";
	(B4 / 5).OutputMat();
	std::cout << "Присвоєння додавання для двох матриць : \n";
	(B4 += A3).OutputMat();
	std::cout << "Присвоєння додавання для матриці та скаляра типу float : \n";
	(B4 += (float)2.3).OutputMat();
	std::cout << "Присвоєння віднімання для двох матриць : \n";
	(B4 -= A3).OutputMat();
	std::cout << "Присвоєння віднімання для матриці та скаляра типу float : \n";
	(B4 -= (float)2.3).OutputMat(); 
	std::cout << "Присвоєння множення для матриці та скаляра типу float : \n";
	(B4 *= (float)2.3).OutputMat(); 
	std::cout << "Присвоєння ділення для матриці та скаляра типу float : \n";
	(B4 /= 5).OutputMat(); 
	std::cout << "\nOперацію індексації: \n";
	std::cout << A3[3] << "\n";

	return 2;
}
int mainExample3() {
	DNS dns1;

	dns1.domain_name = "chicagoGroup.xyz";
	string loc = "Chicago, route n.53";
	string desc = "West IP network, 49 users active now";

	dns1.setAddress(192, 168, 53, 1);
	dns1.setMask(255, 255, 255, 0);
	dns1.setLocation(loc);
	dns1.setDescription(desc);


	cout << dns1;

	return 3;
}

