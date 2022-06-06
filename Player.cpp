#include "Player.h"

bool Player::checkKey(int Key) {
	if (GetKeyState(Key) & 0x8000) {
		last_key_pressd = Key;
		return true;
	}
	else
	{
		last_key_pressd = 0;
		return false;
	}
}

bool Player::checkKeyOnce(int Key) {
	if ((GetKeyState(Key) & 0x8000) && last_key_pressd != Key) {
		last_key_pressd = Key;
		return true;
	}
	else if ((GetKeyState(Key) & 0x8000) && last_key_pressd == Key)
	{
		last_key_pressd = Key;
		return false;
	}
	else {
		last_key_pressd = 0;
		return false;
	}
}