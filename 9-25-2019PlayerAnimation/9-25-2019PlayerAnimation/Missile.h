#pragma once
//Setting up the player ship's projectiles
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
class Missile {
public:
	Missile(int x, int y, ALLEGRO_BITMAP* picture);
	void move();
	void draw();
	void kill();
	bool offScreen();
	bool isAlive();
	int getx();
	int gety();
	void shoot(int x, int y);
	bool collide(double x, double y);


private:
	double xPos;
	double yPos;
	double angle = 0;
	double radius;
	bool Alive;
	ALLEGRO_BITMAP* image;


};