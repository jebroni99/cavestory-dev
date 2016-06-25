#include "Game.h"
#include "Graphics.h"
#include "SDL.h"
#include "Input.h"
#include <algorithm>

const int fps = 50;
const int maxFrameTime = 1000 / fps;

Game::Game() {
}

Game::~Game() {
	//
}

void showPopup(int errCode) {
	std::string s = "Something went wrong, error code: " + std::to_string(errCode);
	SDL_ShowSimpleMessageBox(0, "LOL",  s.c_str(), 0);
}

int Game::init() {
	return SDL_Init(SDL_INIT_EVERYTHING);
}

void Game::start() {
	gameLoop();
}

void Game::draw(Graphics &gfx) {
	gfx.clear();
	int errCode = 0;
	if ((errCode = _player.addToGfx(gfx))) {
		showPopup(errCode);
	}
	gfx.updateScreen();
}

void Game::update(float elapsedTime) {
	float diff = maxFrameTime - elapsedTime;
	_sleep(diff);
	_player.update(maxFrameTime);
}

void Game::gameLoop() {
	Graphics gfx;
	SDL_Event event;
	Input input;
	int errCode = 0;

	if ((errCode = gfx.init())) {
		showPopup(errCode);
		return;
	}
	_player = Player(200, 100);
	if ((errCode = _player.init(gfx))) {
		showPopup(errCode);
		return;
	}

	int lastUpdTime = SDL_GetTicks();
	while (true) {
		input.beginNewFrame();
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				return;
			case SDL_KEYDOWN:
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
				break;
			case SDL_KEYUP:
				input.keyUpEvent(event);
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
			return;
		}
		if (input.isHeld(SDL_SCANCODE_LEFT)) {
			_player.moveLeft();
		}
		if (input.isHeld(SDL_SCANCODE_RIGHT)) {
			_player.moveRight();
		}
		if (!input.isHeld(SDL_SCANCODE_LEFT) && !input.isHeld(SDL_SCANCODE_RIGHT)) {
			_player.stopMoving();
		}
		int currTime = SDL_GetTicks();
		int elapsedTime = currTime - lastUpdTime;
		update(std::min(elapsedTime, maxFrameTime));
		lastUpdTime = currTime;

		draw(gfx);
	}
}