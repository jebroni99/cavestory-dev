#pragma once

#include <string>
#include <unordered_map>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Rect;

class Graphics {
public:
	Graphics();
	~Graphics();

	int init();
	SDL_Surface * loadImage(std::string &filepath);

	/* src      = source sprite SHEET
	   srcRect  = specific rectangle from source sprite sheet
	   destRect = spot on the screen to place this sprite
	*/
	int placeSprite(SDL_Texture *src, SDL_Rect *srcRect, SDL_Rect *destRect);
	
	/* renders screen */
	void updateScreen();
	int clear();
	SDL_Renderer * getRenderer();
private:
	SDL_Window *_window;
	SDL_Renderer *_render;

	std::unordered_map<std::string, SDL_Surface*> _spriteSheets;
};