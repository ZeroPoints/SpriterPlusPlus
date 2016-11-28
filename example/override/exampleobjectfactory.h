#ifndef EXAMPLEOBJECTFACTORY_H
#define EXAMPLEOBJECTFACTORY_H

//#include "SFML/Graphics/RenderWindow.hpp"

#include "../../spriterengine/override/objectfactory.h"

namespace SpriterEngine
{

	class ExampleObjectFactory : public ObjectFactory
	{
	public:
		ExampleObjectFactory();
		
		PointInstanceInfo *newPointInstanceInfo() override;

		BoxInstanceInfo *newBoxInstanceInfo(point size) override;

		BoneInstanceInfo *newBoneInstanceInfo(point size) override;

	private:
	};

}

#endif // EXAMPLEOBJECTFACTORY_H
