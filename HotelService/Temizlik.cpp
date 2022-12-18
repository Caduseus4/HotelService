#include <iostream>
#ifndef TEMIZLIK_CPP
#define TEMIZLIK_CPP


#include "Oda.cpp"
using namespace std;

class Temizlik 
{
public:

	Temizlik() {}

	//Ekstra temizlik fonksiyonu friend fonksiyon olarak tan�mland�
	friend bool EkstraTemizlik(Oda* oda, bool ekstraTemizlik);

	//M�steri cikis yaptiktan sonra oda temizligi kontrolunu yapan fonksiyon
	bool CikisTemizlikKontrol(Oda* oda) {
		if (oda->temizMis)
		{
			cout << "Cikis temizlik kontrol islemi basarili: Oda Temiz!";
			return true;
		}
		else{
			cout << "Cikis temizlik kontrol islemi basarili: Oda Temiz Degil!";
			return false;
		}
		
	}

	//Ara temizlik islemi yapan 
	bool araTemizlik(Oda* oda) {
		if (oda->temizMis == true)
		{
			cout << "Giris temizlik kontrol islemi basarili: Oda Temiz!";
			return true;
		}
		else{
			cout << "Giris temizlik kontrol islemi basarili: Oda Temiz Degil!";
			return false;
		}
	}


	
	~Temizlik() {}

};

//M�steri ekstra temizlik isterse bu fonksiyon �a��r�l�r
bool EkstraTemizlik(Oda* oda) {

	const double ekstraTemizlikUcreti = 499999.99;
	if (oda->ekstraTemizlik == true)
	{
		return true;
	}
	else {
		return false;
	}

}
#endif