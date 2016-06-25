#include "Sprite.h"
#include "Graphics.h"
#include "Constants.h"

Sprite::Sprite() {
	//
}

Sprite::Sprite(std::string &filepath, int srcX, int srcY, int width, int height, float posX, float posY) :
_filepath(filepath),
_x(posX),
_y(posY),
_srcRect({srcX, srcY, width, height})
{
	//
}

Sprite::~Sprite() {
	//
}

int Sprite::init(Graphics &gfx) {
	return getSpriteSheet(gfx);
}

int Sprite::getSpriteSheet(Graphics &gfx) {
	_spriteSheet = SDL_CreateTextureFromSurface(gfx.getRenderer(), gfx.loadImage(_filepath));
	if (_spriteSheet == NULL)
		return 1;

	return 0;
}

int Sprite::addToGfx(Graphics &gfx, int x, int y) {
	SDL_Rect destRect = {x, y, _srcRect.w * constants::scale, _srcRect.h * constants::scale};
	return gfx.placeSprite(_spriteSheet, &_srcRect, &destRect);
}