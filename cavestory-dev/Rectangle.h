#pragma once
#include "Constants.h"


class Rectangle {
public:
	Rectangle();
	Rectangle(int x, int y, int width, int height);

	const int getCenterX() const;
	const int getCenterY() const;
	const int getLeft() const;
	const int getRight() const;
	const int getTop() const;
	const int getBottom() const;
	const int getWidth() const;
	const int getHeight() const;
	const int getSide(sides::Side side);

	bool collidesWith(Rectangle &rect);
	bool isRectangle();
private:
	int _x;
	int _y;
	int _width;
	int _height;
};