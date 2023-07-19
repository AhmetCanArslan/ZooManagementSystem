#ifndef HAYVANATBAHCESI_H
#define HAYVANATBAHCESI_H
#include <list>//hayvan listesi olu�turmak i�in
#include "Hayvan.h"
#include <string>

using namespace std;

class HayvanatBahcesi {
public:
	//yap�c� ve y�k�c�
	HayvanatBahcesi();
	~HayvanatBahcesi();

	//projede istenilen 3 tane aslan i�in 


	//projede istenilen i�levler i�in fonksiyonlar
	void hayvanEkle(Hayvan* hayvan);
	void hayvanlariGoster();
	void hayvanBesle(string ad);
	void hayvanYasGuncelle(string ad, int yas);
	void hayvanlarinRaporu();

	//ortalama alma fonksiyonlar�

	double aslanHarmonikOrtalama();
	double aslanAritmetikOrtalama();

	double kartalHarmonikOrtalama();
	double kartalAritmetikOrtalama();

	double zebraHarmonikOrtalama();
	double zebraAritmetikOrtalama();

	list<Hayvan*> hayvanlar;
};

#endif // !HAYVANATBAHCESI_H
