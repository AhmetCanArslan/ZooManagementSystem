#ifndef ASLAN_H
#define ASLAN_H

#include "Hayvan.h"//subclass, heritance yapmak i�in
#include <string>
using namespace std;

class Aslan :public Hayvan {
public:
	//yap�c� ve y�k�c� tan�m�
	Aslan(string ad, string tur, int yas, string renk);
	Aslan();
	~Aslan();

	//get fonksiyonlar�
	string getRenk();

	//set fonksiyonu
	void setRenk(string);

	//sanal polymorph fonksiyonlar
	void hayvaniBesle() override;
	void bilgileriGoster() override;
	void raporOlustur() override;

private:
	string renk;
};


#endif // !ASLAN_H
