#include "Zolw.h"

Zolw::Zolw(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 2;
	this->initiative = 1;
	this->age = 0;
	this->name = "Zolw";
}

Zolw::~Zolw() {

}

void Zolw::rysowanie() {
	std::cout << "Z";
}

void Zolw::akcja() {
	int sprobuj = rand() % 4;
	if (sprobuj == 0) {
		short kierunek_ruchu;
		int x_dir = 0, y_dir = 0;
		bool mozna_wykonac = false;
		bool zyje = true;

		while (!mozna_wykonac) {
			kierunek_ruchu = std::rand() % 4;
			//std::cout << kierunek_ruchu << '\n';
			if (kierunek_ruchu == 0) { // gora
				x_dir = this->x;
				y_dir = this->y - 1;
			}
			else if (kierunek_ruchu == 1) { //prawo
				x_dir = this->x + 1;
				y_dir = this->y;
			}
			else if (kierunek_ruchu == 2) { //dol
				x_dir = this->x;
				y_dir = this->y + 1;
			}
			else if (kierunek_ruchu == 3) { //lewo
				x_dir = this->x - 1;
				y_dir = this->y;
			}

			if (swiat->is_border(x_dir, y_dir, swiat->get_rozmiar_y(), swiat->get_rozmiar_x())) {
				continue;
			}
			else if (swiat->organizmy_swiat[y_dir][x_dir]) { // kolizja
				//std::cout << "kolizja " << this->name << ' ' << this->x << ' ' << this->y << " z " << x_dir << ' ' << y_dir <<'\n';
				Organizm* oponent = NULL;
				for (int q = 0; q < swiat->liczba_organizmow; ++q) {
					if (swiat->organizmy[q]->get_x() == x_dir && swiat->organizmy[q]->get_y() == y_dir) {
						oponent = swiat->organizmy[q];
						break;
					}
				}
				bool reakcja = oponent->reakcja_na_atak(this);
				if (!reakcja) {
					zyje = this->kolizja(oponent);
				}
				else {
					zyje = false;
				}
				mozna_wykonac = true;
			}
			else {
				mozna_wykonac = true;
			}
		}
		if (zyje) {
			//std::cout << this->name << " kierunek ruchu " << x_dir << ' ' << y_dir << '\n';
			swiat->organizmy_swiat[y_dir][x_dir] = true;
			swiat->organizmy_swiat[y][x] = false;

			this->x = x_dir;
			this->y = y_dir;
		}
	}
}

bool Zolw::reakcja_na_atak(Organizm* atakujacy) {

	if (atakujacy->get_strength() < 5 && atakujacy->get_name() != "Zolw") {
		this->swiat->tabela_wydarzen.add_row({ "Zolw", this->name , std::to_string(this->x), std::to_string(this->y), "<===>", atakujacy->get_name(), std::to_string(atakujacy->get_x()), std::to_string(atakujacy->get_y()) , "Zolw odbija atak " + atakujacy->get_name() });
		return true;
	}
	else {
		return false;
	}
}
