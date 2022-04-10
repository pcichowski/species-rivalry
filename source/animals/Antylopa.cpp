#include "Antylopa.h"

Antylopa::Antylopa(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 4;
	this->initiative = 4;
	this->age = 0;
	this->name = "Antylopa";
}

Antylopa::~Antylopa() {
}

void Antylopa::rysowanie() {
	std::cout << "A";
}

void Antylopa::akcja() {
	short kierunek_ruchu;
	int x_dir = 0, y_dir = 0;
	bool mozna_wykonac = false;
	bool zyje = true;

	while (!mozna_wykonac) {
		kierunek_ruchu = std::rand() % 12;
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
		else if (kierunek_ruchu == 4) { // gora gora
			x_dir = this->x;
			y_dir = this->y - 2;
		}
		else if (kierunek_ruchu == 5) { // prawo prawo
			x_dir = this->x + 2;
			y_dir = this->y;
		}
		else if (kierunek_ruchu == 6) { // lewo lewo
			x_dir = this->x - 2;
			y_dir = this->y;
		}
		else if (kierunek_ruchu == 7) { // dol dol
			x_dir = this->x;
			y_dir = this->y + 2;
		}
		else if (kierunek_ruchu == 8) { // prawy gorny
			x_dir = this->x + 1;
			y_dir = this->y - 1;
		}
		else if (kierunek_ruchu == 9) { // lewy gorny
			x_dir = this->x - 1;
			y_dir = this->y - 1;
		}
		else if (kierunek_ruchu == 10) { // prawy dolny
			x_dir = this->x + 1;
			y_dir = this->y + 1;
		}
		else if (kierunek_ruchu == 11) { // lewy dolny
			x_dir = this->x - 1;
			y_dir = this->y + 1;
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

bool Antylopa::reakcja_na_atak(Organizm* atakujacy) {
	if (atakujacy->get_name() != this->get_name()) {
		int szansa = rand() % 2;
		if (szansa == 0) { // ucieczka
			this->swiat->tabela_wydarzen.add_row({ "Antylopa", this->name , std::to_string(this->x), std::to_string(this->y), "<===>", atakujacy->get_name(), std::to_string(atakujacy->get_x()), std::to_string(atakujacy->get_y()), "Antylopa ucieka " + atakujacy->get_name() });
			short kierunek_ruchu;
			int x_dir = 0, y_dir = 0;
			bool mozna_wykonac = false;
			bool dostepne_kierunki[4] = { 1 , 1, 1 , 1 };

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

				int ctr = 0;
				for (int j = 0; j < 4; j++) {
					if (dostepne_kierunki[j] == false) {
						ctr += 1;
					}
				}
				if (ctr == 4) {
					mozna_wykonac = false;
					break;
				}

				if (swiat->is_border(x_dir, y_dir, swiat->get_rozmiar_y(), swiat->get_rozmiar_x()) || swiat->organizmy_swiat[y_dir][x_dir]) {
					dostepne_kierunki[kierunek_ruchu] = false;
					continue;
				}
				else {
					mozna_wykonac = true;
				}
			}
			if (mozna_wykonac) {
				//std::cout << this->name << " kierunek ruchu " << x_dir << ' ' << y_dir << '\n';
				swiat->organizmy_swiat[y_dir][x_dir] = true;
				swiat->organizmy_swiat[this->y][this->x] = false;

				this->x = x_dir;
				this->y = y_dir;
			}
			return false;
		}
		else {
			return false;
		}
	}
}
