#pragma once
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

class AlienShip {
public:
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
	int xdir = 1;
	int ydir;
	int health;
	ALLEGRO_BITMAP* image;
	double angle;



};