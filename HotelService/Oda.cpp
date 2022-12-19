#ifndef ODA_H
#define ODA_H
#include<iostream>
#include<fstream>
#include <string>
using namespace std;

class Oda
{
public:
	string odaNo;
	string odaTuru;
	int odaKisiKapasitesi;
	int gunlukOdaFiyati;
	bool temizMi;
	bool ekstraTemizlik;
	bool doluMu;
};

class OdaGetir : public Oda
{
public:
	int bosOdaSayisi;
	int doluOdaSayisi;
	string bosOdaHataMesaji;
	string doluOdaHataMesaji;
	Oda* doluOdalar;
	Oda* bosOdalar;
	OdaGetir()
	{
		string bosOdaTextUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\HotelOtomation\\Data\\Odalar\\bosOdaListesi.txt";
		string doluOdaTextUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\HotelOtomation\\Data\\Odalar\\doluOdaListesi.txt";
		string bos;
		string dolu;
		int i = 0;

		//BOS ODALARI OLUSTURMA
		ifstream readBosOda(bosOdaTextUrl);
		while (getline(readBosOda, bos))
		{
			i++; //kac adet bos oda var bunu bulduk
		}
		readBosOda.close();
		if (i != 0)
		{
			bosOdalar = new Oda[i];
			bosOdaOlustur(bosOdalar);
			print(bosOdalar);
		}
		else
		{
			this->bosOdaHataMesaji = "TUM ODALAR DOLMUSTUR!";
		}

		//DOLU ODALARI OLUSTURMA
		int j = 0;
		ifstream readDoluOda(doluOdaTextUrl);
		while (getline(readDoluOda, dolu))
		{
			j++; //kac adet bos oda var bunu bulduk
		}
		readDoluOda.close();
		if (j != 0)
			doluOdalar = new Oda[i];
		else
			this->doluOdaHataMesaji = "DOLU ODA MEVCUT DEGIL!";
	}
	void bosOdaOlustur(Oda* oda)
	{
		string file = "C:\\Users\\Ferhat\\source\\repos\\c\\HotelOtomation\\Data\\Odalar\\Bos\\";
		for (int i = 0; i < bosOdaSayisi; i++)
		{
			ifstream read(file.append(getBosOda(i)));
			string line;
			int j = 0;
			while (getline(read, line))
			{
				if (j == 1 || j == 2)
					bosOdaStringTxtOkuma(oda, file.append(getBosOda(i)), i);
				if (j == 3 || j == 4)
					bosOdaIntTxtOkuma(oda, file.append(getBosOda(i)), i);
				if (j == 5 || j == 6 || j == 7)
					bosOdaBoolTxtOkuma(oda, file.append(getBosOda(i)), i);
				j++;

			}
			read.close();
			j = 0;
		}
	}
	//odayý sectik
	string getBosOda(int i)
	{
		string file = "C:\\Users\\Ferhat\\source\\repos\\c\\HotelOtomation\\Data\\Odalar\\bosOdaListesi.txt";
		ifstream read(file);
		string line;
		string arananData;
		int j = 0;
		int index = 0;
		string oda;
		while (getline(read, line))
		{
			if (j == i)
			{
				oda = line;
				break;
			}
			j++;
		}
		return oda;
	}
	void bosOdaStringTxtOkuma(Oda* oda, string odaNo, int k)
	{
		string file = "C:\\Users\\Ferhat\\source\\repos\\c\\HotelOtomation\\Data\\Odalar\\Bos\\";
		ifstream read(file.append(odaNo + ".txt"));
		string line, arananData;
		int index = 0, i = 0;
		while (getline(read, line))
		{
			if (i == 1)
			{
				index = line.find(":");
				arananData = line.substr(index + 1);
				(oda + k)->odaNo = arananData;
			}
			if (i == 2)
			{
				index = line.find(":");
				arananData = line.substr(index + 1);
				(oda + k)->odaTuru = arananData;
			}
			index = 0;
			i++;
		}
		read.close();
	}
	void bosOdaIntTxtOkuma(Oda* oda, string odaNo, int k)
	{
		string file = "C:\\Users\\Ferhat\\source\\repos\\c\\HotelOtomation\\Data\\Odalar\\Bos\\";
		ifstream read(file.append(odaNo + ".txt"));
		string line, arananData;
		int index = 0, i = 0;
		while (getline(read, line))
		{
			if (i == 3)
			{
				index = line.find(":");
				arananData = line.substr(index + 1);
				(oda + k)->odaKisiKapasitesi = stoi(arananData);
			}
			if (i == 4)
			{
				index = line.find(":");
				arananData = line.substr(index + 1);
				(oda + k)->gunlukOdaFiyati = stoi(arananData);
			}
			index = 0;
			i++;
		}
		read.close();
	}
	void bosOdaBoolTxtOkuma(Oda* oda, string odaNo, int k)
	{
		string file = "C:\\Users\\Ferhat\\source\\repos\\c\\HotelOtomation\\Data\\Odalar\\Bos\\";
		ifstream read(file.append(odaNo + ".txt"));
		string line, arananData;
		int index = 0, i = 0;
		while (getline(read, line))
		{
			if (i == 5)
			{
				index = line.find(":");
				arananData = line.substr(index + 1);
				(oda + k)->doluMu = getBool(odaNo, i);
			}
			if (i == 6)
			{
				index = line.find(":");
				arananData = line.substr(index + 1);
				(oda + k)->odaTuru = getBool(odaNo, i);
			}
			if (i == 7)
			{
				index = line.find(":");
				arananData = line.substr(index + 1);
				(oda + k)->odaTuru = getBool(odaNo, i);
			}
			index = 0;
			i++;
		}
		read.close();

	}

