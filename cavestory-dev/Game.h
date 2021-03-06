#pragma once

#include "Player.h"
#include "Level.h"

class Graphics;

class Game {
public:
	Game();
	~Game();

	int init();
	void start();
private:
	void gameLoop();
	void draw(Graphics &gfx);
	void update(float elapsedTime);
	Player _player;
	Level _level;
};