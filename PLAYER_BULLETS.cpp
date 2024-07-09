#include "CONTAINER.h"
#include "GAME.h"
#include "PLAYER_BULLETS.h"

PLAYER_BULLETS::PLAYER_BULLETS(GAME* game) :
	BULLETS(game){
}
void PLAYER_BULLETS::create() {
	SetBullets(game()->container()->playerBulletData());
}

//Itemæ“¾‚Å’e‚ğ‹­‰»
void PLAYER_BULLETS::powerUpBullets(){
	game()->container()->playerBulletData().exRate *= 3;
	game()->container()->playerBulletData().bcRadius *= 3;
	game()->container()->playerBulletData().advSpeed *= 3;
	game()->container()->playerBulletData().damage *= 3;
	//PLAYER‚Ì’e‚Ìƒf[ƒ^‚ğXV
	game()->playerBulletsInst()->create();
}

//‹­‰»‚µ‚½’e‚ğŒ³‚É–ß‚·
void PLAYER_BULLETS::powerDownBullets(){
	game()->container()->playerBulletData().exRate = 1.0;
	game()->container()->playerBulletData().bcRadius = 10;
	game()->container()->playerBulletData().advSpeed = 10;
	game()->container()->playerBulletData().damage = 1;
	//PLAYER‚Ì’e‚Ìƒf[ƒ^‚ğXV
	game()->playerBulletsInst()->create();
}