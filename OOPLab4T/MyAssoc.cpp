#include "MyAssoc.h"

	
string DNS::getAddress() {
	string tmp;
	tmp = ip.IP[0] + ip.IP[1] + ip.IP[2] + ip.IP[3];
	return tmp;
}

string DNS::getNetAddress() {
	string tmp;
	tmp = ip.IP[0] & ip.mask[0] + ip.IP[1] & ip.mask[1] + 
		  ip.IP[2] & ip.mask[2] + ip.IP[3] & ip.mask[3];

	return tmp;
}

string DNS::getUser(){
	string tmp;
	tmp = ip.IP[0] & !ip.mask[0] + ip.IP[1] & !ip.mask[1] +
		ip.IP[2] & !ip.mask[2] + ip.IP[3] & !ip.mask[3];

	return tmp;
}

string DNS::getLocation()
{
	return ip.location;
}

string DNS::getDescription()
{
	return ip.desc;
}

void DNS::setAddress(int a, int b, int c, int d) {
	ip.IP[0] = a;
	ip.IP[1] = b;
	ip.IP[2] = c;
	ip.IP[3] = d;
}

void DNS::setMask(int a, int b, int c, int d) {
	ip.mask[0] = a;
	ip.mask[1] = b;
	ip.mask[2] = c;
	ip.mask[3] = d;
}

void DNS::setLocation(string& loc){
	ip.location = loc;
}

void DNS::setDescription(string& desc)
{
	ip.desc = desc;
}


string DNS::getMask() {
	string tmp;
	tmp = ip.mask[0] + ip.mask[1] + ip.mask[2] + ip.mask[3];
	return tmp;
}

ostream& operator<<(ostream& os, DNS& obj)
{
	os << "Domain name : " << obj.domain_name << "\n" <<
		"IP : " << obj.ip.IP[0] << "." << obj.ip.IP[1] << "." << obj.ip.IP[2] << "." << obj.ip.IP[3] << "\n" <<
		"Mask : " << obj.ip.mask[0] << "." << obj.ip.mask[1] << "." << obj.ip.mask[2] << "." << obj.ip.mask[3] << "\n" <<
		"Net address : " << (obj.ip.IP[0] & obj.ip.mask[0]) << "." << (obj.ip.IP[1] & obj.ip.mask[1]) << "." << (obj.ip.IP[2] & obj.ip.mask[2]) << "." << (obj.ip.IP[3] & obj.ip.mask[3]) << "\n" <<
		"User address : " << (obj.ip.IP[0] & !obj.ip.mask[0]) << "." << (obj.ip.IP[1] & !obj.ip.mask[1]) << "." << (obj.ip.IP[2] & !obj.ip.mask[2]) << "." << (obj.ip.IP[3] & !obj.ip.mask[3]) << "\n" <<
		"Location : " << obj.ip.location << "\n" <<
		"Description : " << obj.ip.desc << "\n";

	return os;
}
