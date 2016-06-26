#include "Player.h"
#include "Graphics.h"

Player::Player() {
	//
}

Player::Player(float x, float y) :
AnimatedSprite(std::string("../data/MyChar.png"), 0, 0, 16, 16, x, y, 100),
_walkSpeed(0.2f),
_facing(UP)
{
}

Player::~Player() {
	//
}

int Player::init(Graphics &gfx) {
	if (gfx.loadImage(_filepath) == NULL)
		return 1;
	if (AnimatedSprite::init(gfx) != 0)
		return 1;
	setAnimations();
	std::string aniName = "run right";
	moveRight();
	return 0;
}

void Player::setAnimations() {
	addAnimation(3, 0, 0, std::string("run left"), 16, 16, Point(0, 0));
	addAnimation(3, 0, 16, std::string("run right"), 16, 16, Point(0, 0));
	addAnimation(1, 0, 0, std::string("idle left"), 16, 16, Point(0, 0));
	addAnimation(1, 0, 16, std::string("idle right"), 16, 16, Point(0, 0));
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
