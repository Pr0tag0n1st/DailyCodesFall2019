#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main() {
	al_init();
	al_init_primitives_addon();
	int SCREEN_W = 720;
	int SCREEN_H = 540;

	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);

	al_set_target_backbuffer(display);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_filled_rounded_rectangle(((3 * SCREEN_W) / 11)-25, ((3 * SCREEN_H) / 11)-25, ((8 * SCREEN_W) / 11)+25, ((8 * SCREEN_H) / 11)+25, 50, 50, al_map_rgb(125, 35, 125));
	al_draw_filled_ellipse(SCREEN_W / 2, SCREEN_H / 2, SCREEN_W / 8, SCREEN_H / 2, al_map_rgb(125, 0, 125));
	al_draw_filled_ellipse((SCREEN_W / 2), SCREEN_H / 2, (SCREEN_W / 2)-50, SCREEN_H / 8, al_map_rgb(125, 0, 125));
	al_draw_filled_triangle((SCREEN_W / 2) + 50, (SCREEN_H / 2) + 50, (SCREEN_W / 2) - 50, (SCREEN_H / 2) + 50, (SCREEN_W / 2), (SCREEN_H/2) + 200, al_map_rgb(175, 20, 175));
	al_draw_filled_triangle((SCREEN_W / 2) + 50, (SCREEN_H / 2) - 50, (SCREEN_W / 2) - 50, (SCREEN_H / 2) - 50, (SCREEN_W / 2), (SCREEN_H / 2) - 200, al_map_rgb(175, 20, 175));
	al_draw_filled_triangle((SCREEN_W / 2) + 50, (SCREEN_H / 2) + 50, (SCREEN_W / 2) + 50, (SCREEN_H / 2) - 50, (SCREEN_W / 2) + 200, (SCREEN_H / 2), al_map_rgb(175, 20, 175));
	al_draw_filled_triangle((SCREEN_W / 2) - 50, (SCREEN_H / 2) + 50, (SCREEN_W / 2) - 50, (SCREEN_H / 2) - 50, (SCREEN_W / 2) - 200, (SCREEN_H / 2), al_map_rgb(175, 20, 175));
	al_draw_filled_circle(SCREEN_W / 2, SCREEN_H / 2, 75, al_map_rgb(255, 255, 10));

	al_flip_display();
	al_rest(15.0);
}