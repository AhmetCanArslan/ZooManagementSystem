#ifndef ZEBRA_H
#define ZEBRA_H
#include "Hayvan.h"
#include <string>
using namespace std;

//zebra s�n�f�. Hayvan s�n�f�ndan kal�t�m alarak olu�turuldu

class Zebra :public Hayvan {
public:
	// 4 parametreli yap�c� ve y�k�c�
	Zebra(string ad, string tur, int yas, int seritSayisi);
	~Zebra();

	//get ve set fonksiyonlar�

	int getSeritSayisi();
	void setSeritSayisi(int);

	//sanal fonksiyonlar
	void hayvaniBesle() override;
	void bilgileriGoster() override;
	void raporOlustur() override;

private:
	int seritSayisi;
};


#endif // !ZEBRA_H
