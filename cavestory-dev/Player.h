#pragma once

#include "AnimatedSprite.h"
#include "Constants.h"

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	~Player();

	virtual int init(Graphics &gfx, float x, float y);
	virtual void setAnimations();
	virtual void animationDone();
	virtual void update(float elapsedTime);
	int addToGfx(Graphics &gfx);

	void moveLeft();
	void moveRight();
	void stopMoving();
private:
	float _dx, _dy;
	Direction _facing;
	float _walkSpeed;
};