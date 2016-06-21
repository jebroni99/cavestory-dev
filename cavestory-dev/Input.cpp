#include "Input.h"

Input::Input() {
	//
}

Input::~Input() {
	//
}

void Input::beginNewFrame() {
	_pressedKeys.clear();
	_releasedKeys.clear();
}

void Input::keyUpEvent(SDL_Event &event) {
	_heldKeys[event.key.keysym.scancode] = false;
	_releasedKeys[event.key.keysym.scancode] = true;
}

void Input::keyDownEvent(SDL_Event &event) {
	_pressedKeys[event.key.keysym.scancode] = true;
	_heldKeys[event.key.keysym.scancode] = true;
}

bool Input::wasKeyPressed(SDL_Scancode key) {
	return _pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) {
	return _releasedKeys[key];
}

bool Input::isHeld(SDL_Scancode key) {
	return _heldKeys[key];
}