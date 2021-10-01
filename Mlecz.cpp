#include "Mlecz.h"
#include <iostream>

Mlecz::Mlecz(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 0;
	this->initiative = 0;
	this->age = 0;
	this->name = "Mlecz";
	this->is_plant = true;
}
Mlecz::~Mlecz() {

}

void Mlecz::akcja() {
	for (int i = 0; i < 3; ++i) {
		short sprobuj;
		sprobuj = rand() % 100;
		if (sprobuj < 10) {
			rozprzestrzeniaj();
		}
	}
}

void Mlecz::rysowanie() {
	std::cout << "M";
}
