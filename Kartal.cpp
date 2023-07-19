#include <iostream>
#include "Kartal.h"
#include <string>
using namespace std;

//yap�c� ve y�k�c� i�in tan�m
Kartal::Kartal(string ad, string tur, int yas, int kanatUzunlugu) {
	this->ad = ad;
	this->tur = tur;
	this->yas = yas;
	this->kanatUzunlugu = kanatUzunlugu;
	beslenmeDurumu = 0;
}


Kartal::~Kartal() {}

//set ve get fonksiyonlar�

void Kartal::setKanatUzunlugu(int kanatUzunlugu) {
	this->kanatUzunlugu = kanatUzunlugu;
}

int Kartal::getKanatUzunlugu() {
	return kanatUzunlugu;
}

//�okbi�imcilik fonksiyonlar�
void Kartal::hayvaniBesle() {
	cout << endl;
	cout << getAd() << " " << getTur() << "i etle besleniyor." << endl;
	beslenmeDurumu = 1;
	cout << endl;
}

void Kartal::bilgileriGoster() {
	cout << "Ad: " << getAd() << endl;
	cout << "Tur: " << getTur() << endl;
	cout << "Yas: " << getYas() << endl;
}

void Kartal::raporOlustur() {
	cout << endl;
	bilgileriGoster();
	cout << "Kanat Uzunlugu: " << getKanatUzunlugu() << endl;
	cout << "Aclik durumu: " << getBeslenmeDurumu() << endl;
}