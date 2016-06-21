#include "SDL.h"
#include "Game.h"
#include "SDL_Video.h"
#include "SDL_render.h"

using namespace std;

int main(int argc, char *args[]){
	
	Game g;
	if (g.init())
		return 1;
	g.start();

	return 0;
}