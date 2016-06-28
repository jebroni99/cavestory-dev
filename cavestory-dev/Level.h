#pragma once

#include <string>
#include <vector>
#include "Point.h"
#include "Tile.h"
#include "tinyxml2.h"

class Graphics;
struct SDL_Rect;
struct TileSet;
struct SDL_Texture;

using namespace tinyxml2;

class Level {
public:
	Level();
	Level(std::string &mapName, Point spawnPt);
	~Level();

	int init(Graphics & gfx);
	void update(float elapsedTime);
	int addToGfx(Graphics &gfx);

private:
	std::string _mapName;
	Point _spawnPoint;
	Point _size;
	Point _tileSize;
	SDL_Texture *_bgTexture;

	int loadMap(std::string mapName, Graphics &gfx);

	int loadMap(std::string &mapName, XMLDocument *doc);
	void setSizes(XMLElement *mapNode);
	int loadTileSets(XMLElement *tileSetNode, Graphics &gfx);
	void appendToTileList(XMLElement *tileNode);

	std::vector<Tile> _tileList;
	std::vector<TileSet> _tileSets;
	std::vector<SDL_Rect> _colRects;
};

struct TileSet {
	SDL_Texture *_texture;
	int _firstGid;
	int _columns;
	int _rows;
	int _tileWidth;
	int _tileHeight;

	TileSet() {
		_firstGid = -1;
		_columns = -1;
		_rows = -1;
		_tileWidth = -1;
		_tileHeight = -1;
	}

	TileSet(SDL_Texture *texture, int firstGid, int col, int row, int pixW, int pixH) {
		_texture = texture;
		_firstGid = firstGid;
		_columns = col;
		_rows = row;
		_tileWidth = pixW;
		_tileHeight = pixH;
	}
};