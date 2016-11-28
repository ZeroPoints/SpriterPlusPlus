#include "exampleobjectfactory.h"

#include "allegropointinstanceinfo.h"
#include "allegroboxinstanceinfo.h"
#include "allegroboneinstanceinfo.h"
#include "allegrosoundobjectinforeference.h"

namespace SpriterEngine
{

	ExampleObjectFactory::ExampleObjectFactory()
	{
	}

	PointInstanceInfo * ExampleObjectFactory::newPointInstanceInfo()
	{
		return new AllegroPointInstanceInfo();
	}

	BoxInstanceInfo * ExampleObjectFactory::newBoxInstanceInfo(point size)
	{
		return new AllegroBoxInstanceInfo(size);
	}

	BoneInstanceInfo * ExampleObjectFactory::newBoneInstanceInfo(point size)
	{
		return new AllegroBoneInstanceInfo(size);
	}

}