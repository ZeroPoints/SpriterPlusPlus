#ifndef ALLEGROBOXINSTANCEINFO_H
#define ALLEGROBOXINSTANCEINFO_H

//#include "SFML/Graphics/RenderWindow.hpp"

//#include "SFML/Graphics/RectangleShape.hpp"

#include "allegro5\allegro.h"
#include <allegro5/allegro_primitives.h>

#include "../../spriterengine/objectinfo/boxinstanceinfo.h"

namespace SpriterEngine
{

	class AllegroBoxInstanceInfo : public BoxInstanceInfo
	{
	public:
		AllegroBoxInstanceInfo(point initialSize);

		void render() override;

	private:

		ALLEGRO_COLOR colBorder;


		std::pair<float, float> p1;
		std::pair<float, float> p2;
		std::pair<float, float> p3;
		std::pair<float, float> p4;


/*
		sf::RenderWindow *renderWindow;

		sf::RectangleShape rectangle;*/
	};

}

#endif // SFMLBOXINSTANCEINFO_H
