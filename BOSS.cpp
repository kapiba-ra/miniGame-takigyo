#include "BOSS.h"
#include "CONTAINER.h"
#include "GAME.h"
#include "BOSS_BULLETS.h"

BOSS::BOSS(GAME* game) : 
	GAME_OBJECT(game){
}
BOSS::~BOSS(){
}

void BOSS::create(){
	Boss = game()->container()->bossData();
}

void BOSS::init(){
	Boss.hp = game()->container()->bossData().hp;
	Boss.pos = game()->container()->bossData().pos;
	Boss.angle = game()->container()->bossData().angle;
}

void BOSS::update(){
	//ENEMY�̐���0�ɂȂ�����Ăяo��
	if (game()->enemiesInst()->curNum() <= 0) {
		move();
		collision();
		//�e�̔��˂�targetPosY�ɓ��B���Ă���n�߂�
		if (Boss.pos.y >= Boss.targetPosY) {
			launch();
		}
	}
}

void BOSS::move() {
	//targetPosY�܂�y���W���~�낷
	if (Boss.pos.y <= Boss.targetPosY) {
		Boss.pos.y += Boss.ySpeed;
		Boss.invincibleRestTime = Boss.invincibleTime;
	}
	else {
		// y���W��targetPosY�ɒB�����ꍇ�A��ʂ����ɍs��������悤��
		if (Boss.pos.x >= CONTAINER::SCREEN_WIDTH || Boss.pos.x <= 0) {
			Boss.xSpeed = -Boss.xSpeed; // �ړ������𔽓]
		}
		Boss.pos.x += Boss.xSpeed;
	}
}

void BOSS::collision(){
	PLAYER_BULLETS* bullets = game()->playerBulletsInst();		//PLAYER�̒e�̃|�C���^
	float distance = Boss.bcRadius + bullets->bcRadius();		//PLAYER�̒e��BOSS�̓����蔻��ő勗��
	float sqDistance = distance * distance;						//���̂Q��
	//���G���Ԃ̎��̏���
	if (Boss.invincibleRestTime > 0) {
		Boss.invincibleRestTime -= 1.0f;
	}
	//���G����Ȃ����̏���
	else {
		//��ʏ��PLAYER�̒e�̐����������蔻����v�Z
		for (int i = bullets->curNum() - 1; i >= 0; i--) {
			VECTOR2 vec = Boss.pos - bullets->pos(i);		//BOSS��PLAYER�̒e�̋���
			if (sqLength(vec) < sqDistance) {				//(���̂Q��)< (�����蔻��ő勗���̂Q��)
				Boss.hp -= game()->container()->playerBulletData().damage;
				Boss.invincibleRestTime = Boss.invincibleTime;
				bullets->kill(i);		//���������e���폜(��L�̂��̂Ǝ����㏑�����������Ă���)
				i = 0;					//���[�v�𔲂���
			}
		}
	}
}

void BOSS::launch(){
	VECTOR2 playerPos = game()->playerInst()->pos();
	Boss.triggerErapsedTime += 1.0f;
	//�o�ߎ��Ԃ����˂܂ł̃C���^�[�o���𒴂����Ƃ��̏���
	if (Boss.triggerErapsedTime >= Boss.triggerInterval) {
		//���˕����̐ݒ�
		VECTOR2 launchVec = normalize(playerPos - Boss.pos);
		//���ˈʒu�̐ݒ�
		VECTOR2 pos = Boss.pos + launchVec * Boss.ofstLaunchDist;
		game()->bossBulletsInst()->launch(pos, launchVec);		//���ˈʒu�A������n��
		Boss.triggerErapsedTime = 0;
	}
}

void BOSS::rotate() {
	Boss.angle += 0.05f;
}

void BOSS::draw(){
	if (game()->enemiesInst()->curNum() <= 0) {
		DrawRotaGraphF(Boss.pos.x, Boss.pos.y, Boss.exRate, Boss.angle, Boss.img, TRUE);
		game()->hpGaugeInst()->draw(Boss.pos, Boss.hpGaugeOfst, Boss.hp);
	}
}
