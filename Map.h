#pragma once
#include <vector>
#include <iostream>
#include "Level.h"


class Map
{
public:
	void loadMap();
	void loadLevels();

private:
	std::vector<Level*> level;
};

