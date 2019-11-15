#include "Bullet.h"
#include <iostream>
using namespace std;
Bullet::Bullet(int x, int y, float a) {
	x = xPos;
	y = yPos;
	angle = a;
	radius = 10;
	Alive = false;
	if (id != 0) {
		id = 0;
	}
	if (id == 0) {
		id = 1;
	}
}

void Bullet::move1() {
	yPos += 10;
}
void Bullet::move2() {
	angle += .25;
	xPos = xPos + 2*cos(angle);
	yPos+=1;
}
void Bullet::move3() {
	angle += 0.25;
	xPos = xPos + cos(angle)*15;
	yPos +=  5*sin(angle)+5;
}
void Bullet::move4() {
	angle += 0.1;
	if (id == 0) {
		xPos += cos(angle) * 25;
	}
	else if (id == 1) {
		xPos -= cos(angle) * 25;
	}
	yPos += 2 * cos(angle) + 5;
}
void Bullet::draw() {
	if (Alive == true) {
		al_draw_filled_circle(xPos, yPos, radius, al_map_rgb(255, 0, 0));
	}
}

void Bullet::kill() {
	Alive = false;
}

bool Bullet::offScreen() {
	if (yPos > 800) {
		return 1;
	}
	else {
		return 0;
	}
}

bool Bullet::isAlive() {
	return Alive;
}

void Bullet::shoot(int x, int y) {
	Alive = true;
	xPos = x + 14;
	yPos = y;


}

bool Bullet::collide(double x, double y) {
	double dx = (x - xPos) * (x - xPos);
	double dy = (y - yPos) * (y - yPos);

	double dxy = sqrt(dx + dy);

	if (dxy < radius) {
		return true;
	}
	else
		return false;

}