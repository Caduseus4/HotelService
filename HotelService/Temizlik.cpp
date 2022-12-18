#include <iostream>
#ifndef TEMIZLIK_CPP
#define TEMIZLIK_CPP


#include "Oda.cpp"
using namespace std;

class Temizlik 
{
public:

	Temizlik() {}

	//Ekstra temizlik fonksiyonu friend fonksiyon olarak tanımlandı
	friend bool EkstraTemizlik(Oda* oda, bool ekstraTemizlik);

	//Müsteri cikis yaptiktan sonra oda temizligi kontrolunu yapan fonksiyon
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

//Müsteri ekstra temizlik isterse bu fonksiyon çağırılır
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