	bool getBool(string odaNo, int i)
	{
		string file = "C:\\Users\\Ferhat\\source\\repos\\c\\HotelOtomation\\Data\\Odalar\\Bos\\";
		ifstream read(file.append(odaNo + ".txt"));
		string line;
		int tutar = 0;
		int j = 0;
		while (getline(read, line))
		{
			if (j == i)
			{
				tutar = stoi(line); // stoi ile convert islemi yapýyoruz
				break;
			}
			j++;
		}
		return tutar;
	}

	void print(Oda* o)
	{
		for (int i = 0; i < bosOdaSayisi; i++)
		{
			cout << (o + i)->odaNo << " " << (o + i)->gunlukOdaFiyati << endl;
		}
	}
};

class OdaOlustur : public Oda {
	friend class Turizm;
public:
	Oda* odalar;
	int vipOdaSayisi = 10;
	int aOdaSayisi = 30;
	int bOdaSayisi = 30;
	int cOdaSayisi = 30;
	const int toplamOdaSayisi = vipOdaSayisi + aOdaSayisi + bOdaSayisi + cOdaSayisi;

	//BU FONKSIYONLAR TUM ODALARI OLUSTURMAK ICIN 1 KERE KULLANILDI
	void olustur()
	{
		odalar = new Oda[toplamOdaSayisi];
		int i, a, b, c;
		for (i = 0; i < vipOdaSayisi; i++)
		{
			(odalar + i)->odaNo = "VIP-" + to_string(i + 10);
			(odalar + i)->odaTuru = "VIP";
			(odalar + i)->odaKisiKapasitesi = 1;
			(odalar + i)->temizlik = true;
			(odalar + i)->araTemizlik = false;
			(odalar + i)->ozelTemizlik = false;
			(odalar + i)->gunlukOdaFiyati = 15000;
			(odalar + i)->doluMu = false;
		}
		int j = i;
		for (a = (aOdaSayisi + j); j < a; j++)
		{
			(odalar + j)->odaNo = "A-" + to_string(j + 10);
			(odalar + j)->odaTuru = "A";
			(odalar + j)->odaKisiKapasitesi = 2;
			(odalar + j)->temizlik = true;
			(odalar + j)->araTemizlik = false;
			(odalar + j)->ozelTemizlik = false;
			(odalar + j)->gunlukOdaFiyati = 3000;
			(odalar + j)->doluMu = false;
		}
		int z = a;
		for (b = (bOdaSayisi + a); z < b; z++)
		{
			(odalar + z)->odaNo = "B-" + to_string(z + 10);
			(odalar + z)->odaTuru = "B";
			(odalar + z)->odaKisiKapasitesi = 3;
			(odalar + z)->temizlik = true;
			(odalar + z)->araTemizlik = false;
			(odalar + z)->ozelTemizlik = false;
			(odalar + z)->gunlukOdaFiyati = 4000;
			(odalar + z)->doluMu = false;
		}
		int x = b;
		for (c = (cOdaSayisi + b); x < c; x++)
		{
			(odalar + x)->odaNo = "C-" + to_string(x + 10);
			(odalar + x)->odaTuru = "C";
			(odalar + x)->odaKisiKapasitesi = 5;
			(odalar + x)->temizlik = true;
			(odalar + x)->araTemizlik = false;
			(odalar + x)->ozelTemizlik = false;
			(odalar + x)->gunlukOdaFiyati = 5000;
			(odalar + x)->doluMu = false;
		}
		txtOlustur(odalar);
		//bosOdalariYaz(odalar);
	}

