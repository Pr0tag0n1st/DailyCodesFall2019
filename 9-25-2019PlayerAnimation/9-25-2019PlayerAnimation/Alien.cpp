//Creating, updating, and drawing the enemy ship
#include "Alien.h"
#include <iostream>
using namespace std;
AlienShip::AlienShip(int x, int y, ALLEGRO_BITMAP* pic) {
	xPos = x;
	yPos = y;
	image = pic;
	angle = 0;
	health = 700;
	xdir = 1;
	ydir = 1;
	Alive = true;
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
	int speed = 3;

	if (ydir == 1)
		yPos += speed;
	if (ydir == 1 && yPos > 200)
		ydir = 0;
	if (ydir == 0)
		yPos -= speed;
	if (ydir == 0 && yPos < 0)
		ydir = 1;

	if (xdir == 1)
		xPos += speed;
	if (xdir == 1 && xPos > 800 - 128)
		xdir = 0;
	if (xdir == 0)
		xPos -= speed;
	if (xdir == 0 && xPos < 0)
		xdir = 1;
}

void AlienShip::draw() {
	al_draw_bitmap(image, xPos, yPos, NULL);
}

void AlienShip::decreaseHealth() {
	health-=5;
	cout << health << endl;
}

void AlienShip::drawHealth() {
	al_draw_rectangle(50, 10, 750, 20, al_map_rgb(255, 255, 255), 2);
	al_draw_filled_rectangle(50, 10, 50 + health, 20, al_map_rgb(255, 0, 0));
}

bool AlienShip::isAlive() {
	return Alive;
}

void AlienShip::kill() {
	Alive = false;
}