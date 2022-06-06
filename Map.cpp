#include "Map.h"

void Map::loadLevels() {
	level.push_back(new Level("Levels/level_1.txt"));
}

void Map::loadMap() {
	level.at(0)->loadLevel();
}
