#ifndef ALLEGROSOUNDFILE_H
#define ALLEGROSOUNDFILE_H

#include "../../spriterengine/override/soundfile.h"

//#include "SFML/Audio.hpp"

namespace SpriterEngine
{

	class AllegroSoundFile : public SoundFile
	{
	public:
		AllegroSoundFile(std::string initialFilePath);

		SoundObjectInfoReference * newSoundInfoReference();

	private:
		//sf::SoundBuffer buffer;

		void initializeFile();
	};

}

#endif // SFMLSOUNDFILE_H
