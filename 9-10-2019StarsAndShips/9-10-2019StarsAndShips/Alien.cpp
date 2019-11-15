#include "Alien.h"
#include "Globals.h"

; AlienShip::AlienShip(int x, int y, ALLEGRO_BITMAP* pic) {
	xPos = x;
	yPos = y;
	image = pic;
	//angle = 0;
}

int AlienShip::getX() {
	return xPos;
}

int AlienShip::getY() {
	return yPos;
}

int AlienShip::getHealth() {
	return health;
}

void AlienShip::move() {
	//angle+=.05;
	////if (angle > 2 * 3.14)
	//	//angle = 0;
	//xPos = 800*sin(angle*3.14/2)*cos(angle*3.14)+500;
	//yPos = 100*cos(angle * 3.14/2)+300;
	int speed = rand() % 5 + 5;
	int boundary = rand() % 50 + 50;

	if (xdir == 1)
		xPos += speed;
	if (xdir == 1 && xPos > SCREEN_W - 100 - boundary)
		xdir = 0;
	if (xdir == 0)
		xPos -= speed;
	if (xdir == 0 && xPos < 0 + boundary)
		xdir = 1;
}

void AlienShip::draw() {
	al_draw_bitmap(image, xPos, yPos, NULL);
}

void AlienShip::decreaseHealth() {
	health--;
}

