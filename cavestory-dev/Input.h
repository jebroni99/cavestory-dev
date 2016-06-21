#pragma once

#include <unordered_map>
#include "SDL.h"

class Input {
public:
	Input();
	~Input();

	void beginNewFrame();
	void keyUpEvent(SDL_Event &event);
	void keyDownEvent(SDL_Event &event);

	bool wasKeyPressed(SDL_Scancode key);
	bool wasKeyReleased(SDL_Scancode key);
	bool isHeld(SDL_Scancode key);
private:
	std::unordered_map<SDL_Scancode, bool> _heldKeys;
	std::unordered_map<SDL_Scancode, bool> _pressedKeys;
	std::unordered_map<SDL_Scancode, bool> _releasedKeys;
};