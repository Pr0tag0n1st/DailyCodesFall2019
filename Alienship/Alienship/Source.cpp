#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <iostream>
using namespace std;

const int SCREEN_W = 1280;
const int SCREEN_H = 720;
class AlienShip {
public:
	AlienShip();
	AlienShip(int x, int y, ALLEGRO_BITMAP* pic);
	void move();
	void draw();
	void decreaseHealth();
	int getX();
	int getY();
	int getHealth();

private:
	int xPos;
	int yPos;
	int xdir;
	int ydir;
	int health;
	ALLEGRO_BITMAP* image;
	double angle;



	};

int main() {

	al_init();
	al_init_image_addon();
	al_init_primitives_addon();

	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_TIMER* timer = al_create_timer(.2);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_BITMAP* alienmothership = al_load_bitmap("mothership.png");

	int counter = 0;
	AlienShip mothership(500,500, alienmothership);

	while (1) {
		counter++;
		if(counter%100==1)
			mothership.move();


		al_clear_to_color(al_map_rgb(0, 0, 0));
		mothership.draw();
		
		al_flip_display();
	}

	al_destroy_display(display);
}

AlienShip::AlienShip(int x, int y, ALLEGRO_BITMAP* pic) {
	xPos = x;
	yPos = y;
	image = pic;
	angle = 0;
}

int AlienShip::getX() {
	return 0;
}

int AlienShip::getY() {
	return 0;
}

int AlienShip::getHealth() {
	return 0;
}

void AlienShip::move() {
	angle+=.05;
	//if (angle > 2 * 3.14)
		//angle = 0;
	xPos = 800*sin(angle*3.14/2)*cos(angle*3.14)+500;
	yPos = 100*cos(angle * 3.14/2)+300;
}

void AlienShip::draw() {
	al_draw_bitmap(image, xPos, yPos, NULL);
}

void AlienShip::decreaseHealth() {

}