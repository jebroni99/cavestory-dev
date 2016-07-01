#include "Sprite.h"
#include "Graphics.h"

Sprite::Sprite() {
	//
}

Sprite::Sprite(std::string &filepath, int srcX, int srcY, int width, int height, float posX, float posY) :
_filepath(filepath),
_x(posX),
_y(posY),
_srcRect({srcX, srcY, width, height}),
_boundingBox(Rectangle(_x, _y, width * constants::scale, height * constants::scale))
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

void Sprite::update(float elapsedTime) {
	_boundingBox = Rectangle(_x, _y, _srcRect.w * constants::scale, _srcRect.h * constants::scale);
}

Rectangle Sprite::getBoundingBox() {
	return _boundingBox;
}

sides::Side Sprite::getCollisionSide(Rectangle &other) {
	int amtRight, amtLeft, amtTop, amtBottom;

	amtTop = _boundingBox.getTop() - other.getBottom();
	amtLeft = other.getRight() - _boundingBox.getLeft();
	amtBottom = other.getTop() - _boundingBox.getBottom();
	amtRight = _boundingBox.getRight() - other.getLeft();

	int values[4] = {abs(amtTop), abs(amtLeft), abs(amtBottom), abs(amtRight)};
	int lowest = values[0];
	int lowestIdx = 0;
	int i;
	for (i = 0; i < 4; i++) {
		if (values[i] < lowest) {
			lowest = values[i];
			lowestIdx = i;
		}
	}
	return (sides::Side)lowestIdx;
}
