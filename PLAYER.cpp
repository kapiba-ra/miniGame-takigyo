#include "CONTAINER.h"
#include "GAME.h"
#include "PLAYER_BULLETS.h"
#include "ENEMY_BULLETS.h"
#include "BOSS_BULLETS.h"
#include "PLAYER.h"

PLAYER::PLAYER(GAME* game):
	GAME_OBJECT(game){
}
PLAYER::~PLAYER(){
}

void PLAYER::create() {
	Player = game()->container()->playerData();
	screenWidth = game()->container()->getScreenWidth();
	
}

void PLAYER::init(){
	//�ĊJ���ɏ��������ׂ����̂ɂ��Ă�CONTAINER�̃f�[�^�ŏ�����
	Player.pos = game()->container()->playerData().pos;
	Player.hp = game()->container()->playerData().hp;
	Player.img = game()->container()->playerData().img;
	Player.bulletSE = game()->container()->playerData().bulletSE;
	Player.exRate = game()->container()->playerData().exRate;
	Player.invincibleRestTime = game()->container()->playerData().invincibleRestTime;	
}

void PLAYER::update() {
	move();
	launch();
	collision();
}

void PLAYER::move(){
	if (Player.pos.x > Player.limitW && CheckHitKey(KEY_INPUT_A)) {
		Player.pos.x += -Player.advSpeed;
	}
	if (Player.pos.x < screenWidth - Player.limitW && CheckHitKey(KEY_INPUT_D)) {
		Player.pos.x += Player.advSpeed;
	}
}
void PLAYER::launch() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		Player.triggerErapsedTime += 1;		//�P�t���[������1���Z
		//���ˊԊu���o�ߎ��Ԃ��������Ƃ��ɏ���
		if (Player.triggerErapsedTime >= Player.triggerInterval) {
			//���ˈʒupos�̐ݒ�(PLAYER�̒��S��菭����̍��W)
			VECTOR2 pos = Player.pos + Player.launchVec * Player.ofstLaunchDist;
			game()->playerBulletsInst()->launch(pos, Player.launchVec);		//���ˈʒu�A������n��
			Player.triggerErapsedTime = 0;
			//���ˉ���炷
			PlaySoundMem(Player.bulletSE, DX_PLAYTYPE_BACK);
		}
	}
	else {
		//�X�y�[�X�L�[������Ǝ��ɉ������u�Ԃɂ����e���o��悤�ɂ���B
		Player.triggerErapsedTime = Player.triggerInterval; 
	}
}

void PLAYER::collision() {					//�摜�̐؂�ւ��ȊO�͓G�̓����蔻��Ǝ��Ă���
	if (Player.invincibleRestTime > 0) {
		Player.invincibleRestTime -= 1.0f;
		Player.graphic = Player.hitImg;		//���G���Ԓ���hit��Ԃ̉摜
	}
	else{
		//BOSS���U�����n�߂�ƁABOSS�̒e�ɂ��Ă̓����蔻����s���B
		BULLETS* bullets;
		if (game()->enemiesInst()->curNum() >= 1) { bullets = game()->enemyBulletsInst(); }
		else { bullets = game()->bossBulletsInst(); }
		//�����蔻��̍ő勗���ƁA���̂Q����v�Z
		float distance = Player.bcRadius + bullets->bcRadius();
		float sqDistance = distance * distance;
		Player.graphic = Player.img;		//���G���ԂłȂ��Ƃ��͒ʏ펞�̉摜
		for (int i = bullets->curNum() - 1; i >= 0; i--) {
			VECTOR2 vec = Player.pos - bullets->pos(i);
			if (sqLength(vec) < sqDistance) {
				Player.hp -= bullets->damage();
				Player.invincibleRestTime = Player.invincibleTime;
				bullets->kill(i);
				i = 0;
			}
		}
	}
}

void PLAYER::zoom(){
	if (Player.img != Player.awakenImg) {
		Player.img = Player.awakenImg;		//�����I��PLAYER���o����Ԃ̉摜��
	}
	if (Player.exRate < 6.0) {
		Player.exRate += 0.1f;		//�摜�̊g��(�����t��)
	}
}

void PLAYER::draw(){
	DrawRotaGraphF(Player.pos.x, Player.pos.y, Player.exRate, Player.angle, Player.graphic, TRUE);
	game()->hpGaugeInst()->draw(Player.pos, Player.hpGaugeOfst, Player.hp);
}

void PLAYER::itemHit(){
	//�ʏ펞�摜��ITEM�l�����̉摜�ɍ����ւ���
	Player.img = Player.awakenImg;
	//Item�擾��Ԃ�SE�ɐ؂�ւ���
	Player.bulletSE = game()->container()->playerBulletData().sound.upBulletSEget();
}
