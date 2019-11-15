#include <allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
#include <iostream>
using namespace std;

enum KEYLIST { BLACK, WHITE, RED, BLUE, GREEN, YELLOW, PURPLE, ORANGE, PINK };

int main() {
	al_init();
	al_install_keyboard();
	al_init_primitives_addon();
	bool KEYS[9] = { false, false, false, false, false, false, false, false, false };
	ALLEGRO_DISPLAY* display = al_create_display(800, 800);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_set_target_backbuffer(display);
	al_clear_to_color(al_map_rgb(255, 255, 255));


	while (1) {

		ALLEGRO_EVENT ev;
		
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_P:
				KEYS[PURPLE] = true;
				break;
			case ALLEGRO_KEY_Y:
				KEYS[YELLOW] = true;
				break;
			case ALLEGRO_KEY_K:
				KEYS[BLACK] = true;
				break;
			case ALLEGRO_KEY_B:
				KEYS[BLUE] = true;
				break;
			case ALLEGRO_KEY_W:
				KEYS[WHITE] = true;
				break;
			case ALLEGRO_KEY_R:
				KEYS[RED] = true;
				break;
			case ALLEGRO_KEY_G:
				KEYS[GREEN] = true;
				break;
			case ALLEGRO_KEY_O:
				KEYS[ORANGE] = true;
				break;
			case ALLEGRO_KEY_I:
				KEYS[PINK] = true;
				break;
			}
		}

		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_P:
				KEYS[PURPLE] = false;
				break;
			case ALLEGRO_KEY_Y:
				KEYS[YELLOW] = false;
				break;
			case ALLEGRO_KEY_K:
				KEYS[BLACK] = false;
				break;
			case ALLEGRO_KEY_B:
				KEYS[BLUE] = false;
				break;
			case ALLEGRO_KEY_W:
				KEYS[WHITE] = false;
				break;
			case ALLEGRO_KEY_R:
				KEYS[RED] = false;
				break;
			case ALLEGRO_KEY_G:
				KEYS[GREEN] = false;
				break;
			case ALLEGRO_KEY_O:
				KEYS[ORANGE] = false;
				break;
			case ALLEGRO_KEY_I:
				KEYS[PINK] = false;
				break;
			}
		}

		if (al_is_event_queue_empty(event_queue)) {
			if (KEYS[PURPLE] == 1) {
				al_clear_to_color(al_map_rgb(150, 0, 255));
				
			}
			if (KEYS[BLACK] == 1) {

				al_clear_to_color(al_map_rgb(0, 0, 0));
				
			}
			if (KEYS[YELLOW] == 1) {
				al_clear_to_color(al_map_rgb(255, 255, 0));

			}
			if (KEYS[GREEN] == 1) {
				al_clear_to_color(al_map_rgb(0, 255, 0));

			}
			if (KEYS[BLUE] == 1) {
				al_clear_to_color(al_map_rgb(0, 0, 255));

			}
			if (KEYS[WHITE] == 1) {
				al_clear_to_color(al_map_rgb(255, 255, 255));
				
			}
			if (KEYS[RED] == 1) {
				al_clear_to_color(al_map_rgb(255, 0, 0));

			}
			if (KEYS[ORANGE] == 1) {
				al_clear_to_color(al_map_rgb(255, 180, 0));

			}
			if (KEYS[PINK] == 1) {
				al_clear_to_color(al_map_rgb(255, 100, 200));

			}
			al_flip_display();
		}




	}
}