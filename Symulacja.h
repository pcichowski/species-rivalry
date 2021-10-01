#pragma once
#include "Swiat.h"
#include "Organizm.h"
#include "Wilk.h"
#include "Owca.h"
#include "Czlowiek.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"

class Symulacja {
	int rozm_x, rozm_y;
	Swiat* swiat;
	std::string load_world_input;

	bool simulation_running = true;
	bool load_world_bool = false;

public:

	Symulacja();

	void game_loop();
	void main_menu();
	void set_simulation_running(bool set);

	int find_czlowiek(std::vector<Organizm*> organizmy, int liczba);

	void save_world();
	void load_world();
	void load_rozmiary(std::string input);
	void load_organizmy(std::string input);


	~Symulacja();
};

