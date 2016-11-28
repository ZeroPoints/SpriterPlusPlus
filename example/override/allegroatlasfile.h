#ifndef ALLEGROATLASFILE_H
#define ALLEGROATLASFILE_H

#include "../../spriterengine/override/atlasfile.h"
#include <allegro5\allegro.h>

//#include <SFML/Graphics.hpp>

namespace SpriterEngine
{
	class AllegroAtlasFile : public AtlasFile
	{
	public:
		AllegroAtlasFile(std::string initialFilePath);

		const ALLEGRO_BITMAP *getTexture() const;

		bool loaded() {return m_loaded;}

	private:
		ALLEGRO_BITMAP *img_;


		void initializeFile();

		void renderSprite(UniversalObjectInterface *spriteInfo, const atlasframedata data) override;

		bool m_loaded;
	};

}

#endif // SFMLATLASFILE_H
