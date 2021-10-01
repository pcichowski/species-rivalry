#include "Wilk.h"
#include <iostream>

Wilk::Wilk() {
	//std::cout << "konstruktor wilka\n";
	this->strength = 9;
	this->initiative = 5;
	this->age = 0;
	this->name = "Wilk";
}
Wilk::Wilk(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 9;
	this->initiative = 5;
	this->age = 0;
	this->name = "Wilk";

}
Wilk::~Wilk() {

}
/*
void Wilk::akcja() {
	normalny_ruch();
}
bool Wilk::kolizja(Organizm* z_kim) {
	if (this->name == z_kim->get_name()) { // rozmnazanie
		this->rozmnazaj(z_kim);
		return false;
	}
	else { // walka
		if (walka(z_kim)) {
			return true;
		}
		else {
			return false;
		}
	}
}*/
void Wilk::rysowanie() {
	std::cout << "W";
}