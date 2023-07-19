#include "HayvanatBahcesi.h"
#include <iostream>
#include "Hayvan.h"
#include <string>
#include <clocale>
#include "Aslan.h"//aslan eklemek i�in
using namespace std;


// y�k�c�
HayvanatBahcesi::~HayvanatBahcesi() {
	for (Hayvan* hayvan : hayvanlar) {
		delete hayvan;
	}
	hayvanlar.clear();
}

//hayvan ekleme fonksiyonu
void HayvanatBahcesi::hayvanEkle(Hayvan* hayvan) {
	hayvanlar.push_back(hayvan);
}
//yap�c�. Bizden istenilen 3 tane aslan� varsay�lan olarak olu�turmak i�in 
HayvanatBahcesi::HayvanatBahcesi() {
	// Aslanlar� ekleyin
	Hayvan* aslanA = new Aslan("AslanA", "Aslan", 5, "Kahverengi");
	Hayvan* aslanB = new Aslan("AslanB", "Aslan", 7, "Sar�");
	Hayvan* aslanC = new Aslan("AslanC", "Aslan", 10, "Beyaz");

	// Aslanlar� listeye ekleyin
	hayvanlar.push_back(aslanA);
	hayvanlar.push_back(aslanB);
	hayvanlar.push_back(aslanC);
}

//hayvanlar� g�sterme fonksiyonu
void HayvanatBahcesi::hayvanlariGoster() {
	//Aslanlar� g�stermek i�in onlar� ayr� bir listeye al�p daha sonra k���kten b�y��e s�ralayabiliriz;
	list<Hayvan*> aslanYeni;
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getTur() == "Aslan")
			aslanYeni.push_back(hayvan);
	}
	//aslan s�n�f�n� ya�lara g�re s�ralama;
	aslanYeni.sort([](Hayvan* hayvan1, Hayvan* hayvan2) {
		return hayvan1->yas < hayvan2->yas;
		});
	for (Hayvan* hayvan : aslanYeni) {
		hayvan->bilgileriGoster();
		cout << endl;

	}

	//zebralar� k���kten b�y��e s�ralamak i�in yeni liste olu�turma
	list<Hayvan*> zebraYeni;
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getTur() == "Zebra")
			zebraYeni.push_back(hayvan);

	}

	//zebra s�n�f�n� ya�lara g�re s�ralama;
	zebraYeni.sort([](Hayvan* hayvan1, Hayvan* hayvan2) {
		return hayvan1->yas < hayvan2->yas;
		});
	for (Hayvan* hayvan : zebraYeni) {
		hayvan->bilgileriGoster();
		cout << endl;
	}

	//kartallar� s�ralamak i�in ayr� liste
	list<Hayvan*> kartalYeni;
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getTur() == "Kartal")
			kartalYeni.push_back(hayvan);
	}
	//kartal s�n�f�n� ya�lara g�re s�ralama;
	kartalYeni.sort([](Hayvan* hayvan1, Hayvan* hayvan2) {
		return hayvan1->yas < hayvan2->yas;
		});
	for (Hayvan* hayvan : kartalYeni) {
		hayvan->bilgileriGoster();
		cout << endl;

	}

}

//hayvanlar� besleme fonksiyonu
void HayvanatBahcesi::hayvanBesle(string ad) {
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getAd() == ad) {
			hayvan->hayvaniBesle();
			return;
		}
	}
}
//hayvan ya� g�ncelleme fonksiyonu
void HayvanatBahcesi::hayvanYasGuncelle(string ad, int yas) {
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getAd() == ad) {
			hayvan->setYas(yas);
			return;
		}
	}
}


//ortalama fonksiyonlar� her bir t�r i�in ayr� ayr� 

double HayvanatBahcesi::aslanHarmonikOrtalama() {
	double toplam = 0.0;
	list <Hayvan*> yeniListe;
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getTur() == "Aslan") {
			toplam += 1.0 / hayvan->getYas();
			yeniListe.push_back(hayvan);
		}
	}
	return yeniListe.size() / toplam;
}


double HayvanatBahcesi::aslanAritmetikOrtalama() {
	double toplam = 0.0;
	list <Hayvan*> yeniListe;
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getTur() == "Aslan") {
			toplam += hayvan->getYas();
			yeniListe.push_back(hayvan);
		}
	}
	return toplam / yeniListe.size();
}

