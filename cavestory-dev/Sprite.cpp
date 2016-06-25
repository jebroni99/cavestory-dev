#include "Sprite.h"
#include "Graphics.h"
#include "Constants.h"

Sprite::Sprite() {
	//
}

Sprite::~Sprite() {
	//
}

int Sprite::init(Graphics &gfx, std::string &filepath, int srcX, int srcY, int width, int height, float posX, float posY) {
	setSpriteLocation(srcX, srcY, width, height, posX, posY);
	return getSpriteSheet(gfx, filepath);
}

void Sprite::setSpriteLocation(int srcX, int srcY, int width, int height, float posX, float posY) {
	_x = posX;
	_y = posY;
	_srcRect.x = srcX;
	_srcRect.y = srcY;
	_srcRect.w = width;
	_srcRect.h = height;
}

int Sprite::getSpriteSheet(Graphics &gfx, std::string &filepath) {
	_spriteSheet = SDL_CreateTextureFromSurface(gfx.getRenderer(), gfx.loadImage(filepath));
	if (_spriteSheet == NULL)
		return 1;

	return 0;
}

int Sprite::addToGfx(Graphics &gfx, int x, int y) {
	SDL_Rect destRect = {x, y, _srcRect.w * constants::scale, _srcRect.h * constants::scale};
	return gfx.placeSprite(_spriteSheet, &_srcRect, &destRect);
}