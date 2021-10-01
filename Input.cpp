#include "Input.h"
#include <iostream>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define Q 113
/*
void Input::get_input_from_keyboard() {
	bool enter = false;
	key_pressed = 0;
	while (!enter) {
		int c = 0; 
		switch ( c=_getch() ) {
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
			czlowiek->get_swiat()->koniec = true;
			enter = true;
			break;
		default:
			break;
		}
	}
}

void Input::handle_movement() {
	get_input_from_keyboard();
	//std::cout << key_pressed << '\n';
	if (key_pressed == KEY_UP) {
		czlowiek->ruch_czlowiek(0);
	}
	else if(key_pressed == KEY_DOWN){
		czlowiek->ruch_czlowiek(2);
	}
	else if (key_pressed == KEY_RIGHT) {
		czlowiek->ruch_czlowiek(1);
	}
	else if (key_pressed == KEY_LEFT) {
		czlowiek->ruch_czlowiek(3);
	}
}


void Input::set_czlowiek(Organizm* czlowiek) {
	this->czlowiek = czlowiek;
}

int Input::get_key_pressed() const {
	return key_pressed;
}*/
