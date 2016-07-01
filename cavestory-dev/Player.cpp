#include "Player.h"
#include "Graphics.h"
#include <algorithm>
#include "Rectangle.h"

Player::Player() {
	//
}

Player::Player(Point spawnPoint) :
AnimatedSprite(std::string("../data/MyChar.png"), 0, 0, 16, 16, spawnPoint._x, spawnPoint._y, 100),
_walkSpeed(0.2f),
_facing(RIGHT),
_grounded(false),
_gravity(0.002f),
_maxGravity(0.8f),
_dx(0),
_dy(0)
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
	if (_dy <= _maxGravity) {
		_dy = std::min(_dy + elapsedTime * _gravity, _maxGravity);
	}

	_y += _dy * elapsedTime;
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

const float Player::getX() const {
	return _x;
}

const float Player::getY() const {
	return _y;
}

void Player::handleTileCollisions(std::vector<Rectangle> &others) {
	int otherSize = others.size();
	int i;
	for (i = 0; i < otherSize; i++) {
		sides::Side colSide = getCollisionSide(others.at(i));
		switch (colSide){
		case sides::TOP:
			_y = others.at(i).getBottom() + 1;
			_dy = 0;
			break;
		case sides::LEFT:
			_x = others.at(i).getRight() + 1;
			_dx = 0;
			break;
		case sides::BOTTOM:
			_y = others.at(i).getTop() - getBoundingBox().getHeight() - 1;
			_dy = 0;
			_grounded = true;
			break;
		case sides::RIGHT:
			_x = others.at(i).getLeft() - getBoundingBox().getWidth() - 1;
			break;
		}
	}
}
