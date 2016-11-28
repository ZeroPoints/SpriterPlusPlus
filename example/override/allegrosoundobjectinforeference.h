#ifndef ALLEGROSOUNDOBJECTINFOREFERENCE_H
#define ALLEGROSOUNDOBJECTINFOREFERENCE_H

#include "../../spriterengine/override/soundobjectinforeference.h"

//#include "SFML/Audio.hpp"

namespace SpriterEngine
{
	

	class AllegroSoundObjectInfoReference : public SoundObjectInfoReference
	{
	public:
		AllegroSoundObjectInfoReference();

		void playTrigger() override;

	private:
		void setPlaybackVolume() override;
		void setPlaybackPanning() override;

		//sf::Sound sound;
	};

}

#endif // SFMLSOUNDOBJECTINFOREFERENCE_H
