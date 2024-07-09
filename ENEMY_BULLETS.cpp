#include "CONTAINER.h"
#include "GAME.h"
#include "ENEMY_BULLETS.h"

ENEMY_BULLETS::ENEMY_BULLETS(GAME* game) :
	BULLETS(game) {
}
void ENEMY_BULLETS::create() {
	SetBullets(game()->container()->enemyBulletData());	//SetBullets‚ÍBULLETSƒNƒ‰ƒX‚Ìƒƒ“ƒoŠÖ”
}
