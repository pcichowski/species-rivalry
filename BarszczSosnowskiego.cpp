#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 10;
	this->initiative = 0;
	this->age = 0;
	this->name = "Barszcz Sosnowskiego";
	this->is_plant = true;
}

BarszczSosnowskiego::~BarszczSosnowskiego() {
}

void BarszczSosnowskiego::rysowanie() {
	std::cout << "B";
}

void BarszczSosnowskiego::byc_zjedzonym(Organizm* jedzacy) {
	swiat->usun_organizm((Organizm*)jedzacy);
	swiat->zmniejszona_liczba_organizmow = true;
}

void BarszczSosnowskiego::akcja(){
	for (int dir = 0; dir < 4; ++dir) {
		bool found = false;
		int x_dir;
		int y_dir;
		int found_index = 0;
		if (dir == 0) {
			x_dir = this->x;
			y_dir = this->y - 1;
		}
		else if (dir == 1) {
			x_dir = this->x + 1;
			y_dir = this->y;
		}
		else if (dir == 2) {
			x_dir = this->x;
			y_dir = this->y + 1;
		}
		else if (dir == 3) {
			x_dir = this->x - 1;
			y_dir = this->y;
		}
		for (int i = 0; i < swiat->liczba_organizmow; ++i) {
			if (swiat->organizmy[i]->get_x() == x_dir && swiat->organizmy[i]->get_y() == y_dir) {
				found = true;
				found_index = i;
			}
		}

		if (found && !swiat->organizmy[found_index]->is_plant) {
			this->swiat->tabela_wydarzen.add_row({ "Barszcz Sosnowskiego",  swiat->organizmy[found_index]->get_name(), std::to_string(swiat->organizmy[found_index]->get_x()), std::to_string(swiat->organizmy[found_index]->get_y()), "<===>", this->name , std::to_string(this->x), std::to_string(this->y), swiat->organizmy[found_index]->get_name() + " ginie od barszczu sosnowskiego" });
			swiat->usun_organizm((Organizm*)swiat->organizmy[found_index]);
			swiat->zmniejszona_liczba_organizmow = true;
		}
	}
}
