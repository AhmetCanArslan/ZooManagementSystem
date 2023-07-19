#include "Hayvan.h"
#include <iostream>
#include <string>

using namespace std;
//constructor tan�m�

Hayvan::Hayvan()
{
	ad = "";
	tur = "";
	yas = 0;
	beslenmeDurumu = 0;
}

Hayvan::Hayvan(string ad, string tur, int yas) {
	this->ad = ad;
	this->tur = tur;
	this->yas = yas;
	this->beslenmeDurumu = 0;
}

//Destructor
Hayvan::~Hayvan() {}


//Get fonksiyonlar�
string Hayvan::getAd() {
	return ad;
}

string Hayvan::getTur() {
	return tur;
}

int Hayvan::getYas() {
	return yas;
}

string Hayvan::getBeslenmeDurumu() {
	if (beslenmeDurumu) {
		return "Karn� Tok!";
	}
	else
	{
		return "Karn� A�!";
	}

}


//Set fonksiyonlar�
void Hayvan::setAd(string ad) {
	this->ad = ad;
}

void Hayvan::setTur(string tur) {
	this->tur = tur;
}

void Hayvan::setYas(int yas) {
	this->yas = yas;
}

void Hayvan::setBeslenmeDurumu(int beslenmeDurumuYeni) {
	beslenmeDurumu = beslenmeDurumuYeni;
}

//Sanal fonksiyonlar
void Hayvan::hayvaniBesle() {
	cout << endl;
	cout << "Hayvan besleniyor" << endl;
	setBeslenmeDurumu(1);
}

void Hayvan::bilgileriGoster() {
	cout << "Ad: " << getAd() << endl;
	cout << "Tur: " << getTur() << endl;
	cout << "Yas: " << getYas() << endl;
}

void Hayvan::raporOlustur() {
	cout << getAd() << " raporu: " << endl;
	bilgileriGoster();
	cout << "Aclik durumu: " << getBeslenmeDurumu() << endl;
}