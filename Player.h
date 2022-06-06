#pragma once
#include <Windows.h>
class Player
{
public:
	bool checkKey(int Key);
	bool checkKeyOnce(int Key);

private:
	int last_key_pressd{ 0 };
};

