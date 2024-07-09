#include "CONTAINER.h"
#include "GAME.h"
#include "ENEMY_BULLETS.h"
#include "PLAYER_BULLETS.h"
#include "HP_GAUGE.h"
#include "ENEMIES.h"
#include <cmath>
//�΂��`
#define pi 3.141592f

ENEMIES::ENEMIES(GAME* game):
	GAME_OBJECT(game),Enemies(0){
}
ENEMIES::~ENEMIES(){
	delete[] Enemies;
}

void ENEMIES::create(){
	Enemy = game()->container()->enemyData();
	Enemies = new ENEMY[Enemy.totalNum];		//�ő吔�����|�C���^�z������
}

void ENEMIES::init(){
	Enemy.centerPos = game()->container()->enemyData().centerPos;
	//�G�̈ʒu��divTheta�����ϓ��ɒ��S���W���炸��ĕ`�悳���ׂ̐ݒ�
	float divTheta = pi * 2 / Enemy.totalNum;		
	//�e�̔��ˊԊu��G���Ƃɂ��炷�ׂɂ��̊Ԋu��ݒ�
	float divInterval = Enemy.triggerInterval /Enemy.totalNum;

	for (int i = 0; i < Enemy.totalNum; i++) {
		Enemies[i].ofstTheta = divTheta * i;				//�`��ʒu�̒��S����̊p�x
		Enemies[i].triggerErapsedTime = divInterval * i;	//�e�̔��ˊԊu�܂ł̌o�ߎ���
		Enemies[i].invincibleRestTime = 0;
		Enemies[i].hp = Enemy.initHp;
	}
	Enemy.curNum = Enemy.totalNum;		//�G�̕���
}

void ENEMIES::update() {
	move();
	collision();
	launch();
}

void ENEMIES::move(){
	//targetPosY�܂Œ��S���W���~�낷
	if (Enemy.centerPos.y < Enemy.targetPosY) {
		Enemy.centerPos.y += Enemy.fallSpeed;
	}
	//���݂̓G�̐��������[�v������
	for (int i = 0; i < Enemy.curNum; i++) {
		float theta = Enemy.refTheta + Enemies[i].ofstTheta;
		//�ȉ~�̎���̍��W��px,py�Ō��肵�A���ꂼ��̓G�̍��W��
		float px = Enemy.centerPos.x + cosf(theta) * Enemy.majRadius;
		float py = Enemy.centerPos.y + sinf(theta) * Enemy.minRadius;
		Enemies[i].pos.x = px;
		Enemies[i].pos.y = py;
		if (theta > 2 * pi)theta -= 2 * pi;		//theta���ی��Ȃ������Ȃ��悤��
	}
	Enemy.refTheta += Enemy.thetaSpeed;				//���������W�����炷
}

void ENEMIES::collision() {
	PLAYER_BULLETS* bullets = game()->playerBulletsInst();		//PLAYER�̒e�̃|�C���^��p��(�ǂ݂₷��)
	float distance = Enemy.bcRadius + bullets->bcRadius();		//PLAYER�̒e��ENEMY�̋���
	float sqDistance = distance * distance;		//��Βl�ł͂Ȃ������̓����g��(�v�Z�ʂ̍팸)
	//�G�̐�������������(�z��Ȃ̂Ō�납�烋�[�v���č폜���̏������ȒP�ɂ���)
	for (int j = Enemy.curNum - 1; j >= 0; j--) {
		//���G���Ԃ����炷����
		if (Enemies[j].invincibleRestTime > 0) {
			Enemies[j].invincibleRestTime -= 1.0f;
		}
		//���G����Ȃ����̏���
		else {
			//��ʏ��PLAYER�̒e�̐����������蔻����v�Z
			for (int i = bullets->curNum() - 1; i >= 0; i--) {
				VECTOR2 vec = Enemies[j].pos - bullets->pos(i);
				//sqLength(vec)�Ńx�N�g���̑傫���̓����v�Z
				if (sqLength(vec) < sqDistance) {
					Enemies[j].hp-=game()->container()->playerBulletData().damage;
					Enemies[j].invincibleRestTime = Enemy.invincibleTime;
					//�����Enemies[j]��hp0�ɂȂ����Ƃ����݂̓G�̐�������
					if (Enemies[j].hp <= 0) {
						Enemy.curNum--;
						//hp��0�ɂȂ����炻�̓G�̔z���Enemies[curNum]�̏��ŏ㏑������B
						//curNum�����邱�Ƃɂ�莟�̃��[�v�ŏ�����Enemies[Enemy.curNum]��ۑ����A
						//hp���[���ɂȂ����z��̏����������Ƃ��ł���B
						Enemies[j] = Enemies[Enemy.curNum];
					}
					bullets->kill(i);		//���������e���폜(��L�̂��̂Ǝ����㏑�����������Ă���)
					i = 0;					//���[�v�𔲂���
				}
			}
		}
	}
}

void ENEMIES::launch() {
	VECTOR2 playerPos = game()->playerInst()->pos();
	//�G�̐��������[�v
	for (int i = 0; i < Enemy.curNum; i++) {
		Enemies[i].triggerErapsedTime += 1.0f;
		//�o�ߎ��Ԃ����˂܂ł̃C���^�[�o���𒴂����Ƃ��̏���
		if (Enemies[i].triggerErapsedTime >= Enemy.triggerInterval) {
			//���˕����̐ݒ�(normalize�̓x�N�g���̐��K��)
			VECTOR2 launchVec = normalize(playerPos - Enemies[i].pos);
			//���ˈʒu�̐ݒ�(ofstLaunchDist�œG�̐^�񒆂�菭�����ɂȂ�悤����)
			VECTOR2 pos = Enemies[i].pos + launchVec * Enemy.ofstLaunchDist;
			game()->enemyBulletsInst()->launch(pos, launchVec);		//���ˈʒu�A������n��
			Enemies[i].triggerErapsedTime = 0;
		}
	}
}

void ENEMIES::draw(){
	for (int i = 0; i < Enemy.curNum; i++) {
		DrawRotaGraphF(Enemies[i].pos.x, Enemies[i].pos.y,Enemy.exRate, Enemy.angle, Enemy.img, TRUE);
		game()->hpGaugeInst()->draw(Enemies[i].pos, Enemy.hpGaugeOfst, Enemies[i].hp);
	}
}
