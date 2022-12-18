#pragma warning(disable : 4996)
#include <iostream>
#ifndef ODASERVISI_CPP
#define ODASERVISI_CPP
#include "Oda.cpp"
#include "List.cpp"
#include "Hizmet.cpp"
#include <fstream>
#include <ctime>
using namespace std;

class OdaServisi : public Hizmet{
	string odaNo;
	int islemiYapanId;
protected:
	double fiyat;
public:
	string gida,gida1;
	List list;
	List list1;

	// OdaServisi classinin constructori parametreli
	OdaServisi(string odaNo, int islemiYapanId, char* kontrolTarihi) : Hizmet(islemiYapanId, kontrolTarihi) {
		this->odaNo = odaNo;
	}

	// OdaServisi classinin constructori parametresiz
	OdaServisi(){}

	
	// Dosya olusturma fonksiyonu
	void dosyaOlustur(string fileName){
		
		string fileLocation = "C:\\C++\\DonemProje\\HotelService\\Data\\" + fileName + ".txt";
		ofstream file(fileLocation);
		file.close();
		cout << "Dosya Olustu!"<<endl;
	}

	
	// Acik bufeye gida ekleme fonksiyonu
	void acikBufeGidaEkle() {
		cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
		cin >> islemiYapanId;



		while (gida != "0") {
			cout << "Gidayi Giriniz(Ekleme isleminden cikmak icin 0'a basin):";
			cin >> gida;
			if (gida != "0")
			{
				
				time_t now = time(0);
				char* kontrolTarihi = ctime(&now);
				list.pushBack(gida,kontrolTarihi,islemiYapanId);
				
			}


		}

		acikBufeGidaEkleText("AcikBufeGidaList");
		cout << endl;
	}

	// acikBufeGidaEkle fonksiyonunun kullanabilmesi icin texte gidalari yazdiran fonksiyon
	void acikBufeGidaEkleText(string fileName) {

		string fileLocation = "C:\\C++\\DonemProje\\HotelService\\Data\\" + fileName + ".txt";
		ofstream file(fileLocation, ios::app);

				Node* tmp = list.begin();
				file << "\nIslemi Yapan Kisinin ID'si: " << tmp->islemiYapanId << endl;
				while (tmp != list.end()) {

					file << tmp->data << " | Islem Tarihi: " << tmp->kontrolTarihi ;
					tmp = tmp->next;
					
				}
				file.close();
				
	}
	
	// Acik bufeye eklenen gidalari yazdirir
	void acikBufeGidaYazdir() {
		cout << "Acik bufedeki gidalar:\n";

		Node* tmp = list.begin();
		while (tmp != list.end()) {
			cout << tmp->data<< endl;
			tmp = tmp->next;
		}

	}

	// Mini bara gida ekleme fonksiyonu
	void miniBarGidaEkle() {
		cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
		cin >> islemiYapanId;

		while (gida1 != "0") {
			cout << "Gidayi giriniz(Ekleme isleminden cikmak icin 0'e basin):";
			cin >> gida1;
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			if (gida1 != "0")
			{

				cout << "Eklediginiz gidanin fiyatini giriniz:";
				cin >> fiyat;
				list1.pushBack(gida1, kontrolTarihi , islemiYapanId,fiyat);

			}
		}
		miniBarGidaEkleText("MiniBarGidaList");
		cout << endl;
	}

	// miniBarGidaEkle fonksiyonunun kullanabilmesi icin texte gidalari yazdiran fonksiyon
	void miniBarGidaEkleText(string fileName) {

		string fileLocation = "C:\\C++\\DonemProje\\HotelService\\Data\\" + fileName + ".txt";
		ofstream file(fileLocation, ios::app);

		Node* tmp = list1.begin();
		file << "\nIslemi Yapan Kisinin ID'si: " << tmp->islemiYapanId << endl;
		while (tmp != list1.end()) {
			file << tmp->data << " Fiyati:" << tmp->fiyat <<" | Islem Tarihi: " << tmp->kontrolTarihi ;
			tmp = tmp->next;
		}
		file.close();
		
	}

	// Mini bara eklenen gidalari yazdirir
	void miniBarGidaYazdir() {
		cout << "Mini bardaki gidalar:\n";
		Node* tmp = list1.begin();
		while (tmp != list1.end()) {
			cout << tmp->data << " Fiyati:" << tmp->fiyat << endl;
			tmp = tmp->next;
		}
	}
	
	
	// Musteri ozel talep belirtirse onaylama fonksiyonu
	bool ozelTalepCevap(double fiyat, string fileName) {
		
		string fileLocation = "C:\\C++\\DonemProje\\HotelService\\Data\\" + fileName + ".txt";
		ofstream file(fileLocation, ios::app);

		int onay;
		this->fiyat = fiyat;
		cout << "Talebinizin bedeli: " << fiyat << "'TL dir." << endl;
		cout << "Onayliyorsaniz 1 Onaylamiyorsaniz 0 yaziniz: ";
		cin >> onay;

		if (onay==1)
		{
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);

			cout << "Islemi Gerceklestiren Kisinin ID'si: ";
			cin >> islemiYapanId;
			
			file << "Islemi Gerceklestiren Kisinin ID'si: " << islemiYapanId << endl;
			file << "Islem Onaylandi" << " | Islem Tarihi: " << kontrolTarihi << endl;
			
			return true;
		}
		else {
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			
			cout << "Islemi Gerceklestiren Kisinin ID'si: ";
			cin >> islemiYapanId;
			
			file << "Islemi Gerceklestiren Kisinin ID'si: " << islemiYapanId << endl;
			file << "Islem Onaylanmadi" << " | Islem Tarihi: " << kontrolTarihi << endl;
			
			return false;
		}
	}

};

#endif