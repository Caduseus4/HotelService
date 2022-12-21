#pragma warning(disable : 4996)
#include <iostream>
#ifndef TEMIZLIK_CPP
#define TEMIZLIK_CPP
#include <fstream>
#include <ctime>
#include "List.cpp"
#include "Oda.cpp"
using namespace std;

class Temizlik 
{
	int islemiYapanId;
	List list;
public:

	Temizlik() {}

	//Ekstra temizlik fonksiyonu friend fonksiyon olarak tanýmlandý
	friend bool EkstraTemizlik(Oda* oda, bool ekstraTemizlik, string fileName);

	//Müsteri cikis yaptiktan sonra oda temizligi kontrolunu yapan fonksiyon
	bool CikisTemizlikKontrol(Oda* oda, string fileName) {
		if (oda->temizlik)
		{
			cout << "Cikis temizlik kontrol islemi basarili: Oda Temiz!";
			cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
			cin >> islemiYapanId;
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			list.pushBack("Temiz!", kontrolTarihi, islemiYapanId);

			return true;
		}
		else{
			cout << "Cikis temizlik kontrol islemi basarili: Oda Temiz Degil!";
			cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
			cin >> islemiYapanId;
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			list.pushBack("Temiz Degil!", kontrolTarihi, islemiYapanId);
			return false;
		}
		
	}

	//Ara temizlik islemi yapan 
	bool araTemizlik(Oda* oda,string fileName) {
		if (oda->temizlik == true)
		{
			cout << "Giris temizlik kontrol islemi basarili: Oda Temiz!";
			cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
			cin >> islemiYapanId;
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			list.pushBack("Temiz!", kontrolTarihi, islemiYapanId);
			return true;
		}
		else{
			cout << "Giris temizlik kontrol islemi basarili: Oda Temiz Degil!";
			cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
			cin >> islemiYapanId;
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			list.pushBack("Temiz!", kontrolTarihi, islemiYapanId);
			return false;
		}
	}
	void dosyaOlustur(string fileName){
		
		string fileLocation = "C:\\C++\\DonemProje\\HotelService\\Data\\" + fileName + ".txt";
		ofstream file(fileLocation);
		file.close();
		cout << "Dosya Olustu!"<<endl;
	}

	
	~Temizlik() {}

};

//Müsteri ekstra temizlik isterse bu fonksiyon çaðýrýlýr
bool EkstraTemizlik(Oda* oda) {
	int islemiYapanId;
	List list;
	const double ekstraTemizlikUcreti = 499999.99;
	if (oda->ekstraTemizlik == true)
	{
		cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
		cin >> islemiYapanId;
		time_t now = time(0);
		char* kontrolTarihi = ctime(&now);
		list.pushBack("Temiz Degil!", kontrolTarihi, islemiYapanId);
		return true;

	}
	else {
		return false;
	}

}
#endif