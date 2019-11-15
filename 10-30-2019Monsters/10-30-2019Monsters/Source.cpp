#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
using namespace std;

class Monster{
public:
	void initMonster(int xposition, int yposition, ALLEGRO_BITMAP* image, int moves);
	void draw();
	void move();

private:
	ALLEGRO_BITMAP* picture;
	int initxpos;
	int xpos;
	int initypos;
	int ypos;
	int dir;
	int vel;
	int movetype;

};

int main() {
	bool redraw = false;
	al_init();
	al_init_image_addon();
	ALLEGRO_DISPLAY* display = al_create_display(800, 800);
	ALLEGRO_TIMER* timer = al_create_timer(1 / 60);
	ALLEGRO_BITMAP* image1 = al_load_bitmap("NU.png");
	ALLEGRO_BITMAP* image2 = al_load_bitmap("GreenUnit.png");
	ALLEGRO_BITMAP* image3 = al_load_bitmap("Trubbish.jfif");
	al_set_target_backbuffer(display);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_convert_mask_to_alpha(image1, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(image2, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(image3, al_map_rgb(255, 255, 255));

	Monster monster1;
	Monster monster2;
	Monster monster3;
	Monster monster4;
	Monster monster5;


	monster1.initMonster(300, 100, image1, 1);
	monster2.initMonster(550, 600, image2, 2);
	monster3.initMonster(475, 300, image3, 1);
	monster4.initMonster(400, 200, image1, 2);
	monster5.initMonster(100, 500, image3, 2);

	//al_start_timer(timer);
	while (true) {
		monster1.move();
		monster2.move();
		monster3.move();
		monster4.move();
		monster5.move();

		al_clear_to_color(al_map_rgb(0, 0, 0));
		monster1.draw();
		monster2.draw();
		monster3.draw();
		monster4.draw();
		monster5.draw();
		al_flip_display();
		al_rest(0.005);
	}
	
}

void Monster::initMonster(int xposition, int yposition, ALLEGRO_BITMAP* image, int moves) {
	xpos = xposition;
	ypos = yposition;
	initypos = ypos;
	picture = image;
	movetype = moves;
	vel = 1;
}

void Monster::move() {

	if (movetype == 1) {
		xpos += vel;
		if (xpos > 800) {
			vel = -1;
		}
		else if (xpos < 0){
			vel = 1;
		}
	}
	if (movetype == 2) {
		xpos += vel;
		ypos += vel;
		if (xpos > 800) {
			vel = -1;
		}
		else if (xpos < 0){
			vel = 1;
		}
	}

}
void Monster::draw() {
	al_draw_bitmap(picture, xpos, ypos, 0);
}