	void odalariListele(string arananOda)
	{
		string dolu = "BOS";
		cout << "Hotelde BOS olan " << odaTuru << " Odalar: " << endl;
		int h = 0;
		while ((odalar + h)->odaKisiKapasitesi != NULL)
		{
			if ((odalar + h)->doluMu == false &&
				(odalar + h)->odaTuru._Equal(arananOda))
			{
				cout << "ODA NO: " << (odalar + h)->odaNo << " "
					<< "TUR: " << (odalar + h)->odaTuru << " " << " "
					<< "KAPASITE: " << (odalar + h)->odaKisiKapasitesi << " "
					<< "GUNLUK FIYAT: " << (odalar + h)->gunlukOdaFiyati << " "
					<< "ODA DURUMU: " << "BOS" << endl;
			}
			h++;
		}
	}

	/*void bosOdalariYaz(Oda* o)
	{
		string txtIsmi;
		string data;
		ofstream write("C:\\Users\\Ferhat\\source\\repos\\c\\HotelOtomation\\Data\\Odalar\\bosOdaListesi.txt",ios::app);
		for (int i = 0; i < toplamOdaSayisi; i++)
		{
			txtIsmi = (o + i)->odaNo;
			write << txtIsmi << endl;
		}
		write.close();
	}*/

	void txtOlustur(Oda* o)
	{
		string txtIsmi;
		string data;
		for (int i = 0; i < toplamOdaSayisi; i++)
		{
			txtIsmi = (o + i)->odaNo;
			createFile(txtIsmi);
			data = "---------------------------"
				"\nODA NO:" + (odalar + i)->odaNo
				+ "\nODA TURU:" + (odalar + i)->odaTuru
				+ "\nODA KAPASITE:" + to_string((odalar + i)->odaKisiKapasitesi)
				+ "\nGUNLUK FIYAT:" + to_string((odalar + i)->gunlukOdaFiyati)
				+ "\nDOLULUK :" + to_string((odalar + i)->doluMu)
				+ "\nTEMIZLIK:" + to_string((odalar + i)->temizlik)
				+ "\nARA TEMIZLIK:" + to_string((odalar + i)->araTemizlik)
				+ "\n---------------------------\n";
			writeToFile(data, txtIsmi);
		}
	}

	void createFile(string fileName)
	{
		string fileLoc = "C:\\Users\\Ferhat\\source\\repos\\c\\HotelOtomation\\Data\\Odalar\\Bos\\" + fileName + ".txt";
		ofstream file(fileLoc);
		file.close();
		cout << "Dosya olustu" << endl;
	}

	void writeToFile(string data, string fileName)
	{
		string fileLoc = "C:\\Users\\Ferhat\\source\\repos\\c\\HotelOtomation\\Data\\Odalar\\Bos\\" + fileName + ".txt";
		ofstream file(fileLoc);
		file << data;
		file.close();
	}
};

#endif 