#include "Czlowiek.h"
#include <iostream>
#include <conio.h>

Czlowiek::Czlowiek() {
}

Czlowiek::Czlowiek(int y, int x) {
	this->x = x;
	this->y = y;
	this->strength = 5;
	this->initiative = 4;
	this->age = 0;
	this->name = "Czlowiek";
}

Czlowiek::~Czlowiek() {
}

void Czlowiek::akcja() {
	this->handle_movement();
	special_ability();
}

bool Czlowiek::walka(Organizm* z_kim) {

	//std::cout << "WALKA " << this->name << ' ' << this->x << ' ' << this->y << " sila " << this->strength << " z " << z_kim->get_name() << ' ' << z_kim->get_x() << ' ' << z_kim->get_y() << " sila " << z_kim->get_strength() << "\n";
	if (z_kim == NULL) {
		std::cout << "Walka z nieistniejacym przeciwnikiem ~!!!!\n";
		return true;
	}
	std::string wynik;
	if (this->strength >= z_kim->get_strength()) {
		wynik = this->name + " wygrywa";
		swiat->usun_organizm(z_kim);
		swiat->zmniejszona_liczba_organizmow = true;
		this->swiat->tabela_wydarzen.add_row({ "Walka", this->name , std::to_string(this->x), std::to_string(this->y), "<===>", z_kim->get_name(), std::to_string(z_kim->get_x()), std::to_string(z_kim->get_y()), wynik });
		//swiat->rysuj_swiat();
		return true;
	}
	else if (this->strength < z_kim->get_strength() && ability_active) {
		wynik = z_kim->get_name() + " wygrywa";
		swiat->usun_organizm(z_kim);
		swiat->zmniejszona_liczba_organizmow = true;
		this->swiat->tabela_wydarzen.add_row({ "Niesmiertelnosc", this->name , std::to_string(this->x), std::to_string(this->y), "<===>", z_kim->get_name(), std::to_string(z_kim->get_x()), std::to_string(z_kim->get_y()), wynik });
		return true;
	}
	else {
		wynik = z_kim->get_name() + " wygrywa";
		swiat->usun_organizm((Organizm*)this);
		swiat->zmniejszona_liczba_organizmow = true;
		this->swiat->tabela_wydarzen.add_row({ "Walka", this->name , std::to_string(this->x), std::to_string(this->y), "<===>", z_kim->get_name(), std::to_string(z_kim->get_x()), std::to_string(z_kim->get_y()), wynik });
		return false;
	}
}

bool Czlowiek::reakcja_na_atak(Organizm* atakujacy) {
	if (ability_active) {
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
		return true;
	}
	return false;
}

void Czlowiek::ruch_czlowiek(short kierunek) {
	short kierunek_ruchu = kierunek;
	int x_dir = 0, y_dir = 0;
	bool mozna_wykonac = false;
	bool zyje = true;

	while (!mozna_wykonac) {
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
			mozna_wykonac = false;
			break;
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
	if (zyje && mozna_wykonac) {
		//std::cout << this->name << " kierunek ruchu " << x_dir << ' ' << y_dir << '\n';
		swiat->organizmy_swiat[y_dir][x_dir] = true;
		swiat->organizmy_swiat[y][x] = false;

		this->x = x_dir;
		this->y = y_dir;
	}
}

bool Czlowiek::kolizja(Organizm* z_kim) {
	if (z_kim->is_plant) {
		z_kim->byc_zjedzonym(this);
		return true;
	}
	else {
		if (
			walka(z_kim)) {
			return true;
		}
		else {
			return false;
		}
	}
}

void Czlowiek::rysowanie() {
	if (ability_active) {
		printf("\033[3;103;30m&\033[0m");
	}
	else {
		if (ability_cooldown > 0) {
			printf("\033[3;43;93m&\033[0m");
		}
		else {
			printf("\033[3;101;34m&\033[0m");
		}
	}
}

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define Q 113
#define E 101
#define P 112
#define I 105
#define O 111
#define S 115

void Czlowiek::get_input_from_keyboard() {
	bool enter = false;
	key_pressed = 0;
	while (!enter) {
		int c = 0;
		switch (c = _getch()) {
		case KEY_UP:
			key_pressed = KEY_UP;
			break;
		case KEY_DOWN:
			key_pressed = KEY_DOWN;
			break;
		case KEY_RIGHT:
			key_pressed = KEY_RIGHT;
			break;
		case KEY_LEFT:
			key_pressed = KEY_LEFT;
			break;
		case ENTER:
			//std::cout << "enter " << key_pressed << "\n";
			if (key_pressed != 0) {
				enter = true;
			}
			break;
		case Q:
			this->get_swiat()->koniec = true;
			enter = true;
			break;
		case E:
			if (ability_cooldown == 0) {
				this->ability_active = true;
				enter = true;
			}
			break;
		case P:
			this->swiat->print_organizmy();
			break;
		case I:
			this->swiat->print_wydarzenia();
			break;
		case O:
			this->swiat->rysuj_swiat();
			break;
		case S:
			this->swiat->save_world = true;
			break;
		default:
			break;
		}
	}
}

void Czlowiek::handle_movement() {
	get_input_from_keyboard();
	//std::cout << key_pressed << '\n';
	if (key_pressed == KEY_UP) {
		this->ruch_czlowiek(0);
	}
	else if (key_pressed == KEY_DOWN) {
		this->ruch_czlowiek(2);
	}
	else if (key_pressed == KEY_RIGHT) {
		this->ruch_czlowiek(1);
	}
	else if (key_pressed == KEY_LEFT) {
		this->ruch_czlowiek(3);
	}
}

int Czlowiek::get_key_pressed() const {
	return key_pressed;
}

void Czlowiek::special_ability() {
	if (ability_active) {
		ability_cooldown = 5;

		if (ability_duration == 0) {
			ability_active = false;
		}
		else {
			//std::cout << "ability duration = " << ability_duration << '\n';
			ability_duration -= 1;
		}
	}
	else {
		ability_duration = 5;
		if (ability_cooldown > 0) {
			//std::cout << "ability cooldown = " << ability_cooldown << '\n';
			ability_cooldown -= 1;
		}
	}
}


