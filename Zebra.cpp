#include <iostream>
#include "Zebra.h"
#include <string>

using namespace std;

//constructor tan�m�
Zebra::Zebra(string ad, string tur, int yas, int seritSayisi) {
	this->ad = ad;
	this->tur = tur;
	this->yas = yas;
	this->seritSayisi = seritSayisi;
	beslenmeDurumu = 0;
}


//y�k�c� destructor

Zebra::~Zebra() {}

//set ve get fonksiyonlar� tan�m�

void Zebra::setSeritSayisi(int seritSayisi) {
	this->seritSayisi = seritSayisi;
}

int Zebra::getSeritSayisi() {
	return seritSayisi;
}

//sanal fonksiyonlar

void Zebra::bilgileriGoster() {
	cout << "Ad: " << getAd() << endl;
	cout << "Tur: " << getTur() << endl;
	cout << "Yas: " << getYas() << endl;

}

void Zebra::hayvaniBesle() {
	cout << endl;
	cout << getAd() << " " << getTur() << ", otlarla besleniyor." << endl;
	beslenmeDurumu = 1;
	cout << endl;
}

void Zebra::raporOlustur() {
	cout << endl;
	bilgileriGoster();
	cout << "Serit Say�s�: " << getSeritSayisi() << endl;
	cout << "Aclik durumu: " << getBeslenmeDurumu() << endl;
}