#include "Level.h"
#include <fstream>
#include <Windows.h>


Level::Level(std::string file_name) {
	this->constructLevel(file_name);
}


void Level::loadLevel() {
	// This will only show the level
	// And will color with the proper ones

	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	for (auto& x : level_stage) {
		for (auto y : x) {

			switch (y) {
			case '1': case '2': case '3': case '4': case '0':
			case '8': case '5': case '6': case '7': case '9':
				SetConsoleTextAttribute(hC, 10);
				break;
			case '*':
				SetConsoleTextAttribute(hC, 9);
				break;
			case 'M':
				SetConsoleTextAttribute(hC, 12);
				break;
			default:
				SetConsoleTextAttribute(hC, 15);
			}

			std::cout << y;
		}
		std::cout << "\n";
	}
}

void Level::constructLevel(std::string file_name) {
	// The level shoul construct from a file.
	std::ifstream level(file_name);


	// Read the file
	std::string text_file_line;
	int _i{ 0 };
	int _j{ 0 };
	while (getline(level, text_file_line)) {
		_j = 0;
		for (auto s : text_file_line) {
			level_stage[_i][_j] = s;
			_j++;
		}
		_i++;
	}

	// Debug
	// std::cout << "_i" << _i << "\n";
	// std::cout << "_j" << _j;
	level.close();
}

void Level::updateIJ(int i, int j, char c_value) {
	level_stage[i][j] = c_value;
}

bool Level::checkColide(int i, int j) {
	if (level_stage[i][j] == ' ') return false;
	else return true;
}