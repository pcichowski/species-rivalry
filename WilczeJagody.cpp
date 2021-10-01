#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(int y, int x){
	this->x = x;
	this->y = y;
	this->strength = 99;
	this->initiative = 0;
	this->age = 0;
	this->name = "Wilcze Jagody";
	this->is_plant = true;
}

WilczeJagody::~WilczeJagody(){

}

void WilczeJagody::rysowanie() {
	std::cout << "J";
}

void WilczeJagody::byc_zjedzonym(Organizm* jedzacy) {
	this->swiat->tabela_wydarzen.add_row({ "Wilcze Jagody",  jedzacy->get_name(), std::to_string(jedzacy->get_x()), std::to_string(jedzacy->get_y()), "<===>", this->name , std::to_string(this->x), std::to_string(this->y), jedzacy->get_name() + " zjada wilcze jagody i ginie" });
	swiat->usun_organizm((Organizm*)jedzacy);
	swiat->zmniejszona_liczba_organizmow = true;
}
