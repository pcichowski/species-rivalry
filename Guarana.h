#pragma once
#include "Roslina.h"
class Guarana : public Roslina {
public:
	Guarana(int y, int x);
	~Guarana();
	void rysowanie();
	void byc_zjedzonym(Organizm* jedzacy);
};

