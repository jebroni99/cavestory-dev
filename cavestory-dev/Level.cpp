#include "Level.h"
#include "Graphics.h"
#include "SDL.h"
#include "Constants.h"

Level::Level() {
}

Level::Level(std::string & mapName, Point spawnPoint) :
_mapName(mapName),
_spawnPoint(spawnPoint),
_size(Point(constants::screenWidth, constants::screenHeight))
{
}

Level::~Level() {
}

int Level::init(Graphics &gfx) {
	return loadMap(_mapName, gfx);
}

void Level::update(float elapsedTime) {
}

int Level::addToGfx(Graphics &gfx) {
	SDL_Rect srcRect = {0, 0, 64, 64};
	SDL_Rect destRect;

	int x;
	for (x = 0; x * 64 < _size._x; x++) {
		int y;
		for (y = 0; y * 64 < _size._y; y++) {
			destRect = {x*64 * constants::scale, y*64 * constants::scale, 64 * constants::scale, 64 * constants::scale };
			if (gfx.placeSprite(_bgTexture, &srcRect, &destRect))
				return 1;
		}
	}
	return 0;
}

int Level::loadMap(std::string mapName, Graphics & gfx) {
	//TODO
	SDL_Surface *tmpSurface = gfx.loadImage(std::string("../data/backgrounds/bkBlue.png"));
	if (tmpSurface == NULL)
		return 1;
	_bgTexture = SDL_CreateTextureFromSurface(gfx.getRenderer(), tmpSurface);
	if (_bgTexture == NULL)
		return 1;
	return 0;
}
