#include"AnimatedSprite.h"
#include "Constants.h"
#include "Graphics.h"

AnimatedSprite::AnimatedSprite() :
_frameIdx(0),
_timeElapsed(0),
_visible(true),
_currAnimationOnce(false),
_currAnimation("")
{
	//
}

AnimatedSprite::~AnimatedSprite() {
	//
}

int AnimatedSprite::init(Graphics &gfx, std::string & filepath, int srcX, int srcY, int width, int height, float posX, float posY, float timeToUpd) {
	_timeToUpd = timeToUpd;
	return Sprite::init(gfx, filepath, srcX, srcY, width, height, posX, posY);
}

void AnimatedSprite::runAnimation(std::string aniName, bool once) {
	_currAnimationOnce = once;
	if (_currAnimation != aniName) {
		_currAnimation = aniName;
		_frameIdx = 0;
	}
}

void AnimatedSprite::update(float elapsedTime) {
	_timeElapsed += elapsedTime;
	if (_timeElapsed >= _timeToUpd) {
		_timeElapsed = 0;
		_frameIdx = (_frameIdx + 1) % _animations[_currAnimation].size();
		if (!_frameIdx) {
			setVisible(false);
			animationDone();
		}
	}
}

int AnimatedSprite::addToGfx(Graphics &gfx, int x, int y) {
	SDL_Rect destRect;
	SDL_Rect currRect = _animations[_currAnimation].at(_frameIdx);
	destRect.x = x + _offsets[_currAnimation]._x;
	destRect.y = y + _offsets[_currAnimation]._y;

	destRect.h = currRect.h * constants::scale;
	destRect.w = currRect.w * constants::scale;

	return gfx.placeSprite(_spriteSheet, &currRect, &destRect);
}

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string &name, int width, int height, Point offset) {
	
	_animations[name] = {};
	
	int i;
	for (i = 0; i < frames; i++) {
		SDL_Rect r = { (i + x) * width, y, _srcRect.w, _srcRect.h };
		_animations[name].push_back(r);
	}
	_offsets[name] = offset;
}

void AnimatedSprite::resetAnimations() {
	_animations.clear();
	_offsets.clear();
}

void AnimatedSprite::stopAnimation() {
	animationDone();
	_frameIdx = 0;
}

void AnimatedSprite::setVisible(bool visible) {
	_visible = visible;
}