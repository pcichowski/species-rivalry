#include "Organizm.h"
#include <iostream>
#include "Owca.h"
#include "Wilk.h"
#include "Czlowiek.h"

void Organizm::set_swiat(Swiat* swiat) {
	this->swiat = swiat;
}

Swiat* Organizm::get_swiat() const {
	return swiat;
}

Organizm::~Organizm() {

}

void Organizm::normalny_ruch() {
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
			zyje = this->kolizja(oponent);
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



bool Organizm::reakcja_na_atak(Organizm* atakujacy) {
	return false;
}

void Organizm::byc_zjedzonym(Organizm* jedzacy) {
}

/*
bool Organizm::walka(Organizm* z_kim) {
	this->swiat->tabela_wydarzen.add_row({ "Walka", this->name , std::to_string(this->x), std::to_string(this->y), "<===>", z_kim->name, std::to_string(z_kim->x), std::to_string(z_kim->y) });
	//std::cout << "WALKA " << this->name <<' '<< this->x << ' ' << this->y << " sila "<<this->strength <<" z " << z_kim->name << ' ' << z_kim->x << ' ' << z_kim->y << " sila " << z_kim->strength <<"\n";
	if (z_kim == NULL) {
		std::cout << "Walka z nieistniejacym przeciwnikiem ~!!!!\n";
		return true;
	}
	if (this->strength >= z_kim->strength) {
		swiat->usun_organizm(z_kim);
		//swiat->zmniejszona_liczba_organizmow = true;
		return true;
	}
	else {
		swiat->usun_organizm((Organizm*)this);
		swiat->zmniejszona_liczba_organizmow = true;
		return false;
	}
}

void Organizm::rozmnazaj(Organizm* z_kim) {
	this->swiat->tabela_wydarzen.add_row({ "Rozmnazanie", this->name , std::to_string(this->x), std::to_string(this->y), "<===>", z_kim->name, std::to_string(z_kim->x), std::to_string(z_kim->y) });
	//std::cout << "ROZMNAZANIE ";
	//std::cout << this->name << ' ' << this->x << ' ' << this->y << " z " << z_kim->name << ' ' << z_kim->x << ' ' << z_kim->y <<  "\n";
	if (z_kim == NULL) {
		std::cout << "rozmnazanie z nieistniejacym organizmem~!!!!\n";
		return;
	}

	bool mozna_wykonac = false;
	int kierunek = 0;
	int x_dir = 0;
	int y_dir = 0;
	while (kierunek != 4) {
		kierunek = std::rand() % 4;
		if (kierunek == 0) { // gora
			x_dir = this->x;
			y_dir = this->y - 1;
		}
		else if (kierunek == 1) { //prawo
			x_dir = this->x + 1;
			y_dir = this->y;
		}
		else if (kierunek == 2) { //dol
			x_dir = this->x;
			y_dir = this->y + 1;
		}
		else if (kierunek == 3) { //lewo
			x_dir = this->x - 1;
			y_dir = this->y;
		}

		if (swiat->is_border(x_dir, y_dir, swiat->get_rozmiar_y(), swiat->get_rozmiar_x()) || swiat->organizmy_swiat[y_dir][x_dir]) {

		}
		else {
			//std::cout << "dziecko na " << x_dir << ' ' << y_dir << '\n';
			mozna_wykonac = true;
			break;
		}
		kierunek += 1;
	}
	if (mozna_wykonac) {
		Organizm* dziecko;
		if (this->name == "Owca") {
			dziecko = new Owca(y_dir, x_dir);
		}
		else if (this->name == "Wilk") {
			dziecko = new Wilk(y_dir, x_dir);
		}
		else {
			dziecko = new Owca(y_dir, x_dir);
		}
		swiat->dodaj_organizm(dziecko, 1);
		swiat->zwiekszona_liczba_organizmow = true;
		swiat->sortuj_wektor();
	}
}*/

void Organizm::set_koordynaty(int x, int y) {
	swiat->organizmy_swiat[this->x][this->y] = true;
	this->x = x;
	this->y = y;
	swiat->organizmy_swiat[x][y] = true;
}

int	Organizm::get_strength() const {
	return this->strength;
}
int Organizm::get_initiative() const {
	return this->initiative;
}
int Organizm::get_age() const {
	return age;
}
void Organizm::set_age(int x) {
	this->age = x;
}
int Organizm::get_x() const {
	return x;
}
int Organizm::get_y() const {
	return y;
}

std::string Organizm::get_name() const {
	return name;
}

void Organizm::add_strength(int x) {
	this->strength += x;
}

void Organizm::set_strength(int strength) {
	this->strength = strength;
}
