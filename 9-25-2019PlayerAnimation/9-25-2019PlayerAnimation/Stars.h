#pragma once
//Seting up the background of scrolling stars
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
class stars {
private:
	double x;
	double y;
	int rg;
	int b;
	double size;
public:
	stars();
	void draw();
	void move();
	void preposition();
};