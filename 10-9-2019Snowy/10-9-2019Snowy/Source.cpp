#include <iostream>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
using namespace std;

class Snow {
private:
	double x;
	double y;
	int rg;

	int b;
	double size;
public:
	Snow();
	void draw();
	void move();
	void preposition();
};

class Snow2 {
private:
	double x;
	double y;
	int rg;

	int b;
	double size;
public:
	Snow2();
	void draw();
	void move();
	void preposition();
};

class Snow3 {
private:
	double x;
	double y;
	int rg;

	int b;
	double size;
public:
	Snow3();
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

	vector<Snow*> snowfield;
	vector<Snow*>::iterator iter;
	for (int i = 1; i < 200; i++) {
		Snow* newSnow = new Snow();
		snowfield.push_back(newSnow);
	}

	vector<Snow2*> snowfield2;
	vector<Snow2*>::iterator iter2;
	for (int i = 1; i < 200; i++) {
		Snow2* newSnow2 = new Snow2();
		snowfield2.push_back(newSnow2);
	}

	vector<Snow3*> snowfield3;
	vector<Snow3*>::iterator iter3;
	for (int i = 1; i < 200; i++) {
		Snow3* newSnow3 = new Snow3();
		snowfield3.push_back(newSnow3);
	}

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	while (!doexit) {


		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			for (iter = snowfield.begin(); iter != snowfield.end(); iter++) {
				(*iter)->preposition();
				(*iter)->move();
			}
			for (iter2 = snowfield2.begin(); iter2 != snowfield2.end(); iter2++) {
				(*iter2)->preposition();
				(*iter2)->move();
			}

			for (iter3 = snowfield3.begin(); iter3 != snowfield3.end(); iter3++) {
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


			al_clear_to_color(al_map_rgb(100, 100, 255));
			for (iter = snowfield.begin(); iter != snowfield.end(); iter++) {
				(*iter)->draw();
			}
			for (iter2 = snowfield2.begin(); iter2 != snowfield2.end(); iter2++) {
				(*iter2)->draw();
			}
			for (iter3 = snowfield3.begin(); iter3 != snowfield3.end(); iter3++) {
				(*iter3)->draw();
			}
			al_flip_display();
		}
	}
	al_destroy_display(screen);
}

Snow::Snow() {
	x = rand() % 1000;
	y = rand() % 1000;
	rg = 255;
	b = 255;
	size = rand() % 3 + 5;
}

void Snow::draw() {
	al_draw_filled_circle(x, y, size, al_map_rgb(rg, rg, b));
}

void Snow::move() {
	y += 2;
}

void Snow::preposition() {
	if (y > 1002) {
		y = -1;
	}

}

Snow2::Snow2() {
	x = rand() % 1000;
	y = rand() % 1000;
	rg = 255;
	b = 255;
	size = rand() % 2 + 3;
}

void Snow2::draw() {
	al_draw_filled_circle(x, y, size, al_map_rgb(rg, rg, b));
}

void Snow2::move() {
	y += 6;
}

void Snow2::preposition() {
	if (y > 1002) {
		y = -2;
	}

}

Snow3::Snow3() {
	x = rand() % 1000;
	y = rand() % 1000;
	rg = 255;
	b = 255;
	size = rand() % 5 + 7;
}

void Snow3::draw() {
	al_draw_filled_circle(x, y, size, al_map_rgb(rg, rg, b));
}

void Snow3::move() {
	y += 4;
}

void Snow3::preposition() {
	if (y > 1002) {
		y = -2;
	}

}