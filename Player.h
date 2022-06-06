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
private:
	int last_key_pressd{ 0 };
};

