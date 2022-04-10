#pragma once
#include "Zwierze.h"
class Zolw : public Zwierze {
public:
	Zolw(int y, int x);
	~Zolw();
	void rysowanie();
	void akcja();
	bool reakcja_na_atak(Organizm* atakujacy);
};

