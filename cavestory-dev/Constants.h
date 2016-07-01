#pragma once

namespace constants {
	const int screenWidth = 640;
	const int screenHeight = 480;
	const int scale = 2;
}

namespace sides {
	enum Side {
		TOP,
		LEFT,
		BOTTOM,
		RIGHT
	};
}

enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};