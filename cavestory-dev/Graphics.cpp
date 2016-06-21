#include "Graphics.h"
#include "SDL.h"

using namespace std;
Graphics::Graphics() {
	_window = 0;
	_render = 0;
}

int Graphics::init() {
	int ret = SDL_CreateWindowAndRenderer(640, 480, 0, &_window, &_render);
	if (ret)
		return ret;
	SDL_SetWindowTitle(_window, "Cavestory");
	return ret;
}

Graphics::~Graphics() {
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_render);
}