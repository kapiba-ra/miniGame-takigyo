#include "CONTAINER.h"
#include "GAME.h"
#include "BOSS_BULLETS.h"

BOSS_BULLETS::BOSS_BULLETS(GAME* game) :
	BULLETS(game){
}

void BOSS_BULLETS::create(){
	SetBullets(game()->container()->bossBulletData());	//SetBullets‚ÍBULLETSƒNƒ‰ƒX‚Ìƒƒ“ƒoŠÖ”
}

