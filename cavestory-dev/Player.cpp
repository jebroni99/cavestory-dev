#include "Player.h"
#include "Graphics.h"

Player::Player() : AnimatedSprite(),
_walkSpeed(0.2f),
_facing(UP)
{
}

Player::~Player() {
	//
}

int Player::init(Graphics &gfx, float x, float y) {
	std::string s = "../data/MyChar.png";
	if (gfx.loadImage(s) == NULL)
		return 1;
	if (AnimatedSprite::init(gfx, s, 0, 0, 16, 16, x, y, 100) != 0)
		return 1;
	setAnimations();
	std::string aniName = "run right";
	moveRight();
	return 0;
}

void Player::setAnimations() {
	std::string s = "run left";
	addAnimation(3, 0, 0, s, 16, 16, Point(0, 0));
	s = "run right";
	addAnimation(3, 0, 16, s, 16, 16, Point(0, 0));
	s = "idle left";
	addAnimation(1, 0, 0, s, 16, 16, Point(0, 0));
	s = "idle right";
	addAnimation(1, 0, 16, s, 16, 16, Point(0, 0));
}

void Player::animationDone() {
	//
}

void Player::update(float elapsedTime) {
	_x += _dx * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

int Player::addToGfx(Graphics &gfx) {
	return AnimatedSprite::addToGfx(gfx, _x, _y);
}

void Player::moveLeft() {
	if (_facing == LEFT && _dx < 0)
		return;
	_dx = -_walkSpeed;
	runAnimation("run left");
	_facing = LEFT;
}

void Player::moveRight() {
	if (_facing == RIGHT && _dx > 0)
		return;
	_dx = _walkSpeed;
	runAnimation("run right");
	_facing = RIGHT;
}

void Player::stopMoving() {
	_dx = 0.0f;
	if (_facing == LEFT)
		runAnimation("idle left");
	else
		runAnimation("idle right");
}
