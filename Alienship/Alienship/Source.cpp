



#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <vector>
#include"Alien.h"
#include"Star.h"



using namespace std;
const int SCREEN_W = 800;
const int SCREEN_H = 800;

//class AlienShip {
//public:
//	AlienShip(int x, int y, ALLEGRO_BITMAP* pic);
//	void move();
//	void draw();
//	void decreaseHealth();
//	int getX();
//	int getY();
//	int getHealth();
//
//private:
//	int xPos;
//	int yPos;
//	int xdir = 1;
//	int ydir;
//	int health;
//	ALLEGRO_BITMAP* image;
//	double angle;
//
//
//
//};


int main() {

	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	srand(time(NULL));
	bool doexit = false;
	bool redraw = true;

	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_TIMER* timer = al_create_timer(.02);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_BITMAP* alienmothership = al_load_bitmap("mothership.png");


	int counter = 0;
	AlienShip mothership(500,50, alienmothership);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	while (!doexit) {

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {


			counter++;
			if (counter % 10 == 1)
				mothership.move();

			redraw = true;
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));

			mothership.draw();

			al_flip_display();
		}
	}

	al_destroy_display(display);
}
//
//AlienShip::AlienShip(int x, int y, ALLEGRO_BITMAP* pic) {
//	xPos = x;
//	yPos = y;
//	image = pic;
//	//angle = 0;
//}
//
//int AlienShip::getX() {
//	return xPos;
//}
//
//int AlienShip::getY() {
//	return yPos;
//}
//
//int AlienShip::getHealth() {
//	return health;
//}
//
//void AlienShip::move() {
//	//angle+=.05;
//	////if (angle > 2 * 3.14)
//	//	//angle = 0;
//	//xPos = 800*sin(angle*3.14/2)*cos(angle*3.14)+500;
//	//yPos = 100*cos(angle * 3.14/2)+300;
//	int speed = rand() % 5 + 5;
//	int boundary = rand() % 50 + 50;
//
//	if (xdir == 1)
//		xPos += speed;
//	if (xdir == 1 && xPos > SCREEN_W - 100 - boundary)
//		xdir = 0;
//	if (xdir == 0)
//		xPos -= speed;
//	if (xdir == 0 && xPos < 0 + boundary)
//		xdir = 1;
//}
//
//void AlienShip::draw() {
//	al_draw_bitmap(image, xPos, yPos, NULL);
//}
//
//void AlienShip::decreaseHealth() {
//	health--;
//}
//
