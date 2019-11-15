#include "Star.h"
//#include "Globals.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
using namespace std;

stars::stars() {
	x = rand() % 800;
	y = rand() % 800;
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
	size = rand() % 1 + 3;
}

void stars::draw() {
	al_draw_filled_circle(x, y, size, al_map_rgb(r, g, b));
}

void stars::move() {
	y += 3;
}

void stars::preposition() {
	if (y > 800) {
		y = -2;
	}

}