#include "allegroatlasfile.h"

#include "../../spriterengine/global/settings.h"

namespace SpriterEngine
{

	AllegroAtlasFile::AllegroAtlasFile(std::string initialFilePath) :
		AtlasFile(initialFilePath), m_loaded(false)
	{
		initializeFile();
	}

	const ALLEGRO_BITMAP* AllegroAtlasFile::getTexture() const
	{
		return img_;
	}

	void AllegroAtlasFile::initializeFile()
	{
		img_ = al_load_bitmap(path().c_str());

		if (img_ != nullptr)
		{
			m_loaded = true;
		}
		else
		{
			m_loaded = false;
			Settings::Settings::error("AllegroAtlasFile::initializeFile - sfml texture unable to load file from path \"" + path() + "\"");
		}
	}

	void AllegroAtlasFile::renderSprite(UniversalObjectInterface *spriteInfo, const atlasframedata data)
	{
	}

}
