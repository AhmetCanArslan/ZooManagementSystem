#ifndef KARTAL_H
#define KARTAL_H
#include "Hayvan.h"
#include <string>
using namespace std;

class Kartal :public Hayvan {
public:
	//yap�c� ve y�k�c�
	Kartal(string ad, string tur, int yas, int kanatUzunlugu);
	~Kartal();

	//set ve get fonksiyonlar�
	void setKanatUzunlugu(int);
	int getKanatUzunlugu();

	//polymorph fonksiyonlar
	void hayvaniBesle() override;
	void bilgileriGoster() override;
	void raporOlustur() override;

private:
	int kanatUzunlugu;
};
#endif // !KARTAL_H
