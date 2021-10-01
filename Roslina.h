#pragma once
#include "Organizm.h"
class Roslina : public Organizm {
public:
	virtual void rozprzestrzeniaj();
	virtual bool kolizja(Organizm* z_kim);
	virtual void akcja();
	virtual void rysowanie() = 0;

	virtual void byc_zjedzonym(Organizm* jedzacy);
	
};

