#pragma once
#include "Roslina.h"
class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego(int y, int x);
	~BarszczSosnowskiego();
	void rysowanie();
	void byc_zjedzonym(Organizm* jedzacy);
	void akcja();
};