double HayvanatBahcesi::kartalHarmonikOrtalama() {
	double toplam = 0.0;
	list <Hayvan*> yeniListe;
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getTur() == "Kartal") {
			toplam += 1.0 / hayvan->getYas();
			yeniListe.push_back(hayvan);
		}
	}
	return yeniListe.size() / toplam;
}

double HayvanatBahcesi::kartalAritmetikOrtalama() {
	double toplam = 0.0;
	list <Hayvan*> yeniListe;
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getTur() == "Kartal") {
			toplam += hayvan->getYas();
			yeniListe.push_back(hayvan);
		}
	}
	return toplam / yeniListe.size();
}

double HayvanatBahcesi::zebraHarmonikOrtalama() {
	double toplam = 0.0;
	list <Hayvan*> yeniListe;
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getTur() == "zebra") {
			toplam += 1.0 / hayvan->getYas();
			yeniListe.push_back(hayvan);
		}
	}
	return yeniListe.size() / toplam;
}

double HayvanatBahcesi::zebraAritmetikOrtalama() {
	double toplam = 0.0;
	list <Hayvan*> yeniListe;
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getTur() == "Zebra") {
			toplam += hayvan->getYas();
			yeniListe.push_back(hayvan);
		}
	}
	return toplam / yeniListe.size();
}


//Hayvanlar�n raporunu olu�turmak i�in fonksiyon
void HayvanatBahcesi::hayvanlarinRaporu() {
	cout << "\n-----Hayvanlarin raporu-----\n" << endl;

	cout << "Aslanlar�n raporu:" << endl;
	cout << endl;
	//ka� tane aslan oldu�unu kontrol edip ona g�re ��kt� vermemiz gerekcek. burada ka� tane aslan oldu�unu kontrol ediyoruz.
	int aslanSayac = 0;
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getTur() == "Aslan") {
			aslanSayac += 1;
		}
	}
	if (aslanSayac == 0)
		cout << "Hi� aslan yok!" << endl;
	//e�er aslan varsa raporu olu�turacak
	else if (aslanSayac != 0) {
		for (Hayvan* hayvan : hayvanlar) {
			if (hayvan->getTur() == "Aslan") {
				hayvan->raporOlustur();
				cout << endl;
			}
		}
	}
	//e�er 1 tane aslan varsa ortalamalar� g�stermeye gerek yok. ama 2 ve fazla varsa ortalamalar� g�stermeliyiz.
	if (aslanSayac > 1) {
		cout << "Aslan Ya�lar� Aritmetik Ortalamas�: " << aslanAritmetikOrtalama() << endl;
		cout << "Aslan Ya�lar� Harmonik Ortalamas�: " << aslanHarmonikOrtalama() << endl;
	}
	cout << endl;

	cout << "\nKartallar�n raporu:" << endl;
	cout << endl;
	int kartalSayac = 0;
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getTur() == "Kartal") {
			kartalSayac += 1;
		}
	}
	if (kartalSayac == 0)
		cout << "Hi� Kartal Yok!" << endl;
	else if (kartalSayac != 0) {
		for (Hayvan* hayvan : hayvanlar) {
			if (hayvan->getTur() == "Kartal") {
				hayvan->raporOlustur();
				cout << endl;
			}


		}
	}
	if (kartalSayac > 1) {
		cout << "Kartal Ya�lar� Aritmetik Ortalamas�: " << kartalAritmetikOrtalama() << endl;
		cout << "KArtal Ya�lar� Harmonik Ortalamas�: " << kartalHarmonikOrtalama() << endl;
	}
	cout << endl;

	cout << "\nZebralar�n raporu: " << endl;
	cout << endl;
	int zebraSayac = 0;
	for (Hayvan* hayvan : hayvanlar) {
		if (hayvan->getTur() == "Zebra") {
			zebraSayac += 1;
		}
	}
	if (zebraSayac == 0)
		cout << "Hi� Zebra Yok!\n" << endl;
	else if (zebraSayac != 0) {
		for (Hayvan* hayvan : hayvanlar) {
			if (hayvan->getTur() == "Zebra") {
				hayvan->raporOlustur();
				cout << endl;
			}
		}
	}
	if (zebraSayac > 1) {
		cout << "Zebra Ya�lar� Aritmetik Ortalamas�: " << zebraAritmetikOrtalama() << endl;
		cout << "Zebra Ya�lar� Harmonik Ortalamas�: " << zebraHarmonikOrtalama() << endl;
	}
}
