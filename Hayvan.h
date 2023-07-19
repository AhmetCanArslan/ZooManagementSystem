#ifndef HAYVAN_H
#define HAYVAN_H
#include <string>//hayvan isimi ve t�r� i�in
using namespace std;


class Hayvan {
public:
	Hayvan();
	Hayvan(string ad, string tur, int yas);
	~Hayvan();

	// hayvan biglileri i�in get fonksiyonlar�
	string getAd();
	string getTur();
	int getYas();

	//hayvan bilgilerini ayarlamak i�in set fonksiyonlar�
	void setAd(string);
	void setTur(string);
	void setYas(int);

	//di�er s�n�flarda da kullanmak i�in sanal fonksiyonlar
	virtual void hayvaniBesle();
	virtual void bilgileriGoster();
	virtual void raporOlustur();

	//beslenme durumu i�in fonksiyon
	void setBeslenmeDurumu(int);
	string getBeslenmeDurumu();

	friend class HayvanatBahcesi;//hayvanat bah�esini friend olarak tan�mlay�p public fonksiyonlara eri�ebilece�iz

protected:
	string ad;
	int yas;
	string tur;
	int beslenmeDurumu;
};

#endif // !HAYVAN_H
