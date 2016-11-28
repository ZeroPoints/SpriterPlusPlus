#ifndef ALLEGROBONEINSTANCEINFO_H
#define ALLEGROBONEINSTANCEINFO_H

//#include "SFML/Graphics/RenderWindow.hpp"

//#include "SFML/Graphics/ConvexShape.hpp"


#include "allegro5\allegro.h"
#include <allegro5/allegro_primitives.h>

#include "../../spriterengine/objectinfo/boneinstanceinfo.h"

namespace SpriterEngine
{

	class AllegroBoneInstanceInfo : public BoneInstanceInfo
	{
	public:
		AllegroBoneInstanceInfo(point initialSize);

		void render() override;



	private:

		ALLEGRO_COLOR colBorder;
		ALLEGRO_COLOR col;


		//origin
		std::pair<float, float> o1;

		//point
		std::pair<float, float> p1;
		std::pair<float, float> p2;
		std::pair<float, float> p3;

		//rotate function
		//copy pasted online
		std::pair<float, float> RotateTest(float cx, float cy, real angle, std::pair<float, float> p) {
			float s = sin(angle);
			float c = cos(angle);

			// translate point back to origin:
			p.first -= cx;
			p.second -= cy;

			// rotate point
			float xnew = p.first * c - p.second * s;
			float ynew = p.first * s + p.second * c;

			// translate point back:
			p.first = xnew + cx;
			p.second = ynew + cy;
			return p;
		}
	};

}

#endif // SFMLBONEINSTANCEINFO_H
