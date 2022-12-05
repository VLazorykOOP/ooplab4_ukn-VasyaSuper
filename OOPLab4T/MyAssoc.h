#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class IP_adress {
public:
	int IP[4];
	string desc;
	string location;
	int mask[4];
};

class DNS {
public:
	IP_adress ip;			 // Об'єкт типу IP_address
	string domain_name;      // Назва сайту
	string getAddress();     // Видати адресу
	string getMask();	     // Видати маску
	string getNetAddress();  // видати номер мережі
	string getUser();        // Видати номер вузла
	string getLocation();    // Видати місце знаходження
	string getDescription(); // Видати опис


	void setAddress(int a, int b, int c, int d); // Встановити ІП адрессу
	void setMask(int a, int b, int c, int d);	 // Встановити маску
	void setLocation(string& loc);				 // Встановити місце знаходження
	void setDescription(string& desc);		     // Встановити опис
		
	friend ostream& operator<<(ostream& os, DNS& obj); // Оператор виводу у порт виводу
};












