#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <iostream>
#include <vector>
using namespace std;

#include "Alien.h"
#include "Star.h"
#include "Globals.h"
#include "Alien.cpp"
#include "Star.cpp"




int main() {

	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	srand(time(NULL));
	bool doexit = false;
	bool redraw = true;

	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_TIMER* timer = al_create_timer(.2);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_BITMAP* alienmothership = al_load_bitmap("mothership.png");

	vector<stars*> starfield;
	vector<stars*>::iterator iter3;
	for (int i = 1; i < 200; i++) {
		stars* newStar = new stars();
		starfield.push_back(newStar);
	}

	int counter = 0;
	AlienShip mothership(500, 50, alienmothership);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	while (!doexit) {

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			for (iter3 = starfield.begin(); iter3 != starfield.end(); iter3++) {
				(*iter3)->preposition();
				(*iter3)->move();
			}

			counter++;
			if (counter % 100 == 1)
				mothership.move();

			redraw = true;
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));
			for (iter3 = starfield.begin(); iter3 != starfield.end(); iter3++) {

				(*iter3)->draw();
			}
			mothership.draw();

			al_flip_display();
		}
	}

	al_destroy_display(display);
}

