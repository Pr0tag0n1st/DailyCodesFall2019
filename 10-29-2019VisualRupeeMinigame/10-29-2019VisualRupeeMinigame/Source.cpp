#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <ctime>
#include <iostream>
using namespace std;


//Redefines for color simplicity
#define BLACK al_map_rgb(0, 0, 0)
#define WHITE al_map_rgb(255, 255, 255)

//Function declaration
int randomrupeegenerator(int randomnum);

int main() {
	// variables needed for the game
	srand(time(NULL));
	int SCREEN_W = 900;
	int SCREEN_H = 900;
	double FPS = 60;
	int rupees = 100;
	int randomrupee = 0;
	bool redraw = true;
	bool space = false;
	int spacetimer = FPS;
	int rupeedisplay = 0;

	//Getting allegro set up
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	//All the allegro variables
	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_FONT* font = al_create_builtin_font();
	ALLEGRO_BITMAP* rupee1 = al_load_bitmap("Rupee1.jfif");
	ALLEGRO_BITMAP* rupee5 = al_load_bitmap("Rupee5.jfif");
	ALLEGRO_BITMAP* rupee10 = al_load_bitmap("Rupee10.jfif");
	ALLEGRO_BITMAP* rupee20 = al_load_bitmap("Rupee20.jfif");
	ALLEGRO_BITMAP* rupoor20 = al_load_bitmap("rupoor.jfif");
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

	//Starting screen
	al_clear_to_color(WHITE);
	al_draw_textf(font, BLACK, SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTER, "Link has exactly %d rupees in his wallet, let's see how that changes with this minigame!", rupees);
	al_flip_display();
	cout << "Flag1" << endl;
	al_rest(2.5);

	//Registering event sources
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	//Starting the game
	al_start_timer(timer);
	cout << "Flag2" << endl;

	//Start of while loop
	while (rupees > 0) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//Start of timer section
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			cout << "In timer" << endl;
			spacetimer--;
			//Calling and generating the random number, returning a number from a function
			if (space == true && spacetimer > 0) {
				cout << "Space is true" << endl;
				randomrupee = rand() % 101;
				cout << "Generated number "<<randomrupee << endl;
				space = false;
				spacetimer = FPS;
				switch (randomrupeegenerator(randomrupee)) {
					//If the function returns a 1:
				case 1:
					cout << "1 rupee" << endl;
					rupees += 1;
					rupeedisplay = 1;
					break;
					//If the function returns a 5:
				case 5:
					cout << "5 rupees" << endl;
					rupees += 5;
					rupeedisplay = 5;
					break;
					//If the function returns a 10:
				case 10:
					cout << "10 rupees" << endl;
					rupees += 10;
					rupeedisplay = 10;
					break;
					//If the function returns a 20:
				case 20:
					cout << "20 rupees" << endl;
					rupees += 20;
					rupeedisplay = 20;
					break;
					//If the function returns a -20:
				case -20:
					cout << "rupoor 20" << endl;
					rupees -= 20;
					rupeedisplay = -20;
					break;
				default:
					cout << "Goof" << endl;
					al_clear_to_color(WHITE);
					al_draw_textf(font, BLACK, SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTER, "Something went wrong.  I'm not sure how, but Link didn't get anything.");
					al_flip_display();
					al_rest(1.0);
					break;
				}
			}
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (ALLEGRO_KEY_SPACE) {
				space = true;
				spacetimer = FPS;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			if (ALLEGRO_KEY_SPACE) {
				space = false;
			}
		}
		else if (ALLEGRO_EVENT_DISPLAY_CLOSE) {

		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(WHITE);
			if (rupeedisplay == 1) {
				al_draw_bitmap(rupee1, SCREEN_W/2, SCREEN_H/2, ALLEGRO_ALIGN_CENTER);
				al_draw_textf(font, BLACK, SCREEN_W / 2, SCREEN_H - 30, ALLEGRO_ALIGN_CENTER, "Good for Link.  He found one rupee.");
				al_flip_display();
				rupeedisplay = 0;
				al_rest(1.0);
				
			}
			else if (rupeedisplay == 5) {
				al_draw_bitmap(rupee5, SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTER);
				al_draw_textf(font, BLACK, SCREEN_W / 2, SCREEN_H - 30, ALLEGRO_ALIGN_CENTER, "Nice!  Link found five rupees.");
				al_flip_display();
				rupeedisplay = 0;
				al_rest(1.0);
			}
			else if (rupeedisplay == 10) {
				al_draw_bitmap(rupee10, SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTER);
				al_draw_textf(font, BLACK, SCREEN_W / 2, SCREEN_H - 30, ALLEGRO_ALIGN_CENTER, "WOW!  Link found ten rupees!");
				al_flip_display();
				rupeedisplay = 0;
				al_rest(1.0);
			}
			else if (rupeedisplay == 20) {
				al_draw_bitmap(rupee20, SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTER);
				al_draw_textf(font, BLACK, SCREEN_W / 2, SCREEN_H - 30, ALLEGRO_ALIGN_CENTER, "Link just found twenty rupees!  Jackpot!");
				al_flip_display();
				rupeedisplay = 0;
				al_rest(1.0);
			}
			else if (rupeedisplay == -20) {
				al_draw_bitmap(rupoor20, SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTER);
				al_draw_textf(font, BLACK, SCREEN_W / 2, SCREEN_H - 30, ALLEGRO_ALIGN_CENTER, "Link just lost twenty rupees!  Stop gambling!");
				al_flip_display();
				rupeedisplay = 0;
				al_rest(1.0);
			}
			al_draw_textf(font, BLACK, SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTER, "Link currently has %d rupees.", rupees);
			al_flip_display();
			cout << "Redrawing" << endl;
			
		}
	}
}

	int randomrupeegenerator(int randomnum) {
	if (randomnum < 30) {
		return 1;
	}
	else if (30 <= randomnum && randomnum < 50) {
		return 5;
	}
	else if (50 <= randomnum && randomnum < 60) {
		return 10;
	}
	else if (60 <= randomnum && randomnum < 65) {
		return 20;
	}
	else if (65 <= randomnum && randomnum < 100) {
		return -20;
	}
}