#include "Owca.h"
#include <iostream>

Owca::Owca() {
	this->strength = 4;
	this->initiative = 4;
	this->age = 0;
	this->name = "Owca";
}
Owca::Owca(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 4;
	this->initiative = 4;
	this->age = 0;
	this->name = "Owca";
}
Owca::~Owca() {

}

void Owca::rysowanie() {

	std::cout << "O";
}