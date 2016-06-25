#pragma once

#include <string>
#include "SDL_image.h"

class Graphics;
struct SDL_Texture;

class Sprite {
public:
	Sprite();
	virtual ~Sprite();

	virtual int init(Graphics &gfx, std::string &filepath, int srcX, int srcY, int width, int height, float posX, float posY);
	virtual int addToGfx(Graphics &gfx, int x, int y);
protected:
	SDL_Rect _srcRect;
	SDL_Texture *_spriteSheet;
	float _x, _y;
private:
	void setSpriteLocation(int srcX, int srcY, int width, int height, float posX, float posY);
	int getSpriteSheet(Graphics &gfx, std::string &filepath);
};