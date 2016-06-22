#pragma once

namespace constants {
	const int screenWidth = 640;
	const int screenHeight = 480;
	const int scale = 4;
}

struct Vector2 {
	int x, y;
	Vector2() :
		x(0), y(0)
	{}

	Vector2(int x, int y) :
		x(x), y(y)
	{}

	Vector2 zero() {
		return Vector2(0, 0);
	}
};