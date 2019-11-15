#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
class Bullet {
public:
	Bullet(int x, int y, float a);
	void move1();
	void move2();
	void move3();
	void move4();
	void draw();
	void kill();
	bool offScreen();
	bool isAlive();
	int getx();
	int gety();
	void shoot(int x, int y);
	bool collide(double x, double y);


private:
	double xPos = 0;
	double yPos = 0;
	double angle = 0;
	double radius;
	bool Alive;
	int id = 0;

};