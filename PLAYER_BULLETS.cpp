#include "CONTAINER.h"
#include "GAME.h"
#include "PLAYER_BULLETS.h"

PLAYER_BULLETS::PLAYER_BULLETS(GAME* game) :
	BULLETS(game){
}
void PLAYER_BULLETS::create() {
	SetBullets(game()->container()->playerBulletData());
}

//Item�擾�Œe������
void PLAYER_BULLETS::powerUpBullets(){
	game()->container()->playerBulletData().exRate *= 3;
	game()->container()->playerBulletData().bcRadius *= 3;
	game()->container()->playerBulletData().advSpeed *= 3;
	game()->container()->playerBulletData().damage *= 3;
	//PLAYER�̒e�̃f�[�^���X�V
	game()->playerBulletsInst()->create();
}

//���������e�����ɖ߂�
void PLAYER_BULLETS::powerDownBullets(){
	game()->container()->playerBulletData().exRate = 1.0;
	game()->container()->playerBulletData().bcRadius = 10;
	game()->container()->playerBulletData().advSpeed = 10;
	game()->container()->playerBulletData().damage = 1;
	//PLAYER�̒e�̃f�[�^���X�V
	game()->playerBulletsInst()->create();
}