#pragma once

#include "AnimatedSprite.h"
#include "Constants.h"

class Graphics;
class Rectangle;

class Player : public AnimatedSprite {
public:
	Player();
	Player(Point spawnPoint);
	~Player();

	virtual int init(Graphics &gfx);
	virtual void setAnimations();
	virtual void animationDone();
	virtual void update(float elapsedTime);
	int addToGfx(Graphics &gfx);

	void moveLeft();
	void moveRight();
	void stopMoving();

	const float getX() const;
	const float getY() const;

	void handleTileCollisions(std::vector<Rectangle> &others);
private:
	float _dx, _dy;
	Direction _facing;
	float _walkSpeed;
	float _gravity;
	float _maxGravity;
	bool _grounded;
};