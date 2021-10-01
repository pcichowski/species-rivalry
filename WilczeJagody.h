#pragma once
#include "Roslina.h"
class WilczeJagody : public Roslina {
public:
	WilczeJagody(int y, int x);
	~WilczeJagody();
	void rysowanie();
	void byc_zjedzonym(Organizm* jedzacy);
};

