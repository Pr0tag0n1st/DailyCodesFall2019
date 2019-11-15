#pragma once
//Setting up the main alien spaceship
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>

class AlienShip {
public:
	AlienShip(int x, int y, ALLEGRO_BITMAP* pic);
	void move();
	void draw();
	void kill();
	void decreaseHealth();
	void drawHealth();
	int getX();
	int getY();
	int getHealth();
	bool isAlive();
private:
	int xPos;
	int yPos;
	int xdir;
	int ydir;
	int health;
	bool Alive;
	ALLEGRO_BITMAP* image;
	double angle;



};