#include <iostream>
#include <string>
using namespace std;
#ifndef HIZMET_CPP
#define HIZMET_CPP
class Hizmet
{
public:
	int islemiYapanId;
	char* kontrolTarihi;
	
	//Hizmet classinin parametreli constructori
	Hizmet(int islemiYapanId,char* kontrolTarihi) {
		this->islemiYapanId = islemiYapanId;
		this->kontrolTarihi = kontrolTarihi;
	}


	//Hizmet classinin parametresiz constructori
	Hizmet(){}

};
#endif 
