#include "allegrosoundfile.h"

#include "../../spriterengine/global/settings.h"

#include "allegrosoundobjectinforeference.h"

namespace SpriterEngine
{
	AllegroSoundFile::AllegroSoundFile(std::string initialFilePath) :
		SoundFile(initialFilePath)
	{
		initializeFile();
	}

	void AllegroSoundFile::initializeFile()
	{
		/*if (!buffer.loadFromFile(path()))
		{
			Settings::error("AllegroSoundFile::initializeFile - sfml sound buffer unable to load file from path \"" + path() + "\"");
		}*/
	}

	SoundObjectInfoReference * AllegroSoundFile::newSoundInfoReference()
	{
		return new AllegroSoundObjectInfoReference();
	}

}
