#include <iostream>
#include "OdaServisi.cpp"
#include "Temizlik.cpp"
#include "Oda.cpp"

using namespace std;



int main() {
	
	OdaServisi odaService = OdaServisi();
	Temizlik temizlik;
	List list;
	bool talepOnayi;

	Oda* oda;
	oda->odaNo = 10;
	//oda.dosyaOlustur("AcikBufeGidaList");
	//oda.dosyaOlustur("MiniBarGidaList");
	//oda.dosyaOlustur("TalepList");
	
	

	/*odaService.acikBufeGidaEkle();
	odaService.acikBufeGidaYazdir();

	odaService.miniBarGidaEkle();
	odaService.miniBarGidaYazdir();

	

	talepOnayi= odaService.ozelTalepCevap(500,"TalepList");
		
	if (talepOnayi == true)
	{
		cout << "Talebiniz en kisa surede yerine getirilecektir. "<<endl;
	}
	else {
		cout << "Talebinizi onaylamadiniz."<<endl;
	}
	*/


}