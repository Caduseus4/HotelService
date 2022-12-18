#include <iostream>
#include <string>
using namespace std;
#ifndef HIZMET_CPP
#define HIZMET_CPP
class Hizmet
{
public:
	string kontrolEden, kontrolSaati;
	
	Hizmet(string kontrolEden,string kontrolSaati) {
		this->kontrolEden = kontrolEden;
		this->kontrolSaati = kontrolSaati;
	}

	Hizmet(){}

};
#endif 
