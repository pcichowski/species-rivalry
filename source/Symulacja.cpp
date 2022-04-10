#include "Symulacja.h"
#include "tabulate.hpp"
#include <fstream>

#define LICZBA_TUR 25

Symulacja::Symulacja(){
	main_menu();
	swiat = new Swiat(rozm_x, rozm_y);
	if (load_world_bool) {
		load_organizmy(load_world_input);
	}
}

void Symulacja::game_loop() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	if (load_world_bool) {
		std::cout << "\x1B[33mzaladowano\033[0m\n";
		swiat->rysuj_swiat();
	}
	else {
		std::cout << "@@@@ stan poczatkowy @@@@@\n";

		int czlowiek_x = rand() % rozm_y;
		int czlowiek_y = rand() % rozm_y;

		Organizm* czlowiek = new Czlowiek(czlowiek_y, czlowiek_x);
		swiat->dodaj_organizm(czlowiek);
		//input.set_czlowiek(czlowiek);

		std::cout << "Wygenerowano zwierzeta\n";
		const int liczba_wilkow = 6;
		const int liczba_owiec = 6;
		const int liczba_traw = 5;
		const int liczba_lisow = 10;
		const int liczba_mleczy = 3;
		const int liczba_guarany = 5;
		const int liczba_wilczych_jagod = 3;
		const int liczba_barszczy = 5;
		const int liczba_zolwi = 10;
		const int liczba_antylop = 8;
		for (int i = 0; i < liczba_wilkow; i++) {
			int wilk_x, wilk_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				wilk_x = rand() % swiat->get_rozmiar_x();
				wilk_y = rand() % swiat->get_rozmiar_y();
				if (!swiat->organizmy_swiat[wilk_y][wilk_x]) {
					mozna_postawic = true;
				}
			}
			Organizm* wilk = new Wilk(wilk_y, wilk_x);
			swiat->dodaj_organizm(wilk);
		}
		for (int i = 0; i < liczba_owiec; i++) {
			int owca_x, owca_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				owca_x = rand() % swiat->get_rozmiar_x();
				owca_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[owca_y][owca_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* owca = new Owca(owca_y, owca_x);
			swiat->dodaj_organizm(owca);
		}
		for (int i = 0; i < liczba_traw; i++) {
			int trawa_x, trawa_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				trawa_x = rand() % swiat->get_rozmiar_x();
				trawa_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[trawa_y][trawa_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* trawa = new Trawa(trawa_y, trawa_x);
			swiat->dodaj_organizm(trawa);
		}
		for (int i = 0; i < liczba_mleczy; i++) {
			int mlecz_x, mlecz_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				mlecz_x = rand() % swiat->get_rozmiar_x();
				mlecz_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[mlecz_y][mlecz_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* mlecz = new Mlecz(mlecz_y, mlecz_x);
			swiat->dodaj_organizm(mlecz);
		}
		for (int i = 0; i < liczba_lisow; i++) {
			int lis_x, lis_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				lis_x = rand() % swiat->get_rozmiar_x();
				lis_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[lis_y][lis_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* lis = new Lis(lis_y, lis_x);
			swiat->dodaj_organizm(lis);
		}
		for (int i = 0; i < liczba_guarany; i++) {
			int guarana_x, guarana_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				guarana_x = rand() % swiat->get_rozmiar_x();
				guarana_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[guarana_y][guarana_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* guarana = new Guarana(guarana_y, guarana_x);
			swiat->dodaj_organizm(guarana);
		}
		for (int i = 0; i < liczba_wilczych_jagod; i++) {
			int wilcze_x, wilcze_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				wilcze_x = rand() % swiat->get_rozmiar_x();
				wilcze_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[wilcze_y][wilcze_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* wilcze = new WilczeJagody(wilcze_y, wilcze_x);
			swiat->dodaj_organizm(wilcze);
		}
		for (int i = 0; i < liczba_barszczy; i++) {
			int barszcz_x, barszcz_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				barszcz_x = rand() % swiat->get_rozmiar_x();
				barszcz_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[barszcz_y][barszcz_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* barszcz = new BarszczSosnowskiego(barszcz_y, barszcz_x);
			swiat->dodaj_organizm(barszcz);
		}
		for (int i = 0; i < liczba_zolwi; i++) {
			int zolw_x, zolw_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				zolw_x = rand() % swiat->get_rozmiar_x();
				zolw_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[zolw_y][zolw_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* zolw = new Zolw(zolw_y, zolw_x);
			swiat->dodaj_organizm(zolw);
		}
		for (int i = 0; i < liczba_antylop; i++) {
			int antylopa_x, antylopa_y;
			bool mozna_postawic = false;
			while (!mozna_postawic) {
				antylopa_x = rand() % swiat->get_rozmiar_x();
				antylopa_y = rand() % swiat->get_rozmiar_y();

				if (!swiat->organizmy_swiat[antylopa_y][antylopa_x]) {
					mozna_postawic = true;
				}
			}

			Organizm* antylopa = new Antylopa(antylopa_y, antylopa_x);
			swiat->dodaj_organizm(antylopa);
		}
		//swiat.print_organizmy();
		swiat->rysuj_swiat();
		std::cout << "@@@@@@@@@@@@@\n";
		std::cout << '\n';
	}
	

	for (int i = 0; i < LICZBA_TUR; i++) {
		if (!swiat->koniec) {
			swiat->wykonaj_ture();
			if (swiat->save_world) {
				save_world();
				swiat->save_world = false;
				swiat->rysuj_swiat();
			}
		}
		else {
			break;
		}
	}

}

void Symulacja::main_menu() {
	std::cout << R"(	______                    _ _               _                     _               _                 
	| ___ \                  | (_)             (_)                   | |             | |                
	| |_/ /   ___      ____ _| |_ ______ _  ___ _  __ _    __ _  __ _| |_ _   _ _ __ | | _______      __
	|    / | | \ \ /\ / / _` | | |_  / _` |/ __| |/ _` |  / _` |/ _` | __| | | | '_ \| |/ / _ \ \ /\ / /
	| |\ \ |_| |\ V  V / (_| | | |/ / (_| | (__| | (_| | | (_| | (_| | |_| |_| | | | |   < (_) \ V  V / 
	\_| \_\__, | \_/\_/ \__,_|_|_/___\__,_|\___| |\__,_|  \__, |\__,_|\__|\__,_|_| |_|_|\_\___/ \_/\_/  
	       __/ |                              _/ |         __/ |                                        
	      |___/                              |__/         |___/                                          )";
	std::cout << R"(
		              _            __     __  _                                
		         ___ (_)_ _  __ __/ /__ _/ /_(_)__  ___    ___ ____ ___ _  ___ 
		        (_-</ /  ' \/ // / / _ `/ __/ / _ \/ _ \  / _ `/ _ `/  ' \/ -_)
		       /___/_/_/_/_/\_,_/_/\_,_/\__/_/\___/_//_/  \_, /\_,_/_/_/_/\__/ 
		                                                 /___/                 
)" << '\n';

	std::cout << "\x1B[33m				  Autor: Pawel Cichowski s184465	\033[0m\n\n";

	tabulate::Table sterowanie;
	tabulate::Table add;
	add.add_row({ "Sterowanie:" });
	add.format().width(40);
	add.format().font_align(tabulate::FontAlign::center);
	sterowanie.add_row({ add });
	sterowanie.add_row({ "strza³ki - poruszanie siê" });
	sterowanie.add_row({ "E - specjalna umiejetnosc" });
	sterowanie.add_row({ "Postac grywalna ma taki symbol: &" });
	sterowanie.add_row({ "Gdy specjalna umiejetnosc jest aktywowana tlo staje sie jasnozolte" });
	sterowanie.add_row({ "A gdy umiejetnosc sie odnawia tlo bedzie ciemniejsze" });

	sterowanie.add_row({ "Q - wyjdz z gry" });
	sterowanie.add_row({ "I - wyswietl dziennik wydarzen" });
	sterowanie.add_row({ "O - narysuj aktualny stan swiata" });
	sterowanie.add_row({ "P - wyswietl istniejace organizmy" });
	sterowanie.add_row({ "S - zapisz stan gry" });



	sterowanie.format().font_align(tabulate::FontAlign::center);
	sterowanie.format().width(100);
	sterowanie.format().border_color(tabulate::Color::yellow);
	sterowanie.format().corner_color(tabulate::Color::yellow);
	//sterowanie.row(0).format().font_background_color(tabulate::Color::yellow);
	sterowanie.row(0).cell(0).format().font_background_color(tabulate::Color::yellow);
	sterowanie.row(0).cell(0).format().font_color(tabulate::Color::grey);

	std::cout << sterowanie << '\n' << '\n' << '\n';

	char input;
	std::cout << "\x1B[33m				 Czy chcesz wczytac zapis gry? [T/N]\n\n";
	std::cin >> input;
	std::cout << "\033[0m";
	if (input == 'T' || input == 't') {
		load_world_bool = true;
	}
	if (load_world_bool) {
		load_world();
	}
	else {
		std::cout << "\n\x1B[33m				  Wybierz rozmiar swiata ( x, y )\033[0m\n\n";

		std::cin >> rozm_x >> rozm_y;
	}

}

void Symulacja::set_simulation_running(bool set) {
	this->simulation_running = set;
}

int Symulacja::find_czlowiek(std::vector<Organizm*> organizmy, int liczba) {
	for (int i = 0; i < liczba; i++) {
		if (organizmy[i]->get_name() == "Czlowiek") {
			return i;
		}
	}
	return 0;
}

void Symulacja::save_world() {
	std::ofstream out;
	std::string open_file;

	std::cout << "\x1B[33m";
	std::cout << "Podaj nazwe i rozszerzenie pliku do ktorego chcesz zapisac\n";
	std::cin >> open_file;
	std::cout << "zapisano\033[0m\n";
	open_file = "saves/" + open_file;
	out.open(open_file);

	out << rozm_x << '\n';
	out << rozm_y << '\n';
	out << swiat->get_tura() << '\n';
	out << swiat->liczba_organizmow << '\n';

	swiat->sortuj_wektor();

	for (int i = 0; i < swiat->liczba_organizmow; i++) {
		if (swiat->organizmy[i]->get_name() == "Wilcze Jagody") {
			out << "Wilcze" << ' ' << swiat->organizmy[i]->get_x() << ' ' << swiat->organizmy[i]->get_y() << ' ' << swiat->organizmy[i]->get_age() << ' ' << swiat->organizmy[i]->get_strength() << ' ' << swiat->organizmy[i]->get_initiative() << '\n';
		}
		else if (swiat->organizmy[i]->get_name() == "Barszcz Sosnowskiego") {
			out << "Barszcz" << ' ' << swiat->organizmy[i]->get_x() << ' ' << swiat->organizmy[i]->get_y() << ' ' << swiat->organizmy[i]->get_age() << ' ' << swiat->organizmy[i]->get_strength() << ' ' << swiat->organizmy[i]->get_initiative() << '\n';
		}
		else {
			out << swiat->organizmy[i]->get_name() << ' ' << swiat->organizmy[i]->get_x() << ' ' << swiat->organizmy[i]->get_y() << ' ' << swiat->organizmy[i]->get_age() << ' ' << swiat->organizmy[i]->get_strength() << ' ' << swiat->organizmy[i]->get_initiative() << '\n';
		}
	}

	out << swiat->organizmy[find_czlowiek(swiat->organizmy, swiat->liczba_organizmow)]->ability_active << '\n';
	out << swiat->organizmy[find_czlowiek(swiat->organizmy, swiat->liczba_organizmow)]->ability_cooldown << '\n';
	out << swiat->organizmy[find_czlowiek(swiat->organizmy, swiat->liczba_organizmow)]->ability_duration << '\n';
	

	out.close();
}

void Symulacja::load_world() {
	std::string open_file;

	std::cout << "\x1B[33m";
	std::cout << "Podaj nazwe i rozszerzenie pliku ktory chcesz wczytac\n";
	std::cin >> open_file;
	open_file = "saves/" + open_file;
	load_world_input = open_file;
	load_rozmiary(open_file);

	std::cout << "\033[0m\n";
}

void Symulacja::load_rozmiary(std::string input) {
	std::ifstream in;
	in.open(input);

	in >> rozm_x;
	in >> rozm_y;

	in.close();
}

void Symulacja::load_organizmy(std::string input) {
	std::ifstream in;
	in.open(input);

	int tura, placeholder_a, placeholder_b, liczba_org;

	in >> placeholder_a;
	in >> placeholder_b;
	in >> tura; swiat->set_tura(tura);
	in >> liczba_org;
	for (int i = 0; i < liczba_org; i++) {
		Organizm* nowy = NULL;
		std::string nazwa;
		int x, y;
		in >> nazwa;
		in >> x >> y;
		if (nazwa == "Czlowiek") {
			nowy = new Czlowiek(y, x);
		}
		else if (nazwa == "Wilk") { nowy = new Wilk(y, x); }
		else if (nazwa == "Owca") { nowy = new Owca(y, x); }
		else if (nazwa == "Antylopa") { nowy = new Antylopa(y, x); }
		else if (nazwa == "Zolw") { nowy = new Zolw(y, x); }
		else if (nazwa == "Mlecz") { nowy = new Mlecz(y, x); }
		else if (nazwa == "Lis") { nowy = new Lis(y, x); }
		else if (nazwa == "Trawa") { nowy = new Trawa(y, x); }
		else if (nazwa == "Guarana") { nowy = new Guarana(y, x); }
		else if (nazwa == "Barszcz") { nowy = new BarszczSosnowskiego(y, x); }
		else if (nazwa == "Wilcze") { nowy = new WilczeJagody(y, x); }
		int age, strength, initiative;
		in >> age >> strength >> initiative;

		nowy->set_age(age);
		nowy->set_strength(strength);

		swiat->dodaj_organizm(nowy);
	}

	in >> swiat->organizmy[find_czlowiek(swiat->organizmy, swiat->liczba_organizmow)]->ability_active;
	in >> swiat->organizmy[find_czlowiek(swiat->organizmy, swiat->liczba_organizmow)]->ability_cooldown;
	in >> swiat->organizmy[find_czlowiek(swiat->organizmy, swiat->liczba_organizmow)]->ability_duration;


	in.close();
}

Symulacja::~Symulacja(){
}
