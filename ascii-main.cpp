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

		if (mPlayer.checkKeyOnce(VK_RIGHT)) mGame.transformLevel(1);
		if (mPlayer.checkKeyOnce(VK_LEFT)) mGame.transformLevel(0);
	}
	return 0;
}