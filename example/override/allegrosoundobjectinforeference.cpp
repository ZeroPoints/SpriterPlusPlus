#include "allegrosoundobjectinforeference.h"

namespace SpriterEngine
{

	AllegroSoundObjectInfoReference::AllegroSoundObjectInfoReference()
	{
		//sound.setBuffer(buffer);
	}

	void AllegroSoundObjectInfoReference::playTrigger()
	{
		if (getTriggerCount())
		{
			//sound.play();
		}
	}

	void AllegroSoundObjectInfoReference::setPlaybackVolume()
	{
		//sound.setVolume(100 * getVolume());
	}

	void AllegroSoundObjectInfoReference::setPlaybackPanning()
	{
		//sound.setPosition(100 * getPanning(), 0, 0);
	}

}
