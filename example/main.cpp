//#include <SFML/Graphics.hpp>

#include <allegro5/allegro.h>
#include <allegro5\allegro_image.h>//images
#include <allegro5/allegro_primitives.h>

// overridden factories to create our special Sfml and TinyXml based objects
#include "override/exampleobjectfactory.h"
#include "override/examplefilefactory.h"

// include to use Spriter animations
#include "../spriterengine/spriterengine.h"
#include "../spriterengine/global/settings.h"

int main()
{
	SpriterEngine::Settings::setErrorFunction(SpriterEngine::Settings::simpleError);

	// setup Sfml Render Window
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	//bool redraw = true;
	al_init();
	const float FPS = 60;
	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(1000, 1000);

	al_install_keyboard();
	al_init_image_addon();
	al_install_mouse();
	al_init_primitives_addon();

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));





	// load Spriter file into SpriterModel object using our custom factories


	//added greyguy resource to example so i could run in debug.
	//switch back to relative directory for proper exe
	SpriterEngine::SpriterModel scmlModel("./GreyGuy/player.scml", new SpriterEngine::ExampleFileFactory(), new SpriterEngine::ExampleObjectFactory());

	//SpriterEngine::SpriterModel scmlModel("./GreyGuy/player.scml", new SpriterEngine::ExampleFileFactory(/*&window*/), new SpriterEngine::ExampleObjectFactory(/*&window*/));
	//SpriterEngine::SpriterModel scmlModel("./GreyGuy/player.scon", new SpriterEngine::ExampleFileFactory(&window), new SpriterEngine::ExampleObjectFactory(&window));
	//SpriterEngine::SpriterModel scmlModel("./GreyGuyAtlas/GreyGuy.scml", new SpriterEngine::ExampleFileFactory(&window), new SpriterEngine::ExampleObjectFactory(&window));

	// create an array to hold instances of our character
	std::vector<SpriterEngine::EntityInstance*> instances;

	




	// create a timer to run our animations
	al_start_timer(timer);
	bool redraw_ = false;
	double lastTimeElapsed = 0;

	while (true)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		// if window is closed delete everything and exit
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{

			


			redraw_ = true;



		}

		//While no timer tick or events happening keep drawing
		while (al_is_event_queue_empty(event_queue))
		{
			redraw_ = false;

			// add more instances until there are 100
			if (instances.size() < 100)
			{
				// create an instance of the entity named "Player"
				instances.push_back(scmlModel.getNewEntityInstance("Player"));
				SpriterEngine::EntityInstance *inst = instances.back();

				if (inst)
				{
					// set the instance's animation to "walk"
					inst->setCurrentAnimation("walk");

					// set the instance's scale, position, and angle to something random
					SpriterEngine::real scale = ((rand() % 1500) + 500) / 1000.0;
					inst->setScale(SpriterEngine::point(scale, scale));

					inst->setPosition(SpriterEngine::point(rand() % 1000, rand() % 1000));


					inst->setAngle(SpriterEngine::toRadians(rand() % 360));
				}

				// update the object count text with the total number of instances
			}


			// update all instances
			double currentTime = (ev.timer.timestamp);
			double timeElapsed = (currentTime - lastTimeElapsed)*1000;
			for (auto& it : instances)
			{
				if (it)
				{
					// tell the instance how much time has elapsed
					it->setTimeElapsed(timeElapsed);
					it->render();
					it->playSoundTriggers();
				}
			}
			lastTimeElapsed = currentTime;


			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}


	for (auto& it : instances)
	{
		delete it;
	}


	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}


