#pragma once
#include "Organizm.h"
class Zwierze : public Organizm {

public:

	virtual void akcja();
	virtual bool kolizja(Organizm* z_kim);
	
	virtual void rysowanie() = 0;

	virtual bool walka(Organizm* z_kim);
	virtual void rozmnazaj(Organizm* z_kim);

	//virtual ~Zwierze();
};

