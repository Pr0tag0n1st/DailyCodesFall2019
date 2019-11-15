//rainbow mouse circle drawing program
//programmed by Dr. Mo avoiding housework 10/12/19
//adapted from https://wiki.allegro.cc/index.php?title=Allegro_5_Tutorial/Input

#include <stdio.h>
#include <allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
#include<iostream>
using namespace std;

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;

int main(int argc, char** argv)
{
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_BITMAP* bouncer = NULL;
	int xpos = SCREEN_W / 2;
	int ypos = SCREEN_H / 2;
	int rcounter = 0;
	int gcounter = 0;
	int bcounter = 0;
	int widthticker = 0;
	int sizeconstant = 0;
	bool drawCircle = false;
	bool redraw = true;
	bool widthtickerdir = 0;
	int wheel = 0;

	al_init();
	al_install_mouse();
	al_init_primitives_addon();
	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_W, SCREEN_H);

	al_set_mouse_z(0);
	al_set_mouse_w(0);
	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_start_timer(timer);

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			cout << wheel << endl;
			rcounter += 1;
			gcounter += 5;
			bcounter += 3;
			if (widthticker >= 10) {
				widthtickerdir = 1;
			}
			if (widthticker <= 0) {
				widthtickerdir = 0;
			}
			if (widthtickerdir == 0) {
				widthticker++;
			}
			if (widthtickerdir == 1) {
				widthticker -= 1;
			}
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			sizeconstant = al_get_mouse_wheel_precision();

			xpos = ev.mouse.x;
			ypos = ev.mouse.y;
			wheel = ev.mouse.z;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			drawCircle = true;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			drawCircle = false;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			//al_clear_to_color(al_map_rgb(0, 0, 0));

			if (drawCircle == true)
				al_draw_filled_circle(xpos, ypos, wheel + widthticker, al_map_rgb(wheel, ypos+gcounter, xpos * ypos + bcounter));

			al_flip_display();
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

