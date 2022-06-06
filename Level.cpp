#include "Level.h"
#include <fstream>


Level::Level(std::string file_name) {
	this->constructLevel(file_name);
}


void Level::loadLevel() {
	// This will only show the level
	for (auto& x : level_stage) {
		for (auto y : x) {
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