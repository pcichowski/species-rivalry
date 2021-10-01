#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
	int key_pressed;

public:
	Czlowiek();
	Czlowiek(int y, int x);
	~Czlowiek();
	void akcja();
	bool kolizja(Organizm* z_kim);
	void rysowanie();
	bool walka(Organizm* z_kim);
	bool reakcja_na_atak(Organizm* atakujacy);
	void ruch_czlowiek(short kierunek);

	void get_input_from_keyboard();
	void handle_movement();

	int get_key_pressed() const;

	void special_ability();
	
};

