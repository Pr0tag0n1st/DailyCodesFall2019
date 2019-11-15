#include "PanicClear.h"
#include <iostream>
using namespace std;
PanicButton::PanicButton(int x, int y) {
	x = xPos;
	y = yPos;
	radius = 0;
}
void PanicButton::draw() {
	 
	al_draw_filled_circle(xPos, yPos, radius, al_map_rgb(255, 255, 255));

}
void PanicButton::detonate(int x, int y) {
	xPos = x;
	yPos = y;
	Alive = true;
	for (int i = 0; i < 90; i += 15) {
		radius = i;
	}
}

bool PanicButton::isAlive() {
	return Alive;
}
void PanicButton::destroy() {
	Alive = false;
}
bool PanicButton::collide(double x, double y) {
	double dx = (x - xPos) * (x - xPos);
	double dy = (y - yPos) * (y - yPos);

	double dxy = sqrt(dx + dy);

	if (dxy < radius) {
		return true;
	}
	else
		return false;

}