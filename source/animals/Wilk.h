#pragma once
#include "Zwierze.h"
#include <iostream>

class Wilk : public Zwierze {
public:
	Wilk();
	Wilk(int y, int x);
	~Wilk();
	void rysowanie();
};
