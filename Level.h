#pragma once
#include <iostream>
#include <string>
class Level
{
public:
	Level(std::string file_name);
	void loadLevel();
	void constructLevel(std::string file_name);
	void updateIJ(int i, int j, char c_value);

private:
	char level_stage[9][30] {" "};
};

