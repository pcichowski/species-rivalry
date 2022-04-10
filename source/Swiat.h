#pragma once
#include <vector>
#include "Organizm.h"
#include "tabulate.hpp"

class Swiat{

	int rozmiar_swiata_y;
	int rozmiar_swiata_x;
	int tura_swiata = 0;

public:
	std::vector<Organizm*> organizmy;

	tabulate::Table tabela_tur;
	tabulate::Table tabela_wydarzen;

	bool** organizmy_swiat;

	int liczba_organizmow;
	Swiat(int rozmiar_x, int rozmiar_y);
	void wykonaj_ture();
	void rysuj_swiat();
	void sortuj_wektor();
	bool zmniejszona_liczba_organizmow = false;
	bool zwiekszona_liczba_organizmow = false;

	void dodaj_organizm(Organizm* org);
	void dodaj_organizm(Organizm* org, bool front);
	void usun_organizm(Organizm* org);

	void print_organizmy();
	void print_wydarzenia();
	void dodaj_licznik_tur();

	bool koniec = false;
	bool save_world = false;

	int get_rozmiar_y() const;
	int get_rozmiar_x() const;
	void set_rozmiar_x(int n);
	void set_rozmiar_y(int n);
	int get_tura() const;
	void set_tura(int tura);

	bool is_border(int x, int y, int r_y, int r_x);

	~Swiat();
};

