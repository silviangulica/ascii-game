#include "Map.h"
#include "Macros.h"

int main() {
	
	Map mGame;
	mGame.loadLevels();
	mGame.loadMap();

	while (!NEED_STOP) {

	}
	return 0;
}