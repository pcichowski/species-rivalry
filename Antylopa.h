#pragma once
#include "Zwierze.h"
class Antylopa : public Zwierze {
public:
	Antylopa(int y , int x);
	~Antylopa();
	void rysowanie();
	void akcja();
	bool reakcja_na_atak(Organizm* atakujacy);
};

