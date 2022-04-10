#pragma once
#include <string>

class Swiat;

class Organizm {

protected:
	Swiat* swiat;
	int strength;
	int initiative;
	int x, y;
	int age;
	std::string name;

public:
	virtual void akcja() = 0;
	virtual bool kolizja(Organizm* z_kim) = 0;
	virtual void rysowanie() = 0;
	void set_koordynaty(int x, int y);

	void normalny_ruch();
	virtual bool reakcja_na_atak(Organizm* atakujacy);
	virtual void byc_zjedzonym(Organizm* jedzacy);

	int	get_strength() const;
	int get_initiative() const;
	int get_age() const;
	void set_age(int x);
	int get_x() const;
	int get_y() const;
	std::string get_name() const;
	void add_strength(int x);
	void set_strength(int strength);

	bool is_plant = false;

	bool ability_active = false;
	int ability_duration = 5;
	int ability_cooldown = 0;

	void set_swiat(Swiat* swiat);
	Swiat* get_swiat() const;
	virtual ~Organizm();
};

#include "Swiat.h"