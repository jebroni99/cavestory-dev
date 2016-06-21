#pragma once

#include <string>
#include "SDL_image.h"

class Graphics;
struct SDL_Texture;

class Sprite {
public:
	Sprite();
	virtual ~Sprite();

	int init(Graphics &gfx, std::string &filepath, int srcX, int srcY, int width, int height, float posX, float posY);
	virtual void update();
	int addToGfx(Graphics &gfx, int x, int y);
private:
	SDL_Rect _srcRect;
	SDL_Texture *_spriteSheet;
	float _x, _y;
};