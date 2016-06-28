#pragma once

#include "Point.h"

struct SDL_Texture;
class Graphics;

class Tile {
public:
	Tile();
	Tile(SDL_Texture *tileSet, Point size, Point tileSetPosition, Point position);
	~Tile();

	int addToGfx(Graphics &gfx);
	void update(float elapsedTime);
private:
	SDL_Texture *_tileSet;
	Point _size;
	Point _tileSetPosition;
	Point _destPosition;
};