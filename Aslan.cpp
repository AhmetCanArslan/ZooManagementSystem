#include "Aslan.h"
#include <iostream>
#include "HayvanatBahcesi.h"
#include <string>
using namespace std;
//4 parametreli yap�c�
Aslan::Aslan(string ad, string tur, int yas, string renk) {
	this->ad = ad;
	this->tur = tur;
	this->yas = yas;
	this->renk = renk;
	beslenmeDurumu = 0;
}

Aslan::Aslan() {}


//Y�k�c�
Aslan::~Aslan() {}


//get fonksiyon
string Aslan::getRenk() {
	return renk;
}

//set fonksiyon
void Aslan::setRenk(string renk) {
	this->renk = renk;
}

//sanal fonksiyonlar
void Aslan::hayvaniBesle() {
	cout << endl;
	cout << getAd() << " " << getTur() << "� etle besleniyor." << endl;
	setBeslenmeDurumu(1);
	cout << endl;
}

void Aslan::bilgileriGoster() {
	cout << "Ad: " << getAd() << endl;
	cout << "T�r: " << getTur() << endl;
	cout << "Ya�: " << getYas() << endl;
}

void Aslan::raporOlustur() {
	cout << endl;
	bilgileriGoster();
	cout << "Renk: " << getRenk() << endl;
	cout << "Aclik durumu: " << getBeslenmeDurumu() << endl;
}