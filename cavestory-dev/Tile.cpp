#include "Tile.h"
#include "Graphics.h"
#include "SDL.h"
#include "Constants.h"

Tile::Tile() {
}

Tile::Tile(SDL_Texture *tileSet, Point size, Point tileSetPosition, Point position) :
_tileSet(tileSet),
_tileSetPosition(tileSetPosition),
_size(size),
_destPosition(Point(position._x * constants::scale, position._y * constants::scale))
{
}

Tile::~Tile() {
}

int Tile::addToGfx(Graphics &gfx) {
	SDL_Rect destRect = {_destPosition._x, _destPosition._y, _size._x * constants::scale, _size._y * constants::scale};
	SDL_Rect srcRect = {_tileSetPosition._x, _tileSetPosition._y, _size._x, _size._y};
	return gfx.placeSprite(_tileSet, &srcRect, &destRect);
}

void Tile::update(float elapsedTime) {
}
