#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main() {
	int SCREEN_W = 720;
	int SCREEN_H = 540;

	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();


	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_FONT* font = NULL;

	display = al_create_display(SCREEN_W, SCREEN_H);

	al_set_target_backbuffer(display);
	al_clear_to_color(al_map_rgb(155, 155, 155));

	font = al_create_builtin_font();


	al_draw_filled_circle((2*SCREEN_W) / 3-60, SCREEN_H / 2, 35, al_map_rgb(0, 0, 0));
	al_draw_filled_circle(SCREEN_W / 3+60, SCREEN_H / 2, 35, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(SCREEN_W / 3, SCREEN_H / 2, (2 * SCREEN_W) / 3, SCREEN_H / 3, al_map_rgb(120, 20, 20));
	al_draw_filled_triangle(SCREEN_W / 3, SCREEN_H / 2, SCREEN_W / 3, SCREEN_H / 3, SCREEN_W / 4, SCREEN_H / 2, al_map_rgb(120, 20, 20));
	al_draw_filled_triangle((2*SCREEN_W )/ 3, SCREEN_H / 2, (SCREEN_W*2) / 3, SCREEN_H / 3, (4*SCREEN_W) / 5, SCREEN_H / 2, al_map_rgb(120, 20, 20));
	al_draw_textf(font, al_map_rgb(0, 0, 0),  SCREEN_W / 2, (2 * SCREEN_H) / 5, 0, "IT'S DRIFTING TIME");

	al_flip_display();
	al_rest(15);
}