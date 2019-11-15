#include <allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
using namespace std;

//constants: variables that shouldn't change once the game starts
const float FPS = 60;
const int SCREEN_W = 800;
const int SCREEN_H = 800;


//Collision function for ball collision
bool Collision(int b1x, int b2x, int b1y, int b2y, int ballmod, int playerwidth, int playerheight);

//enumeration to help you remember what numbers represent which directions
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_W, KEY_S
};

int main()
{
	//set up allegro
	al_init();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	//set up game screen, event queue, and timer
	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	ALLEGRO_FONT* typeface = al_create_builtin_font();
	al_start_timer(timer);

	//position of BALL
	double xPos = 400;
	double yPos = 700;
	int xvel = 6;
	int yvel = 6;

	//size variables
	int ballsize = 32;
	int paddlewidth = 16;
	int paddleheight = 80;

	//player position variables
	double p1x = 16;
	double p1y = 16;
	double p2x = SCREEN_W - (paddlewidth*2);
	double p2y = 16;

	//game variables
	bool key[4] = { false, false, false, false }; //holds key clicks
	bool redraw = true; //variable needed for render section
	bool doexit = false; //handles game loop
	int p1score = 0;
	int p2score = 0;
	int startup = 180;
	int frames = 60;

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

			if (Collision(xPos, yPos, p1x, p1y, ballsize, paddlewidth, paddleheight) == true) {
				cout << "Collide left" << endl;
				xvel *= -1;
			}
			if (Collision(xPos, yPos, p2x, p2y, ballsize, paddlewidth, paddleheight) == true) {
				cout << "Collide right" << endl;
				xvel *= -1;
			}

			startup--;//Stop the ball from instantly moving
			if (startup < 0) {
				//move the BALL
				yPos += yvel;
				xPos += xvel;
			}
			//bounce off the ceiling
			if (yPos < 0 || yPos + ballsize > SCREEN_H) {
				yvel *= -1;
			}

			//bounce off the left wall, add 1 to right player's score
			if (xPos < 0) {
				xvel *= -1;
				p2score++;
			}
			//bounce off right wall, add 1 to left player's score
			if (xPos + ballsize > SCREEN_W) {
				xvel *= -1;
				p1score++;
			}

			//move player 4 pixels in a direction when key is pressed
			if (key[KEY_UP] && p2y > 0) {
				p2y -= 4.0;
			}

			if (key[KEY_DOWN] && p2y + paddleheight < SCREEN_H) {
				p2y += 4.0;
			}

			if (key[KEY_W] && p1y > 0) {
				p1y -= 4.0;
			}

			if (key[KEY_S] && p1y + paddleheight < SCREEN_H) {
				p1y += 4.0;
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

			case ALLEGRO_KEY_W:
				key[KEY_W] = true;
				break;

			case ALLEGRO_KEY_S:
				key[KEY_S] = true;
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

			case ALLEGRO_KEY_W:
				key[KEY_W] = false;
				break;

			case ALLEGRO_KEY_S:
				key[KEY_S] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}

		//render section//////////////////////////////////////////////////
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0)); //wipe screen black between drawing (without this things smear)

			al_draw_filled_rectangle(xPos, yPos, xPos + ballsize, yPos + ballsize, al_map_rgb(255, 255, 255)); //draw the BALL

			al_draw_filled_rectangle(p1x, p1y, p1x + paddlewidth, p1y + paddleheight, al_map_rgb(255, 0, 0)); // draw the left player

			al_draw_filled_rectangle(p2x, p2y, p2x + paddlewidth, p2y + paddleheight, al_map_rgb(0, 0, 255));

			al_draw_textf(typeface, al_map_rgb(255, 0, 0), ballsize, ballsize, ALLEGRO_ALIGN_LEFT, "%d", p1score);
			al_draw_textf(typeface, al_map_rgb(0, 0, 255), SCREEN_W - ballsize, ballsize, ALLEGRO_ALIGN_RIGHT, "%d", p2score);

			if (startup > 0)
			al_draw_textf(typeface, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTER, "%d", startup / frames );

			al_flip_display(); //flip everything from memory to gamescreen
		}//end render


	}//end game loop

	//clean up memory
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}


bool Collision(int b1x, int b1y, int b2x, int b2y, int ballmod, int playerwidth, int playerheight) {
	if ((b1x + ballmod < b2x) ||
		(b1x > b2x + playerwidth) ||
		(b1y > b2y + playerheight) ||
		(b1y + ballmod < b2y)) {
		return false;
	}
	else
		return true;
}