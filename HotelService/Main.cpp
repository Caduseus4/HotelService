#include <iostream>
#include "OdaServisi.cpp"

using namespace std;


//Mini bara fiyat eklendiðinde texte yazmýyor


int main() {
	
	OdaServisi oda = OdaServisi();
	List list;
	bool talepOnayi;

	//oda.dosyaOlustur("AcikBufeGidaList");
	//oda.dosyaOlustur("MiniBarGidaList");
	//oda.dosyaOlustur("TalepList");


	oda.acikBufeGidaEkle();
	oda.acikBufeGidaYazdir();

	oda.miniBarGidaEkle();
	oda.miniBarGidaYazdir();

	

	talepOnayi= oda.ozelTalepCevap(500,"TalepList");
		
	if (talepOnayi == true)
	{
		cout << "Talebiniz en kisa surede yerine getirilecektir. "<<endl;
	}
	else {
		cout << "Talebinizi onaylamadiniz."<<endl;
	}
	


}