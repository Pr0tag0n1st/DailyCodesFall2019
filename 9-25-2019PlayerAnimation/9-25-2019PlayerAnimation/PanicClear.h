#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
class PanicButton {
public:
	PanicButton(int x, int y);
	void draw();
	void detonate(int x, int y);
	void destroy();
	int getx();
	int gety();
	bool isAlive();
	bool collide(double x, double y);
private:
	double xPos = 0;
	double yPos = 0;
	double angle = 0;
	double radius = 0;
	bool Alive = 0;
	int time = 0;
	ALLEGRO_BITMAP* image;
};