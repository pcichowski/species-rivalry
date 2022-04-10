#include "Swiat.h"
#include <iostream>
#include <ctime>
#include <algorithm>

Swiat::Swiat(int rozmiar_x, int rozmiar_y) {
	liczba_organizmow = 0;
	rozmiar_swiata_y = rozmiar_y;
	rozmiar_swiata_x = rozmiar_y;

	organizmy_swiat = new bool* [rozmiar_swiata_y];
	for (int i = 0; i < rozmiar_swiata_y; i++) {
		organizmy_swiat[i] = new bool[rozmiar_swiata_x];
		for (int j = 0; j < rozmiar_swiata_x; j++) {
			organizmy_swiat[i][j] = false;
		}
	}
	srand(time(NULL));

	tabela_wydarzen.add_row({"Wydarzenie", "Nazwa", "X", "Y", " ", "Nazwa", "X", "Y", "Wynik" });
}

void Swiat::wykonaj_ture() {
	dodaj_licznik_tur();
	sortuj_wektor();
	int liczba_organizmow_temp = this->liczba_organizmow;
	for (std::size_t i = 0; i < liczba_organizmow; ++i) {
		this->organizmy[i]->akcja();
		if (zmniejszona_liczba_organizmow) {
			liczba_organizmow_temp -= 1;
			i -= 1;
			zmniejszona_liczba_organizmow = false;
		}
		else {
			this->organizmy[i]->set_age(this->organizmy[i]->get_age() + 1);
		}
		
	}
	sortuj_wektor();
	//this->print_organizmy();
	this->rysuj_swiat();
	//std::cout << liczba_organizmow << '\n';
	tura_swiata += 1;
}

bool Swiat::is_border(int x, int y, int r_y, int r_x) {
	if ((y <= -1 || y >= r_y) || (x <= -1 || x >= r_x)) {
		return true;
	}
	else {
		return false;
	}
}

void Swiat::rysuj_swiat() {

	for (int i = - 1; i < rozmiar_swiata_y + 1; i++) {
		if (!is_border(i, 0, rozmiar_swiata_y, rozmiar_swiata_x)) {
			std::cout << i;
			if (i <= 9) {
				std::cout << " ";
			}
		}
		else {
			std::cout << "  ";
		}
		std::cout << "  ";
		for (int j = - 1; j < rozmiar_swiata_x + 1; j++) {
			bool narysowano_organizm = false;
			if (is_border(i, j, rozmiar_swiata_y, rozmiar_swiata_x)) {
				std::cout << '#';
			}
			else {
				if (organizmy_swiat[i][j]) {
					//std::cout << "X";
				}
			}
			for (int q = 0; q < liczba_organizmow; q++) {
				if (organizmy[q]->get_y() == i && organizmy[q]->get_x() == j) {
					organizmy[q]->rysowanie();
					narysowano_organizm = true;
				}
			}
			if (!narysowano_organizm && !is_border(i, j, rozmiar_swiata_y, rozmiar_swiata_x)) {
				std::cout << ' ';
			}
			std::cout << ' ';
		}
		std::cout << '\n';
	}
}

bool operator<(const Organizm& a, const Organizm& b) {
	if (a.get_initiative() != b.get_initiative()) {
		return a.get_initiative() > b.get_initiative();
	}
	else {
		return a.get_age() > b.get_age();
	}
}

bool compare(Organizm* a, Organizm* b) {
	if (a->get_initiative() != b->get_initiative()) {
		return a->get_initiative() > b->get_initiative();
	}
	else {
		return a->get_age() > b->get_age();
	}
}

void Swiat::sortuj_wektor() {
	std::sort(organizmy.begin(), organizmy.end(), compare);
}

void Swiat::dodaj_organizm(Organizm* org) {
	org->set_swiat(this);
	organizmy.push_back(org);
	this->liczba_organizmow += 1;
	this->organizmy_swiat[org->get_y()][org->get_x()] = true;
}

void Swiat::dodaj_organizm(Organizm* org, bool front) {
	org->set_swiat(this);
	organizmy.insert(organizmy.begin(), 1, org);
	this->liczba_organizmow += 1;
	this->organizmy_swiat[org->get_y()][org->get_x()] = true;
}

