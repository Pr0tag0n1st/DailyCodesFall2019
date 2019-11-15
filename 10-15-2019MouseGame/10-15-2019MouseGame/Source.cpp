//rainbow mouse circle drawing program
//programmed by Dr. Mo avoiding housework 10/12/19
//adapted from https://wiki.allegro.cc/index.php?title=Allegro_5_Tutorial/Input

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
using namespace std;

bool Collision(int x1, int y1, int x2, int y2, int dist);

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;

int main(int argc, char** argv){
	srand(time(NULL));
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_BITMAP* bouncer = NULL;
	ALLEGRO_FONT* font = NULL;
	int xpos = SCREEN_W / 2;
	int ypos = SCREEN_H / 2;
	int radius = rand() % 30 + 60;
	bool drawCircle = false;
	bool redraw = true;
	int score = 0;
	int maxtimer = 300;
	int countdown = maxtimer;


	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();
	al_init_primitives_addon();
	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_W, SCREEN_H);

	font = al_create_builtin_font();
	al_set_target_bitmap(al_get_backbuffer(display));

	al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTER, "CLICK THE CIRCLES");
	al_flip_display();
	al_rest(2.5);


	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_start_timer(timer);

	while (countdown > 0)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			countdown--;
			if (drawCircle == false) {
				xpos = rand() % SCREEN_W;
				ypos = rand() % SCREEN_H;
				radius = rand() % 30 + 60;
				drawCircle = true;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {

		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			
			if (Collision(xpos, ypos, ev.mouse.x, ev.mouse.y, radius) == true) {
				drawCircle = false;
				score++;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (maxtimer > 60) {
				maxtimer =300 - (score * 20);
			}
			countdown = maxtimer;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			if (drawCircle == true)
				al_draw_filled_circle(xpos, ypos, radius, al_map_rgb(xpos, ypos, xpos * ypos));
			al_draw_textf(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 24, ALLEGRO_ALIGN_CENTER, "SCORE: %d", score);
			al_draw_textf(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 24 + 24, ALLEGRO_ALIGN_CENTER, "TIME: %d", countdown);
			al_flip_display();
		}

	}

	if (countdown <= 0) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_textf(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTER, "FINAL SCORE: %d", score);
		al_flip_display();
		al_rest(2.5);
	}

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

bool Collision(int x1, int y1, int x2, int y2, int dist) {
	double dx = (x2 - x1) * (x2 - x1);
	double dy = (y2 - y1) * (y2 - y1);

	double dxy = sqrt(dx + dy);
	if (dxy < dist) {
		return true;
	}
	else
		return false;


}