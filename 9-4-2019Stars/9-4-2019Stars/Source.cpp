#include <iostream>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
using namespace std;

class stars {
private:
	double x;
	double y;
	int rg;

	int b;
	double size;
	double tj;
public:
	stars();
	void draw();
	void move();
	void preposition();
};

int main() {
	al_init();
	al_init_primitives_addon();
	srand(time(NULL));
	bool doexit = false;
	bool redraw = true;
	ALLEGRO_DISPLAY* screen = al_create_display(1000, 1000);
	ALLEGRO_TIMER* timer = al_create_timer(.02);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

	vector<stars*> starfield;
	vector<stars*>::iterator iter3;
	for (int i = 1; i < 200; i++) {
		stars* newStar = new stars();
		starfield.push_back(newStar);
	}

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
			al_flip_display();
		}
	}
	al_destroy_display(screen);
}

stars::stars() {
	x = rand() % 1000;
	y = rand() % 1000;
	rg = rand() % 255;
	b = rand() % 255;
	tj = 1;
	size = rand() % 1 +tj;
}

void stars::draw() {
	al_draw_filled_circle(x, y, size, al_map_rgb(rg, rg, b));
}

void stars::move() {
	y += 1;
}

void stars::preposition() {
	if (y > 1002) {
		y = -2;
	}

}