#ifndef ALLEGROIMAGEFILE_H
#define ALLEGROIMAGEFILE_H

#include "../../spriterengine/override/imagefile.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>//images

//#include <SFML/Graphics.hpp>

namespace SpriterEngine
{
	class AllegroImageFile : public ImageFile
	{
	public:
		AllegroImageFile(std::string initialFilePath, point initialDefaultPivot);

		void renderSprite(UniversalObjectInterface *spriteInfo) override;

		void setAtlasFile(AtlasFile *initialAtlasFile, atlasframedata initialAtlasFrameData) override;

	private:
		ALLEGRO_BITMAP *img_;


		void initializeFile();
	};

}

#endif // SFMLIMAGEFILE_H
