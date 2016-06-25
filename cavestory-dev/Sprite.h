#pragma once

#include <string>
#include "SDL_image.h"

class Graphics;
struct SDL_Texture;

class Sprite {
public:
	Sprite();
	Sprite(std::string &filepath, int srcX, int srcY, int width, int height, float posX, float posY);
	virtual ~Sprite();

	virtual int init(Graphics &gfx);
	virtual int addToGfx(Graphics &gfx, int x, int y);
protected:
	SDL_Rect _srcRect;
	SDL_Texture *_spriteSheet;
	float _x, _y;
	std::string _filepath;
private:
	int getSpriteSheet(Graphics &gfx);
};