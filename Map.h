#pragma once
#include <vector>
#include <iostream>
#include <windows.h>

#include "Level.h"
#include "Player.h"


class Map
{
public:
	void loadMap(int wLevel);
	void loadLevels();
	void clearMap();
	void transformLevel(int newLevel);
	void hideCursor(bool mk_visible);
	void startLevel(int level_id, Player &player);
	void sleep(int numeric);

	// Public Variables
	bool NEED_STOP = false;
	int CURRENT_LEVEL = 0;
	int MAX_LEVELS = 2;

private:
	std::vector<Level*> level;
};

