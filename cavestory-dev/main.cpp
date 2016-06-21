#include "SDL.h"
#include "Graphics.h"
#include "SDL_Video.h"
#include "SDL_render.h"

using namespace std;

int main(int argc, char *args[]){
	SDL_Init(SDL_INIT_EVERYTHING);

	Graphics gfx;
	gfx.init();
	return 0;
}