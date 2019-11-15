//Main, where everything else is handled
#include <iostream>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include "Missile.h"
#include "Stars.h"
#include "Alien.h"
#include "Bullet.h"
#include "PanicClear.h"
using namespace std;
//constants: variables that shouldn't change once the game starts
const float FPS = 60;
const int SCREEN_W = 800;
const int SCREEN_H = 800;


enum DIRECTIONS { UP, DOWN, LEFT, RIGHT };
//enumeration to help you remember what numbers represent which directions
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_Z, KEY_X, KEY_SHIFT
};
int main()
{
	//set up allegro
	int invincibleframes = 0;
	int bullettime = 0;
	int lives = 3;
	int panics = 3;
	int panicrest = 600;
	int justshot = 0;
	int ticker = 0;
	double counter = 0;
	double minbullets = 60;
	int cellNum = 0;
	int dir = 0;
	int movespeed = 6;
	al_init();
	al_init_image_addon();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_font_addon();
	//set up game screen, event queue, and timer
	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_FONT* font = al_create_builtin_font();
	ALLEGRO_BITMAP* shipPic = al_load_bitmap("PlayerShip.png");
	ALLEGRO_BITMAP* missilePic = al_load_bitmap("Missile.png");
	ALLEGRO_BITMAP* shipLives = al_load_bitmap("ShipLifeIcon.png");
	ALLEGRO_BITMAP* panicicon = al_load_bitmap("PanicIcon.png");
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	ALLEGRO_BITMAP* alienmothership = al_load_bitmap("mothership.png");
	ALLEGRO_BITMAP* dinopic = al_load_bitmap("dino.jpg");

	al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

	//start dark for a second
	for (float i = 0; i < 1; i += .0005) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	//fade in
	for (float i = 0; i < 1; i += .001) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_tinted_bitmap(dinopic, al_map_rgba_f(1, 1, 1, i), 0, 0, 0);
		al_flip_display();
	}
	//stay solid for a second
	for (float i = 0; i < 1; i += .001) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_tinted_bitmap(dinopic, al_map_rgba_f(1, 1, 1, 1), 0, 0, 0);
		al_flip_display();
	}
	//fade out
	for (float i = 1; i > 0; i -= .001) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_tinted_bitmap(dinopic, al_map_rgba_f(i, 1, 1, i), 0, 0, 0);
		al_flip_display();
	}





	al_start_timer(timer);
	//position of player
	double xPos = 400;
	double yPos = 700;
	//game variables
	bool key[7] = { false, false, false, false, false, false, false }; //holds key clicks
	bool redraw = true; //variable needed for render section
	bool doexit = false; //handles game loop

	AlienShip mothership(500, 50, alienmothership);

	vector<Missile*> missiles;
	vector<Missile*>::iterator iter;
	for (int i = 0; i < 40; i++) {
		Missile* newMissile = new Missile(0, 0, missilePic);
		missiles.push_back(newMissile);
	}

	vector<PanicButton*> panicbuttons;
	vector<PanicButton*>::iterator paniciter;
	for (int i = 0; i < panics; i++) {
		PanicButton* newButton = new PanicButton(0, 0);
		panicbuttons.push_back(newButton);
	}

	vector<stars*> starfield;
	vector<stars*>::iterator iter3;
	for (int i = 1; i < 200; i++) {
		stars* newStar = new stars();
		starfield.push_back(newStar);
	}

	vector<Bullet*> bullets;
	vector<Bullet*>::iterator bulliter1;

	

	//tell event queue what to look for
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!doexit && lives != 0 && mothership.getHealth() != 0)//game loop!
	{
		ALLEGRO_EVENT ev;

		al_wait_for_event(event_queue, &ev);

		//timer (physics) section////////////////////////////////////////
		if (ev.type == ALLEGRO_EVENT_TIMER) {

			//slows animation so it doesn't move at the speed of the game loop
			for (iter3 = starfield.begin(); iter3 != starfield.end(); iter3++) {
				(*iter3)->preposition();
				(*iter3)->move();
			}
			redraw = true;
			

			invincibleframes++;
			panicrest++;
			bullettime++;
			justshot++;

			
			if (mothership.getHealth() >= 500) {
				counter++;
			}
			if (500 > mothership.getHealth() && mothership.getHealth() >= 300) {
				counter += 2;
			}
			if (300 > mothership.getHealth() && mothership.getHealth() >= 100) {
				counter += 5;
			}
			if (100 > mothership.getHealth()) {
				counter += 10;
			}

			minbullets -= .01;
			if (counter > minbullets) {
				Bullet* newbullet = new Bullet(mothership.getX(), mothership.getY() + 10, 0);
				cout << "Instantiated new bullet1";
				bullets.push_back(newbullet);
				Bullet* newbullet2 = new Bullet(mothership.getX() + 60, mothership.getY() + 10, 3.14);
				cout << "Instantiated new bullet2";
				bullets.push_back(newbullet2);
				counter = 0;
			}


			ticker++;
			if (ticker > 10) {
				ticker = 0;
			}

			if (ticker == 0) {
				cellNum++;
			}

			if (dir == UP || dir == DOWN) {
				if (cellNum > 4)
					cellNum = 0;
			}

			if (dir == LEFT || dir == RIGHT) {
				if (cellNum < 5) {
					cellNum = 5;
				}
				if (cellNum > 9) {
					cellNum = 5;
				}
			}
			//move missiles
			for (iter = missiles.begin(); iter != missiles.end(); iter++) {
				if ((*iter)->isAlive())
					(*iter)->move();
			}
			//CULL THE MISSILES
			for (iter = missiles.begin(); iter != missiles.end(); iter++) {
				if ((*iter)->offScreen())
					(*iter)->kill();
			}

			//shoot function
			for (bulliter1 = bullets.begin(); bulliter1 != bullets.end(); bulliter1++) {
				if ((*bulliter1)->isAlive() == false && mothership.isAlive() == true){
					(*bulliter1)->shoot(mothership.getX()+60, mothership.getY() + 30);
					//iter++;
					//(*bulliter1)->shoot(mothership.getX()+60, mothership.getY()+30);
				}
			}

			//move all the bullets
			for (bulliter1 = bullets.begin(); bulliter1 != bullets.end(); bulliter1++) {
				if ((*bulliter1)->isAlive() && mothership.getHealth() >= 500) {
					(*bulliter1)->move4();
				}
				if ((*bulliter1)->isAlive() && 500 > mothership.getHealth() && mothership.getHealth() >= 300) {
					(*bulliter1)->move3();
				}
				if ((*bulliter1)->isAlive() && 300 > mothership.getHealth() && mothership.getHealth() >= 100) {
					(*bulliter1)->move2();
				}
				if ((*bulliter1)->isAlive() && 100 > mothership.getHealth()) {
					(*bulliter1)->move1();
				}
			}

			//destroying the bullets
			for (bulliter1 = bullets.begin(); bulliter1 != bullets.end(); bulliter1++) {
				if ((*bulliter1)->offScreen()) {
					(*bulliter1)->kill();
					(*bulliter1)->~Bullet();
					bulliter1 = bullets.erase(bulliter1);
				}
			}

			for (iter = missiles.begin(); iter != missiles.end(); iter++) {
				if ((*iter)->isAlive()&& mothership.isAlive()== true)
					if ((*iter)->collide(mothership.getX() + 64.0, mothership.getY() - 16.0)) {
						mothership.decreaseHealth();
						(*iter)->kill();
					}
			}

			for (bulliter1 = bullets.begin(); bulliter1 != bullets.end(); bulliter1++) {
				if ((*bulliter1)->collide(xPos + 14, yPos + 14) && invincibleframes > 5) {
					lives--;
					invincibleframes = 0;
				}
			}


			//move player 4 pixels in a direction when key is pressed
			if (key[KEY_UP] && yPos > 0) {
				yPos -= movespeed;
				dir = UP;
			}
			if (key[KEY_DOWN] && yPos < SCREEN_H - 32) {
				yPos += movespeed;
				dir = DOWN;
			}
			if (key[KEY_LEFT] && xPos > 0) {
				xPos -= movespeed;
				dir = LEFT;
			}
			if (key[KEY_RIGHT] && xPos < SCREEN_W - 32) {
				xPos += movespeed;
				dir = RIGHT;
			}
			if (key[KEY_SHIFT] == true) {
				movespeed = 2;
			}
			if (key[KEY_SHIFT] == false) {
				movespeed = 6;
			}
			if (key[KEY_X] == true) {

				for (paniciter = panicbuttons.begin(); paniciter != panicbuttons.end(); paniciter++) {
					if (((*paniciter)->isAlive()) == false && panicrest > 600) {
						(*paniciter)->detonate(xPos, yPos);
						panicrest = 0;
						panics-=1;
					}
				}

			}
			if (key[KEY_Z]) {
				for (iter = missiles.begin(); iter != missiles.end(); iter++) {
					if (((*iter)->isAlive()) == false && justshot > 5) {
						(*iter)->shoot(xPos, yPos);
						justshot = 0;
					}
				}
			}

			for (paniciter = panicbuttons.begin(); paniciter != panicbuttons.end(); paniciter++) {
				if (panicrest > 60)
					(*paniciter)->destroy();
			}

			mothership.move();
			if (mothership.getHealth() < 0) {
				mothership.kill();
			}


			redraw = true;
		}
		//keyboard and screen sections//////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			case ALLEGRO_KEY_Z:
				key[KEY_Z] = true;
				break;
			case ALLEGRO_KEY_X:
				key[KEY_X] = true;
				break;
			case ALLEGRO_KEY_LSHIFT:
				key[KEY_SHIFT] = true;
				break;
			}

		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;
			case ALLEGRO_KEY_Z:
				key[KEY_Z] = false;
				break;
			case ALLEGRO_KEY_X:
				key[KEY_X] = false;
				break;
			case ALLEGRO_KEY_LSHIFT:
				key[KEY_SHIFT] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;

			}
		}
		//render section//////////////////////////////////////////////////
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0)); //wipe screen black between drawing

			for (iter3 = starfield.begin(); iter3 != starfield.end(); iter3++) {

				(*iter3)->draw();
			}

		//	(without this things smear)
			if (dir == LEFT) {
				al_draw_bitmap_region(shipPic, cellNum * 32, 0, 32, 32, xPos, yPos, ALLEGRO_FLIP_HORIZONTAL); //draw the player
			}
			else{
				al_draw_bitmap_region(shipPic, cellNum * 32, 0, 32, 32, xPos, yPos, NULL); //draw the player
			}

			for (iter = missiles.begin(); iter != missiles.end(); iter++) {
				(*iter)->draw();
			}
			for (bulliter1 = bullets.begin(); bulliter1 != bullets.end(); bulliter1++) {
				(*bulliter1)->draw();
			}
			for (paniciter = panicbuttons.begin(); paniciter != panicbuttons.end(); paniciter++) {
				(*paniciter)->draw();
			}
			for (int i = 0; i < lives; i++) {
				al_draw_bitmap(shipLives, SCREEN_W - (i * 24) - 24, SCREEN_H - 24, 0);
			}
			for (int i = 0; i < panics; i++) {
				al_draw_bitmap(panicicon, (i * 24) + 12, SCREEN_H - 24, 0);
			}

			if (mothership.isAlive()) {
				mothership.drawHealth();
				mothership.draw();
			}

			al_flip_display(); //flip everything from memory to gamescreen
		}//end render

			
	}//end game loop
	if (lives == 0) {
		cout << "You are dead, not big surprise" << endl;
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 2, 0, "You are dead");
		al_flip_display();
		al_rest(3.0);
	}

	if (mothership.getHealth() <= 0) {
		cout << "A winner is you" << endl;
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 2, 0, "You win");
		al_flip_display();
		al_rest(3.0);
	}
		

	//clean up memory
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_bitmap(shipPic);
	al_destroy_bitmap(missilePic);
	al_destroy_bitmap(shipLives);
	al_destroy_bitmap(panicicon);
	al_destroy_font(font);
	al_destroy_bitmap(dinopic);
	al_destroy_event_queue(event_queue);
	return 0;
}

