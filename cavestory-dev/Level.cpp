#include "Level.h"
#include "Graphics.h"
#include "SDL.h"
#include "Constants.h"
#include <sstream>
#include <algorithm>
#include <cmath>

Level::Level() {
}

Level::Level(std::string &mapName, Point spawnPoint) :
_mapName(mapName),
_spawnPoint(spawnPoint),
_size(Point()),
_tileSize(Point())
{
}

Level::~Level() {
}

int Level::init(Graphics &gfx) {
	return loadMap(_mapName, gfx);
}

void Level::update(float elapsedTime) {
}

int Level::addToGfx(Graphics &gfx) {
	int i;
	int tileListSize = _tileList.size();
	for (i = 0; i < tileListSize; i++) {
		if (_tileList.at(i).addToGfx(gfx))
			return 1;
	}

	return 0;
}

int Level::loadMap(std::string mapName, Graphics &gfx) {
	XMLDocument doc;

	if (loadMap(mapName, &doc))
		return 1;

	XMLElement *mapNode = doc.FirstChildElement("map");
	setSizes(mapNode);

	XMLElement *tileSetNode = mapNode->FirstChildElement("tileset");
	if (loadTileSets(tileSetNode, gfx))
		return 1;

	XMLElement *layerNode = mapNode->FirstChildElement("layer");
	while (layerNode) {
		XMLElement *dataNode = layerNode->FirstChildElement("data");
		while (dataNode) {
			XMLElement *tileNode = dataNode->FirstChildElement("tile");
			appendToTileList(tileNode);
			dataNode = dataNode->NextSiblingElement("data");
		}
		layerNode = layerNode->NextSiblingElement("layer");
	}
	return 0;
}

int Level::loadMap(std::string &mapName, XMLDocument *doc) {
	std::stringstream ss;
	ss << "../data/maps/" << mapName << ".tmx";
	return doc->LoadFile(ss.str().c_str());
}

void Level::setSizes(XMLElement *mapNode) {
	int width, height;
	mapNode->QueryIntAttribute("width", &width);
	mapNode->QueryIntAttribute("height", &height);

	_size = Point(width, height);

	int tileWidth, tileHeight;
	mapNode->QueryIntAttribute("tilewidth", &tileWidth);
	mapNode->QueryIntAttribute("tileheight", &tileHeight);

	_tileSize = Point(tileWidth, tileHeight);
}

int Level::loadTileSets(XMLElement *tileSetNode, Graphics &gfx) {
	while (tileSetNode) {
		int firstGid;
		int columns, tileCount;
		int tileWidth, tileHeight;
		const char *src = tileSetNode->FirstChildElement("image")->Attribute("source");
		std::stringstream ss;
		ss << "../data/maps/" << src;
		tileSetNode->QueryIntAttribute("firstgid", &firstGid);
		tileSetNode->QueryIntAttribute("columns", &columns);
		tileSetNode->QueryIntAttribute("tilecount", &tileCount);
		tileSetNode->QueryIntAttribute("tilewidth", &tileWidth);
		tileSetNode->QueryIntAttribute("tileheight", &tileHeight);
		SDL_Texture *tex = SDL_CreateTextureFromSurface(gfx.getRenderer(), gfx.loadImage(ss.str()));
		if (tex == NULL) {
			return 1;
		}
		_tileSets.push_back(TileSet(tex, firstGid, columns, tileCount / columns, tileWidth, tileHeight));

		tileSetNode = tileSetNode->NextSiblingElement("tileset");
	}
	return 0;
}

void Level::appendToTileList(XMLElement *tileNode) {
	int tileCount = -1;
	while (tileNode) {
		int gid;
		tileNode->QueryIntAttribute("gid", &gid);
		tileCount++;
		if (!gid) {
			tileNode = tileNode->NextSiblingElement("tile");
			continue;
		}
		TileSet tls;
		int i;
		int tileSetSize = _tileSets.size();
		for (i = 0; i < tileSetSize; i++) {
			tls = _tileSets.at(i);
			if (tls._firstGid <= gid) {
				break;
			}
		}
		if (tls._firstGid == -1) {
			tileNode = tileNode->NextSiblingElement("tile");
			continue;
		}

		int mapX, mapY;
		mapX = (tileCount % _size._x) * _tileSize._x;
		mapY = (tileCount / _size._x) * _tileSize._y;
		Point finalTilePos = Point(mapX, mapY);

		int tileSetX, tileSetY;
		tileSetX = ((gid - 1) % tls._columns) * tls._tileWidth;
		tileSetY = ((gid - 1) / tls._columns) * tls._tileHeight;
		Point finalTileSetPosition = Point(tileSetX, tileSetY);

		Tile tile(tls._texture, Point(tls._tileWidth, tls._tileHeight), finalTileSetPosition, finalTilePos);
		_tileList.push_back(tile);

		tileNode = tileNode->NextSiblingElement("tile");
	}
}