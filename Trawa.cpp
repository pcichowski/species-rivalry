#include "Trawa.h"

Trawa::Trawa() {
	
}

Trawa::Trawa(int y, int x){
	this->x = x;
	this->y = y;
	this->strength = 0;
	this->initiative = 0;
	this->age = 0;
	this->name = "Trawa";
	this->is_plant = true;
}

Trawa::~Trawa() {

}

void Trawa::rysowanie() {
	std::cout << "T";
}
