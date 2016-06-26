#pragma once

#include <string>
#include "Point.h"

class Graphics;
struct SDL_Texture;

class Level {
public:
	Level();
	Level(std::string &mapName, Point spawnPt);
	~Level();

	int init(Graphics & gfx);
	void update(float elapsedTime);
	int addToGfx(Graphics &gfx);

private:
	std::string _mapName;
	Point _spawnPoint;
	Point _size;
	SDL_Texture *_bgTexture;

	int loadMap(std::string mapName, Graphics &gfx);
};