#include "Rectangle.h"

Rectangle::Rectangle() {
}

Rectangle::Rectangle(int x, int y, int width, int height) :
_x(x),
_y(y),
_width(width),
_height(height)
{
}

const int Rectangle::getCenterX() const { return _x + _width / 2; }
const int Rectangle::getCenterY() const { return _y + _height / 2; }
const int Rectangle::getLeft() const { return _x; }
const int Rectangle::getRight() const { return _x + _width; }
const int Rectangle::getTop() const { return _y; }
const int Rectangle::getBottom() const { return _y + _height; }
const int Rectangle::getWidth() const { return _width; }
const int Rectangle::getHeight() const { return _height; }

const int Rectangle::getSide(sides::Side side) {
	switch (side) {
	case sides::LEFT:
		return getLeft();
	case sides::RIGHT:
		return getRight();
	case sides::TOP:
		return getTop();
	case sides::BOTTOM:
		return getBottom();
	}
	return -1;
}

bool Rectangle::collidesWith(Rectangle &other) {
	return getRight() >= other.getLeft() &&
		getLeft() <= other.getRight() &&
		getTop() <= other.getBottom() &&
		getBottom() >= other.getTop();
}

bool Rectangle::isRectangle() {
	return _x >= 0 && _y >= 0 && _width >= 0 && _height >= 0;
}
