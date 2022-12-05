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
	IP_adress ip;			 // ��'��� ���� IP_address
	string domain_name;      // ����� �����
	string getAddress();     // ������ ������
	string getMask();	     // ������ �����
	string getNetAddress();  // ������ ����� �����
	string getUser();        // ������ ����� �����
	string getLocation();    // ������ ���� �����������
	string getDescription(); // ������ ����


	void setAddress(int a, int b, int c, int d); // ���������� �� �������
	void setMask(int a, int b, int c, int d);	 // ���������� �����
	void setLocation(string& loc);				 // ���������� ���� �����������
	void setDescription(string& desc);		     // ���������� ����
		
	friend ostream& operator<<(ostream& os, DNS& obj); // �������� ������ � ���� ������
};












