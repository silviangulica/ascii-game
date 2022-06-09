#include "Map.h"

void Map::loadLevels() {
	level.push_back(new Level("Levels/level_1.txt"));
	level.push_back(new Level("Levels/level_2.txt"));
}

void Map::loadMap(int wLevel) {
	level.at(wLevel)->loadLevel();
}

void Map::clearMap() {
	// Wait 1ms
	sleep(1);
	
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

	bool stop_level_update = false;
	while (!stop_level_update) {
		if (player.checkKeyOnce(VK_RIGHT)) {

			// Colising system
			sleep(1);
			if (level.at(level_id)->checkColide(player.coo_i, player.coo_j + 1)) break;


			player.inc_righ += 0.40;

			if (player.inc_righ >= 1) {
				player.inc_righ = 1 - player.inc_righ;
				player.coo_j++;
				level.at(level_id)->updateIJ(player.coo_i, player.coo_j, player.form);
				level.at(level_id)->updateIJ(player.coo_i, player.coo_j - 1, ' ');
				break;
			}

		}
		if (player.checkKey(VK_LEFT)) {
			// Colising system
			sleep(1);
			if (level.at(level_id)->checkColide(player.coo_i, player.coo_j - 1)) break;

			player.inc_left += 0.40;
			if (player.inc_left >= 1) {
				player.inc_left = 1 - player.inc_left;
				player.coo_j--;
				level.at(level_id)->updateIJ(player.coo_i, player.coo_j, player.form);
				level.at(level_id)->updateIJ(player.coo_i, player.coo_j + 1, ' ');
				break;
			}
		}

		if (player.checkKey(VK_UP)) {
			// Colising system
			sleep(1);
			if (level.at(level_id)->checkColide(player.coo_i - 1, player.coo_j)) break;

			player.inc_up += 0.35;
			if (player.inc_up >= 1) {
				player.inc_up = 0;
				player.coo_i--;
				level.at(level_id)->updateIJ(player.coo_i, player.coo_j, player.form);
				level.at(level_id)->updateIJ(player.coo_i + 1, player.coo_j, ' ');
				break;
			}
		}

		if (player.checkKey(VK_DOWN)) {
			// Colising system
			sleep(1);
			if (level.at(level_id)->checkColide(player.coo_i + 1, player.coo_j)) break;

			player.inc_down += 0.5;

			if (player.inc_down >= 0) {
				player.inc_down = 0;
				player.coo_i++;
				level.at(level_id)->updateIJ(player.coo_i, player.coo_j, player.form);
				level.at(level_id)->updateIJ(player.coo_i - 1, player.coo_j, ' ');
				sleep(1);
				break;
			}
		}
		
	}

}

void Map::sleep(int numeric) {
	Sleep(numeric);
}