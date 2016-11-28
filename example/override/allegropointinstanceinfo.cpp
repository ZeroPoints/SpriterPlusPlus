#include "allegropointinstanceinfo.h"

#include "../../spriterengine/global/settings.h"

namespace SpriterEngine
{

	AllegroPointInstanceInfo::AllegroPointInstanceInfo()
	{
		//circle.setFillColor(sf::Color::Red);
		//circle.setOrigin(5, 5);
	}

	void AllegroPointInstanceInfo::render()
	{
		if (Settings::renderDebugPoints)
		{
			//circle.setPosition(getPosition().x, getPosition().y);
			//circle.setRotation(toDegrees(getAngle()));
			//renderWindow->draw(circle);
		}
	}

}
