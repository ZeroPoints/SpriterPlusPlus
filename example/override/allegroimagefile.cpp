#include "allegroimagefile.h"

#include "../../spriterengine/global/settings.h"

#include "../../spriterengine/objectinfo/universalobjectinterface.h"

#include "allegroatlasfile.h"

namespace SpriterEngine
{

	AllegroImageFile::AllegroImageFile(std::string initialFilePath, point initialDefaultPivot) :
		ImageFile(initialFilePath,initialDefaultPivot)
	{
		initializeFile();
	}

	void AllegroImageFile::initializeFile()
	{


		img_ = al_load_bitmap(path().c_str());

		if (img_ != nullptr)
		{
			// texture.setSmooth(true);
			//sprite.setTexture(texture);
		}
		else
		{
			Settings::Settings::error("AllegroImageFile::initializeFile - sfml texture unable to load file from path \"" + path() + "\"");
		}
	}

	void AllegroImageFile::renderSprite(UniversalObjectInterface * spriteInfo)
	{

		if(atlasFile) {
			//Code from SFML Library implementation

			// Adding of transformations is in the reverse order you would expect.
			//sf::Transform t;
			//if(atlasFrameData.rotated) {
			//	t.translate(spriteInfo->getPosition().x, spriteInfo->getPosition().y);
			//	t.rotate(toDegrees(spriteInfo->getAngle()));
			//	t.scale(spriteInfo->getScale().x, spriteInfo->getScale().y);
			//	t.translate(-spriteInfo->getPivot().x * atlasFrameData.sourceSize.x, -spriteInfo->getPivot().y * atlasFrameData.sourceSize.y);
			//	// Turn it because the image is rotated
			//	t.rotate(-90);
			//	// Translate the cutoff in atlas (spriteSourcePosition is the position of the atlas in the original == offset)
			//	// X and Y swapped
			//	// Also translate it the height (sourceSize.y) up so that the left-up corner of the original image is at the x0 y0.
			//	t.translate(atlasFrameData.spriteSourcePosition.y - atlasFrameData.sourceSize.y, atlasFrameData.spriteSourcePosition.x);
			//}
			//else {
			//	t.translate(spriteInfo->getPosition().x, spriteInfo->getPosition().y);
			//	t.rotate(toDegrees(spriteInfo->getAngle()));
			//	t.scale(spriteInfo->getScale().x, spriteInfo->getScale().y);
			//	// Translate the cutoff in atlas (spriteSourcePosition is the position of the atlas in the original == offset)
			//	// Also translate the pivot at onces (saves an extra instruction)
			//	t.translate(atlasFrameData.spriteSourcePosition.x - spriteInfo->getPivot().x * atlasFrameData.sourceSize.x,
			//				atlasFrameData.spriteSourcePosition.y - spriteInfo->getPivot().y * atlasFrameData.sourceSize.y);
			//}
			//renderWindow->draw(sprite, t);

			al_draw_scaled_rotated_bitmap(
				img_,
				al_get_bitmap_width(img_)*spriteInfo->getPivot().x,
				al_get_bitmap_height(img_)*spriteInfo->getPivot().y,
				spriteInfo->getPosition().x,
				spriteInfo->getPosition().y,
				spriteInfo->getScale().x,
				spriteInfo->getScale().y,
				spriteInfo->getAngle(),
				0
			);
		}
		else {

			al_draw_scaled_rotated_bitmap(
				img_,
				al_get_bitmap_width(img_)*spriteInfo->getPivot().x,
				al_get_bitmap_height(img_)*spriteInfo->getPivot().y,
				spriteInfo->getPosition().x,
				spriteInfo->getPosition().y,
				spriteInfo->getScale().x,
				spriteInfo->getScale().y,
				spriteInfo->getAngle(),
				0
			);
		}
	}

	// Overwritten so we can create the sprite from the texture.
	void AllegroImageFile::setAtlasFile(AtlasFile *initialAtlasFile, atlasframedata initialAtlasFrameData) {
		// First call baseclass implementation
		ImageFile::setAtlasFile(initialAtlasFile, initialAtlasFrameData);

		// atlasFile should be a AllegroAtlasFile
		if(atlasFile && static_cast<AllegroAtlasFile*>(atlasFile)->loaded()) {
			//const sf::Texture *texture = static_cast<AllegroAtlasFile*>(atlasFile)->getTexture();
			//sprite.setTexture(*texture);
			//if(atlasFrameData.rotated) {
			//	// When rotated, the atlasdata framesize are relative to the original. Not the frame
			//	sprite.setTextureRect(sf::IntRect(atlasFrameData.framePosition.x, atlasFrameData.framePosition.y,
			//									  atlasFrameData.frameSize.y, atlasFrameData.frameSize.x));
			//}
			//else {
			//	sprite.setTextureRect(sf::IntRect(atlasFrameData.framePosition.x, atlasFrameData.framePosition.y,
			//									  atlasFrameData.frameSize.x, atlasFrameData.frameSize.y));
			//}
		}
	}
}
