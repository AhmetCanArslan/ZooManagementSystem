#include <iostream>
#include "Hayvan.h"
#include "Aslan.h"
#include "Zebra.h"
#include "Kartal.h"
#include "HayvanatBahcesi.h"
#include <clocale> //t�rk�e karakter i�in
#include <string>

using namespace std;

//aray�z� g�stermek i�in fonksiyon olu�turma
void arayuz();

//girilen de�erin string olup olmad���n� kontrol etmek i�in fonksiyon
bool isString(string input);

int main() {

	setlocale(LC_ALL, "Turkish");
	cout << "AHMETCAN ARSLAN 210709036 �NG�L�ZCE B�LG�SAYAR M�HEND�SL��� MBM_104 BAHAR 2023 Proje 1 FERHAT BOZKURT\n" << endl;
	cout << "----- Hayvanat Bah�esi Y�netim Sistemi -----" << "\n" << endl;
	//hayvanat bah�esi olu�turma
	HayvanatBahcesi hayvanatBahcesi;

	//program� �al��t�rmak i�in while d�ng�s�
	while (true) {
		arayuz();
		int secim;
		cin >> secim;
		cout << endl;

		//aray�z kullan�m� i�in switch case olu�turma
		switch (secim) {

		case 1: {
			string ad, tur;
			int yas;

			//istenilen t�rde de�er girilene kadar kontrol etme

			cout << "Hayvan Ad�: ";
			cin >> ad;
			while (!isString(ad)) {
				cout << "\n�sim string olmal�! Tekrar deneyin.\n" << endl;
				cout << "Hayvan Ad�: ";
				cin >> ad;
			}
			cout << "\nHayvan T�r� (Aslan, Zebra, Kartal): ";
			cin >> tur;

			//hayvan t�r� i�eri�inin string olup olmad���n� kontrol etme
			while (!isString(tur)) {
				cout << "\nT�r string olmal�! Tekrar deneyin.\n" << endl;
				cout << "\nHayvan T�r� (Aslan, Zebra, Kartal): ";
				cin >> tur;
			}
			//hayvan t�r� i�eri�inin istenilen t�rlerden biri olup olmad���n� kontrol etme

			while (true) {

				if (tur == "Aslan")
					break;

				else if (tur == "Kartal")
					break;

				else if (tur == "Zebra")
					break;
				else {
					cout << "\nT�r sunulan se�eneklerden biri olmal�d�r!" << endl;
					cout << "\nHayvan T�r� (Aslan, Zebra, Kartal): ";
					cin >> tur;
				}
			}

			//girilen  ya��n s�f�rdan b�y�k ve int olup olmad���n� kontrol etme
			cout << "\nHayvan Ya�� :";
			cin >> yas;

			while (cin.fail() || yas <= 0) {
				cin.clear();  // Hata durumunu temizle
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ge�ersiz giri�i atla 
				cout << "\nYa� integer ve 0'dan b�y�k olmal�! Tekrar deneyin.\n" << endl;
				cout << "\nHayvan Ya�� :";
				cin >> yas;
			}
			cout << endl;


			//e�er t�r aslansa renk bilgisini almam�z gerekecek
			if (tur == "Aslan") {
				string renk;
				cout << "Aslan Rengi: ";
				cin >> renk;
				cout << endl;

				//hayvan� olu�tur ve hayvanat bah�esine ekle
				Hayvan* aslan = new Aslan(ad, tur, yas, renk);
				hayvanatBahcesi.hayvanEkle(aslan);
				cout << "---Hayan Eklendi!---\n" << endl;

			}
			//e�er t�r kartalsa, kanat uzunlu�unu almam�z gerekecek
			else if (tur == "Kartal") {
				int kanatUzunlugu;
				cout << "Kartal Kanat Uzunlu�u: ";
				cin >> kanatUzunlugu;
				cout << endl;

				//hayvan� olu�tur ve hayvanat bah�esine ekle
				Hayvan* kartal = new Kartal(ad, tur, yas, kanatUzunlugu);
				hayvanatBahcesi.hayvanEkle(kartal);
				cout << "---Hayan Eklendi!---\n" << endl;
			}
			//e�er t�r zebraysa, �erit say�s�n� almam�z gerekecek
			else {
				int seritSayisi;
				cout << "Zebra �erit Say�s�: ";
				cin >> seritSayisi;
				cout << endl;

				//hayvan� olu�tur ve hayvanat bah�esine ekle
				Hayvan* zebra = new Zebra(ad, tur, yas, seritSayisi);
				hayvanatBahcesi.hayvanEkle(zebra);
				cout << "---Hayan Eklendi!---\n" << endl;
			}

			break;
		}
			  //hayvanlar� g�stermek i�in case 2
		case 2:
			hayvanatBahcesi.hayvanlarinRaporu();
			break;
			//hayvanlar� beslemek i�in case 3
		case 3: {
			string ad;
			bool hayvanBulundu = false;
			//e�er girilen isim string de�ilse ve o isimde bir hayvan yoksa tekrar giri� yap�lmas� istenir
			while (true) {
				cout << "Beslemek �stedi�iniz hayvan�n ad�n� giriniz: ";
				cin >> ad;
				//string olup olmad��� kontrol edilir
				if (!isString(ad)) {
					cout << "\nL�tfen bir string giriniz!\n" << endl;
					continue;
				}
				//o isimde hayvan var m� yok mu o kontrol edilir. e�er varsa hayvan beslenir
				hayvanBulundu = false;

				for (Hayvan* hayvan : hayvanatBahcesi.hayvanlar) {
					if (hayvan->getAd() == ad) {
						hayvanatBahcesi.hayvanBesle(ad);
						hayvanBulundu = true;
						break;
					}
				}
				//e�er o isimde bir hayvan varsa while d�ng�s�nden ��k�� yap�l�r
				if (hayvanBulundu) {
					break;
				}
				else {
					cout << "\nGirilen isimde bir hayvan bulunmamaktad�r. L�tfen tekrar deneyiniz.\n" << endl;
				}
			}
			break;
		}
		case 4:
			cout << "Uygulamadan ��k�� yap�l�yor!" << endl;
			return 0;

		default:
			cout << "Yanl�� giri� yapt�n�z. L�tfen tekrar deneyiniz!\n" << endl;
		}
	};
}

//aray�z� g�stermek i�in fonksiyon
void arayuz() {
	cout << "1. Hayvan Ekle " << endl;
	cout << "2. Hayvanlar� G�ster " << endl;
	cout << "3. Hayvan Besle " << endl;
	cout << "4. ��k�� " << endl;
	cout << "Se�iminizi yap�n: ";
}

//isString fonksiyonunun tan�m�
bool isString(string input) {
	for (char c : input) {
		if (!std::isalpha(c)) {
			return false;
		}
	}
	return true;
}