void Swiat::usun_organizm(Organizm* org) {
	std::vector<Organizm*>::iterator itr;
	itr = std::find(organizmy.begin(), organizmy.end(), org);

	if (itr != organizmy.end()) {
		this->organizmy_swiat[org->get_y()][org->get_x()] = false;

		organizmy.erase(itr);
		this->liczba_organizmow -= 1;
		//delete org;
	}

}

void Swiat::print_organizmy(){
	sortuj_wektor();

	tabulate::Table tabela_print;

	tabela_print.add_row({ "Nazwa", "X", "Y", "Inicjatywa", "Sila", "Wiek" });


	for (int i = 0; i < liczba_organizmow; i++) {
		//std::cout << organizmy[i]->get_name() << " x = " << organizmy[i]->get_x() << " y = " << organizmy[i]->get_y() << " age = "<< organizmy[i]->get_age() <<'\n';
		tabela_print.add_row({ organizmy[i]->get_name(), std::to_string(organizmy[i]->get_x()), std::to_string(organizmy[i]->get_y()), std::to_string(organizmy[i]->get_initiative()), std::to_string(organizmy[i]->get_strength()) ,std::to_string(organizmy[i]->get_age()) });
	}
	tabela_print[0].format() 
		.padding_top(1)
		.padding_bottom(1)
		.font_align(tabulate::FontAlign::center)
		.font_style({ tabulate::FontStyle::underline })
		.font_background_color(tabulate::Color::red);
	tabela_print.column(0).format()
		.font_color(tabulate::Color::yellow);
	tabela_print[0][0].format()
		.font_color(tabulate::Color::white);

	std::cout << tabela_print << '\n';
}

void Swiat::print_wydarzenia() {

	tabela_wydarzen.format()
		.border_color(tabulate::Color::cyan)
		.corner_color(tabulate::Color::cyan);
	tabela_wydarzen.column(0).format()
		.font_background_color(tabulate::Color::blue)
		.font_style({ tabulate::FontStyle::bold })
		.padding_left(1)
		.padding_right(1)
		.font_color(tabulate::Color::white);

	std::size_t i = 0;
	for (auto& cell : tabela_wydarzen.column(0)) {
		if (cell.get_text() == "Walka") {
			cell.format().font_background_color(tabulate::Color::red)
				.font_color(tabulate::Color::grey);
		}
		if (cell.get_text() == "Rozmnazanie") {
			cell.format().font_background_color(tabulate::Color::cyan)
				.font_color(tabulate::Color::grey);
		}
		if (cell.get_text() == "Zjadanie") {
			cell.format().font_background_color(tabulate::Color::green)
				.font_color(tabulate::Color::grey);
		}
		if (cell.get_text() == "Guarana") {
			cell.format().font_background_color(tabulate::Color::magenta)
				.font_color(tabulate::Color::grey);
		}
		if (cell.get_text() == "Wilcze Jagody") {
			cell.format().font_background_color(tabulate::Color::red)
				.font_color(tabulate::Color::grey);
		}
		if (cell.get_text() == "Barszcz Sosnowskiego") {
			cell.format().font_background_color(tabulate::Color::grey)
				.font_color(tabulate::Color::white);
		}
		if (cell.get_text() == "Antylopa") {
			cell.format().font_background_color(tabulate::Color::yellow)
				.font_color(tabulate::Color::grey);
		}

		i++;
	}

	std::cout << tabela_wydarzen << '\n';
}
void Swiat::dodaj_licznik_tur() {
	std::string tura = "TURA " + std::to_string(tura_swiata);
	tabela_wydarzen.add_row({ tura ,  " ", " ", " ", " ", " ", " ", " " });
}

int Swiat::get_rozmiar_y() const {
	return rozmiar_swiata_y;
}
int Swiat::get_rozmiar_x() const {
	return rozmiar_swiata_y;
}

void Swiat::set_rozmiar_x(int n) {
}

void Swiat::set_rozmiar_y(int n) {
}

int Swiat::get_tura() const
{
	return tura_swiata;
}

void Swiat::set_tura(int tura) {
	this->tura_swiata = tura;
}

Swiat::~Swiat() {
	for (int i = 0; i < rozmiar_swiata_y; i ++) {
		delete[] organizmy_swiat[i];
	}
	delete[] organizmy_swiat;
}
