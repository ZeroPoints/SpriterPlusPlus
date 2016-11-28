#include "allegroboxinstanceinfo.h"

#include "../../spriterengine/global/settings.h"

namespace SpriterEngine
{

	AllegroBoxInstanceInfo::AllegroBoxInstanceInfo(point initialSize) :
		BoxInstanceInfo(initialSize)
	{

		colBorder = al_map_rgb_f(1, 1, 1);


		p1.first = 0;
		p1.second = 0;

		p2.first = initialSize.x;
		p2.second = 0;

		p3.first = initialSize.x;
		p3.second = initialSize.y;

		p4.first = 0;
		p4.second = initialSize.y;

	}

	void AllegroBoxInstanceInfo::render()
	{
		if (Settings::renderDebugBoxes)
		{

			al_draw_line(getPosition().x + p1.first, getPosition().y + p1.second, getPosition().x + p2.first, getPosition().y + p2.second, colBorder, 2);
			al_draw_line(getPosition().x + p2.first, getPosition().y + p2.second, getPosition().x + p3.first, getPosition().y + p3.second, colBorder, 2);
			al_draw_line(getPosition().x + p3.first, getPosition().y + p3.second, getPosition().x + p4.first, getPosition().y + p4.second, colBorder, 2);
			al_draw_line(getPosition().x + p4.first, getPosition().y + p4.second, getPosition().x + p1.first, getPosition().y + p1.second, colBorder, 2);


			/*rectangle.setPosition(getPosition().x, getPosition().y);
			rectangle.setRotation(toDegrees(getAngle()));
			rectangle.setScale(getScale().x, getScale().y);
			rectangle.setOrigin(getPivot().x*getSize().x, getPivot().y*getSize().y);
			renderWindow->draw(rectangle);*/
		}
	}

}
