#pragma once
#include <Windows.h>
class Player
{
public:
	bool checkKey(int Key);
	bool checkKeyOnce(int Key);


	int coo_i{ 7 };
	int coo_j{ 3 };
	char form{ '8' };
	float inc_righ = 0;
	float inc_down = 0;
	float inc_up = 0;
	float inc_left = 0;

private:
	int last_key_pressd{ 0 };

	// Player Stats
	double health{ 1000 };
	double damage{ 10 };
	int level{ 1 };
	double experience{ 0 };
};

