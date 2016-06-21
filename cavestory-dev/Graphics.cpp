#include "Graphics.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Constants.h"

using namespace std;
Graphics::Graphics() {
	_window = 0;
	_render = 0;
}

int Graphics::init() {
	int ret = SDL_CreateWindowAndRenderer(constants::screenWidth, constants::screenHeight, 0, &_window, &_render);
	if (ret)
		return ret;
	SDL_SetWindowTitle(_window, "Cavestory");
	return ret;
}

Graphics::~Graphics() {
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_render);
}

SDL_Surface * Graphics::loadImage(std::string &filepath) {
	if (_spriteSheets[filepath] == NULL) {
		_spriteSheets[filepath] = IMG_Load(filepath.c_str());
	}
	return _spriteSheets[filepath];
}

int Graphics::placeSprite(SDL_Texture *src, SDL_Rect *srcRect, SDL_Rect *destRect) {
	return SDL_RenderCopy(_render, src, srcRect, destRect);
}

void Graphics::updateScreen() {
	SDL_RenderPresent(_render);
}

int Graphics::clear() {
	return SDL_RenderClear(_render);
}

SDL_Renderer * Graphics::getRenderer() {
	return _render;
}