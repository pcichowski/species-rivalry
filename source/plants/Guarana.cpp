#include "Guarana.h"
#include <iostream>

#define GUARANA_STRENGTH 3

Guarana::Guarana(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 0;
	this->initiative = 0;
	this->age = 0;
	this->name = "Guarana";
	this->is_plant = true;
}

Guarana::~Guarana() {
	
}

void Guarana::rysowanie() {
	std::cout << "G";
}

void Guarana::byc_zjedzonym(Organizm* jedzacy) {
	this->swiat->tabela_wydarzen.add_row({ "Guarana",  jedzacy->get_name(), std::to_string(jedzacy->get_x()), std::to_string(jedzacy->get_y()), "<===>", this->name , std::to_string(this->x), std::to_string(this->y), jedzacy->get_name() + " zjada guarane"});
	swiat->usun_organizm((Organizm*)this);
	swiat->zmniejszona_liczba_organizmow = true;
	jedzacy->add_strength(GUARANA_STRENGTH);
}
