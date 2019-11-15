//Creating, updating and drawing background stars
#include "Stars.h"
#include <iostream>
using namespace std;
stars::stars() {
	x = rand() % 800;
	y = rand() % 800;
	rg = rand() % 255;
	b = rand() % 255;
	size = rand() % 2 + 2;
}

void stars::draw() {
	al_draw_filled_circle(x, y, size, al_map_rgb(rg, rg, b));
}

void stars::move() {
	y += 1;
}

void stars::preposition() {
	if (y > 802) {
		y = -2;
	}

}