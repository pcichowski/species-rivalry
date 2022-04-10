#pragma once
#include "Swiat.h"
#include "Organizm.h"
#include "animals/Wilk.h"
#include "animals/Owca.h"
#include "animals/Czlowiek.h"
#include "animals/Lis.h"
#include "animals/Zolw.h"
#include "animals/Antylopa.h"
#include "plants/Trawa.h"
#include "plants/Mlecz.h"
#include "plants/Guarana.h"
#include "plants/WilczeJagody.h"
#include "plants/BarszczSosnowskiego.h"

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

