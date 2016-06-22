#pragma once

#include "Sprite.h"
#include "Point.h"
#include <unordered_map>
#include <vector>

class Graphics;

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(float timeToUpd);
	virtual ~AnimatedSprite();

	void runAnimation(std::string aniName, bool once = false);
	void update(float elapsedTime);
	int addToGfx(Graphics &gfx, int x, int y);

	virtual void setAnimations();
private:
	std::unordered_map<std::string, std::vector<SDL_Rect>> _animations;
	std::unordered_map<std::string, Point> _offsets;
	int _frameIdx;
	double _timeElapsed;
	bool _visible;
protected:
	double _timeToUpd;
	bool _currAnimationOnce;
	std::string _currAnimation;

	void addAnimation(int frames, int x, int y, std::string &name, int width, int height, Point offset);
	void resetAnimations();
	void stopAnimation();
	void setVisible(bool visible);
	virtual void animationDone();
};