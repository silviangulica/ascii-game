#pragma once
#include <iostream>
#include <string>
class Level
{
public:
	Level(std::string file_name);
	void loadLevel();
	void constructLevel(std::string file_name);

private:
	char level_stage[9][30] {" "};
};

