#include "Map.h"
#include "Player.h"

int main() {
	Map mGame;
	mGame.loadLevels();
	mGame.hideCursor(false);

	Player mPlayer;

	while (!mGame.NEED_STOP) {
		
		mGame.clearMap();
		mGame.loadMap(mGame.CURRENT_LEVEL);
		

		// Starting a Level
		if (mGame.CURRENT_LEVEL == 1) mGame.startLevel(1, mPlayer);


		// Checking the Menu
		if (mPlayer.checkKeyOnce('1') && mGame.CURRENT_LEVEL == 0) {
			mGame.transformLevel(1);
		}

		if (mPlayer.checkKeyOnce('2') && mGame.CURRENT_LEVEL == 0) {
			mGame.NEED_STOP = true;
			break;
		}
	}
	return 0;
}