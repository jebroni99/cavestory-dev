#pragma once

#include "AnimatedSprite.h"
#include "Constants.h"

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	Player(float x, float y);
	~Player();

	virtual int init(Graphics &gfx);
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