#pragma once
#include "Czlowiek.h"


class Organizm;

class Input {

	

	//Organizm* czlowiek;

public:

	void get_input_from_keyboard();
	void handle_movement();

	void set_czlowiek(Organizm* czlowiek);
	int get_key_pressed() const;
};
