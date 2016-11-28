#ifndef ALLEGROPOINTINSTANCEINFO_H
#define ALLEGROPOINTINSTANCEINFO_H

//#include "SFML/Graphics/RenderWindow.hpp"

//#include "SFML/Graphics/CircleShape.hpp"

#include "../../spriterengine/objectinfo/pointinstanceinfo.h"

namespace SpriterEngine
{

	class AllegroPointInstanceInfo : public PointInstanceInfo
	{
	public:
		AllegroPointInstanceInfo();

		void render() override;

	private:

		//sf::CircleShape circle;
	};

}

#endif // SFMLPOINTINSTANCEINFO_H
