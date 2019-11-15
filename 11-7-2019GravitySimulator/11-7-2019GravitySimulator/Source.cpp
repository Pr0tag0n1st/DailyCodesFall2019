//gravity simulator
//written by Dr. Mo Nov 2019
//uses the Allegro game library found at https://liballeg.org/

#include <allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include<iostream>
using namespace std;

//constants: variables that shouldn't change once the game starts
const float FPS = 60;
const int SCREEN_W = 800;
const int SCREEN_H = 800;
//enumeration to help you remember what numbers represent which directions
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
int main()
{
	//set up allegro
	al_init();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_image_addon();
	//set up game screen, event queue, and timer
	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	ALLEGRO_BITMAP* image = al_load_bitmap("rocket.png");
	al_start_timer(timer);
	//position of player
	double xPos = 400;
	double yPos = 800 - 30;
	double xVel = 0;
	double yVelocity = 0;
	bool isOnGround = false;
	//game variables
	bool key[4] = { false, false, false, false }; //holds key clicks
	bool redraw = true; //variable needed for render section
	bool doexit = false; //handles game loop

	//tell event queue what to look for
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());


	while (!doexit)//game loop!
	{
		ALLEGRO_EVENT ev;

		al_wait_for_event(event_queue, &ev);

		//timer (physics) section////////////////////////////////////////
		if (ev.type == ALLEGRO_EVENT_TIMER) {

			//you'll see things divided by 60 because this code runs at 60 times per second
				//apply gravity!
			if (isOnGround == false)
				yVelocity += 9.8 / 60; //because we're adding 9.8 to this variable *every* game loop, this is actually an acceleration value

			//apply upward acceleration
			if (key[KEY_UP]) {
				yVelocity -= 2.45 / 60; //acceleration of NASA rockets on Earth's surface
			}

			//check if you're on the ground, if not, apply gravity
			else if (yPos + 30 >= 800) {
				isOnGround = true;
				yVelocity = 0; //no velocity when on ground
			}
			else
				isOnGround = false;


			//left and right movement (we can take this out)
			if (key[KEY_LEFT] && xPos > 0) {
				xVel -= 1.0 / 60;
			}
			else if (key[KEY_RIGHT] && xPos + 30 < 800) {
				xVel += 1.0 / 60;
			}
			else
				xVel = 0;

			//update position with velocity
			xPos += xVel;
			yPos += yVelocity;

			//screen bounds checking
			if (yPos + 30 > 800)
				yPos = 800 - 30;
			if (xPos + 30 > 800)
				xPos = 800 - 30;
			if (xPos < 0)
				xPos = 0;

			//bounce pad can go here!!

			if ((xPos + 30 < 100) ||
				(xPos > 200) ||
				(yPos + 30 < SCREEN_H - 30)) {
				cout << "Not Colliding" << endl;
			}
			else {
				cout << "Collision" << endl;
				yVelocity *= -0.9;
			}
			redraw = true;
			cout << xPos << "," << yPos << endl;

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
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
		//render section//////////////////////////////////////////////////
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0)); //wipe screen black between drawing(without this things smear)

			//bounce pad!
			al_draw_filled_rectangle(100, SCREEN_H, 200, SCREEN_H - 30, al_map_rgb(60, 120, 200));

			al_draw_filled_rectangle(xPos, yPos, xPos + 30, yPos + 30, al_map_rgb(250, 40, 50));
			al_flip_display(); //flip everything from memory to gamescreen
		}//end render

	}//end game loop
	//clean up memory
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}
