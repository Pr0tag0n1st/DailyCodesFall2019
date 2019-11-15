//Creating, updating, and drawing player projectiles
#include "Missile.h"
#include <iostream>
using namespace std;
Missile::Missile(int x, int y, ALLEGRO_BITMAP* picture) {
	x = xPos;
	y = yPos;
	image = picture;
	radius = 64;
}

void Missile::move() {
	yPos -= 10;
}

void Missile::draw() {
	if (Alive == true) {
		al_draw_bitmap(image, xPos, yPos, 0);
	}
}

void Missile::kill() {
	Alive = false;
}

bool Missile::offScreen() {
	if (yPos < 0) {
		return 1;
	}
	else {
		return 0;
	}
}

bool Missile::isAlive() {
	return Alive;
}

void Missile::shoot(int x, int y) {
	Alive = true;
	xPos = x + 14;
	yPos = y;
	

}

bool Missile::collide(double x, double y) {
	double dx = (x - xPos) * (x - xPos);
	double dy = (y - yPos) * (y - yPos);

	double dxy = sqrt(dx + dy);

	if (dxy < radius) {
		return true;
	}
	else
		return false;

}