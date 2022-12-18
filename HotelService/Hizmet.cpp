#include <iostream>
#include <string>
using namespace std;
#ifndef HIZMET_CPP
#define HIZMET_CPP
class Hizmet
{
public:
	string islemiYapan;
	char* kontrolTarihi;
	
	Hizmet(string islemiYapan,char* kontrolTarihi) {
		this->islemiYapan = islemiYapan;
		this->kontrolTarihi = kontrolTarihi;
	}

	Hizmet(){}

};
#endif 
