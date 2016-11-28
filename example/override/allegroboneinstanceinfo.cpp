#include "allegroboneinstanceinfo.h"

#include "../../spriterengine/global/settings.h"

namespace SpriterEngine
{

	AllegroBoneInstanceInfo::AllegroBoneInstanceInfo(point initialSize) :
		BoneInstanceInfo(initialSize)
	{


		o1.first = 0;
		o1.second = initialSize.y / 2.0;


		p1.first = 0;
		p1.second = 0;

		p2.first = 0;
		p2.second = initialSize.y;

		p3.first = initialSize.x;
		p3.second = initialSize.y / 2.0;
		col = al_map_rgba_f(0, 0, 1, 0.2);
		colBorder = al_map_rgb_f(1, 1, 1);


	}

	void AllegroBoneInstanceInfo::render()
	{
		if (Settings::renderDebugBones)
		{
			//tmp points for manipulation
			std::pair<float, float> tmp1 = p1;
			std::pair<float, float> tmp2 = p2;
			std::pair<float, float> tmp3 = p3;

			//transform
			tmp1.first = tmp1.first;
			tmp1.second = (tmp1.second) * getScale().y;

			tmp2.first = tmp2.first;
			tmp2.second = (tmp2.second) * getScale().y;

			tmp3.first = tmp3.first * getScale().x;
			tmp3.second = (tmp3.second) * getScale().y;


			//rotate
			auto newp1 = AllegroBoneInstanceInfo::RotateTest(o1.first, o1.second, getAngle(), tmp1);
			auto newp2 = AllegroBoneInstanceInfo::RotateTest(o1.first, o1.second, getAngle(), tmp2);
			auto newp3 = AllegroBoneInstanceInfo::RotateTest(o1.first, o1.second, getAngle(), tmp3);


			//draw filled triangle
			al_draw_filled_triangle(
				newp1.first + getPosition().x, 
				newp1.second + getPosition().y, 
				newp2.first + getPosition().x, 
				newp2.second + getPosition().y,
				newp3.first + getPosition().x,
				newp3.second + getPosition().y,
				col);

			//draw border of triangle
			al_draw_triangle(
				newp1.first + getPosition().x,
				newp1.second + getPosition().y,
				newp2.first + getPosition().x,
				newp2.second + getPosition().y,
				newp3.first + getPosition().x,
				newp3.second + getPosition().y,
				colBorder, 2);
			
		}
	}



}
