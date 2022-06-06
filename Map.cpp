#include "Map.h"

void Map::loadLevels() {
	level.push_back(new Level("Levels/level_1.txt"));
	level.push_back(new Level("Levels/level_2.txt"));
}

void Map::loadMap(int wLevel) {
	level.at(wLevel)->loadLevel();
}

void Map::clearMap() {
	// Wait 10 nanoseconds
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1ms);
	
	COORD mouse_pos{ 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mouse_pos);
}

void Map::transformLevel(int newLevel) {
	if (newLevel < -1) {
		CURRENT_LEVEL = 0;
	}
	else if (newLevel >= MAX_LEVELS) {
		CURRENT_LEVEL = MAX_LEVELS - 1;
	}
	else {
		CURRENT_LEVEL = newLevel;
	}
}

void Map::hideCursor(bool mk_visible) {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = mk_visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Map::startLevel(int level_id, Player &player) {

	while (true) {
		if (player.checkKeyOnce(VK_RIGHT)) {
			player.coo_j++;
			level.at(level_id)->updateIJ(player.coo_i, player.coo_j, player.form);
			level.at(level_id)->updateIJ(player.coo_i, player.coo_j - 1, ' ');
			break;
		}
		if (player.checkKey(VK_LEFT)) {
			player.coo_j--;
			level.at(level_id)->updateIJ(player.coo_i, player.coo_j, player.form);
			level.at(level_id)->updateIJ(player.coo_i, player.coo_j + 1, ' ');
			break;
		}
	}

}