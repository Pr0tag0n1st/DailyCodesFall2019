#include<allegro5/allegro.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<iostream>
using namespace std;

int main() {
	al_init();
	al_install_audio();
	al_init_acodec_addon();

	ALLEGRO_SAMPLE* sample;
	ALLEGRO_SAMPLE* sample2;
	ALLEGRO_SAMPLE* sample3;
	ALLEGRO_SAMPLE* sample4;
	ALLEGRO_SAMPLE* sample5;
	ALLEGRO_TIMER* timer;

	ALLEGRO_SAMPLE_INSTANCE* sampleInstance = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance2 = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance3 = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance4 = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance5 = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_DISPLAY* display = al_create_display(500, 500);



	al_reserve_samples(3);


	sample = al_load_sample("Mortalseinfeld.wav");
	sample2 = al_load_sample("Spaghet.wav");
	sample3 = al_load_sample("Bohemian.wav");
	sample4 = al_load_sample("Salad.wav");
	sample5 = al_load_sample("Doug.wav");


	if (sample == NULL) { cout << "sample didn't load" << endl; system("pause"); }
	if (sample2 == NULL) { cout << "sample2 didn't load" << endl; system("pause"); }
	if (sample3 == NULL) { cout << "sample3 didn't load" << endl; system("pause"); }
	if (sample4 == NULL) { cout << "sample3 didn't load" << endl; system("pause"); }
	if (sample5 == NULL) { cout << "sample3 didn't load" << endl; system("pause"); }


	sampleInstance = al_create_sample_instance(sample);
	sampleInstance2 = al_create_sample_instance(sample2);
	sampleInstance3 = al_create_sample_instance(sample3);
	sampleInstance4 = al_create_sample_instance(sample4);
	sampleInstance5 = al_create_sample_instance(sample5);


	al_set_sample_instance_playmode(sampleInstance, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(sampleInstance2, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(sampleInstance3, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(sampleInstance4, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(sampleInstance5, ALLEGRO_PLAYMODE_LOOP);


	al_attach_sample_instance_to_mixer(sampleInstance, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance2, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance3, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance4, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance5, al_get_default_mixer());

	al_set_sample_instance_gain(sampleInstance5, 4.0);
	al_set_sample_instance_gain(sampleInstance, 0.3);
	al_set_sample_instance_gain(sampleInstance4, 2.0);
	al_set_sample_instance_gain(sampleInstance3, 1.5);
	al_set_sample_instance_gain(sampleInstance2, 2.5);

	al_set_sample_instance_speed(sampleInstance, 2.0);
	al_set_sample_instance_speed(sampleInstance5, 1.5);
	al_set_sample_instance_speed(sampleInstance3, 0.9);
	al_set_sample_instance_speed(sampleInstance2, 1.8);

	al_play_sample_instance(sampleInstance);
	al_play_sample_instance(sampleInstance2);
	al_play_sample_instance(sampleInstance3);
	al_play_sample_instance(sampleInstance4);
	al_play_sample_instance(sampleInstance5);


	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_set_target_bitmap(al_get_backbuffer(display));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	while (1)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			cout << "tick" << endl;
		}
	}
	al_destroy_event_queue(event_queue);
	al_destroy_sample_instance(sampleInstance);
	al_destroy_sample_instance(sampleInstance2);
	al_destroy_sample_instance(sampleInstance3);
	al_destroy_sample_instance(sampleInstance4);
	al_destroy_sample_instance(sampleInstance5);
	al_destroy_sample(sample);
	al_destroy_sample(sample2);
	al_destroy_sample(sample3);
	al_destroy_sample(sample4);
	al_destroy_sample(sample5);
	al_destroy_display(display);
}

