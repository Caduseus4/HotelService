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
	string islemiYapan,odaNo;
protected:
	double fiyat;
public:
	string gida,gida1;
	List list;
	List list1;

	OdaServisi(string odaNo, string islemiYapan, char* kontrolTarihi) : Hizmet(islemiYapan, kontrolTarihi) {
		this->odaNo = odaNo;
	}
	
	OdaServisi(){}

	void dosyaOlustur(string fileName){
		
		string fileLocation = "C:\\C++\\DonemProje\\HotelService\\Data\\" + fileName + ".txt";
		ofstream file(fileLocation);
		file.close();
		cout << "Dosya Olustu!"<<endl;
	}

	

	void acikBufeGidaEkle() {

		while (gida != "0") {
			cout << "Gidayi Giriniz(Ekleme isleminden cikmak icin 0'a basin):";
			cin >> gida;
			if (gida != "0")
			{
				time_t now = time(0);
				char* kontrolTarihi = ctime(&now);
				list.pushBack(gida,kontrolTarihi);
				
			}


		}

		acikBufeGidaEkleText("AcikBufeGidaList");
	}

	void acikBufeGidaEkleText(string fileName) {
		string fileLocation = "C:\\C++\\DonemProje\\HotelService\\Data\\" + fileName + ".txt";
		ofstream file(fileLocation, ios::app);

				Node* tmp = list.begin();
				while (tmp != list.end()) {

					file << tmp->data <<" | Islem Tarihi: " << tmp->kontrolTarihi << endl;
					tmp = tmp->next;
					
				}
				file.close();
				
	}
	
	void acikBufeGidaYazdir() {
		cout << "Acik bufedeki gidalar:\n";

		Node* tmp = list.begin();
		while (tmp != list.end()) {
			cout << tmp->data<< endl;
			tmp = tmp->next;
		}

	}

	
	void miniBarGidaEkleText(string fileName) {
		string fileLocation = "C:\\C++\\DonemProje\\HotelService\\Data\\" + fileName + ".txt";
		ofstream file(fileLocation, ios::app);

		Node* tmp = list1.begin();
		while (tmp != list1.end()) {
			file << tmp->data << " Fiyati:" << tmp->fiyat <<" | Islem Tarihi: " << tmp->kontrolTarihi << endl;
			tmp = tmp->next;
		}
	}


	void miniBarGidaEkle() {
		while (gida1 != "0") {
			cout << "Gidayi giriniz(Ekleme isleminden cikmak icin 0'e basin):";
			cin >> gida1;
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			if (gida1 != "0")
			{
				
				cout << "Eklediginiz gidanin fiyatini giriniz:";
				cin >> fiyat;
				list1.pushBack(gida1,fiyat,kontrolTarihi);

			}
		}
		miniBarGidaEkleText("MiniBarGidaList");
	}


	void miniBarGidaYazdir() {
		cout << "Mini bardaki gidalar:\n";
		Node* tmp = list1.begin();
		while (tmp != list1.end()) {
			cout << tmp->data << " Fiyati:" << tmp->fiyat << endl;
			tmp = tmp->next;
		}
	}
	
	

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
			file << "Islem Onaylandi" << " | Islem Tarihi: " << kontrolTarihi;
			return true;
		}
		else {
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			file << "Islem Onaylanmadi" << " | Islem Tarihi: " << kontrolTarihi;
			return false;
		}
	}

};

#endif