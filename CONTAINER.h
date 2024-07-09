#pragma once
#include "TITLE.h"
#include "STAGE.h"
#include "GAME_CLEAR.h"
#include "GAME_OVER.h"
#include "PLAYER.h"
#include "ENEMIES.h"
#include "BOSS.h"
#include "BULLETS.h"
#include "HP_GAUGE.h"
#include "ITEM.h"

//CONTAINER�͊e�N���X�Ɏ�������f�[�^���܂Ƃ߂Ă���N���X

class CONTAINER{
private:
	struct DATA {
		TITLE::DATA title;
		STAGE::DATA stage;
		GAME_CLEAR::DATA gameClear;
		GAME_OVER::DATA gameOver;
		PLAYER::DATA player;
		ENEMIES::DATA enemy;
		BOSS::DATA boss;
		BULLETS::DATA playerBullet;
		BULLETS::DATA enemyBullet;
		BULLETS::DATA bossBullet;
		HP_GAUGE::DATA hpGauge;
		ITEM::DATA item;
	};
	DATA Data;
//�Q�Ƃɂ��邱�ƂŒ��ڃA�N�Z�X�ł���B
//Data�̃f�[�^�͊e�N���X��private��DATA�ɑ�������B
public:
	TITLE::DATA& titleData() { return Data.title; }
	STAGE::DATA& stageData() { return Data.stage; }
	GAME_CLEAR::DATA& gameClearData() { return Data.gameClear; }
	GAME_OVER::DATA& gameOverData() { return Data.gameOver; }
	PLAYER::DATA& playerData() { return Data.player; }
	ENEMIES::DATA& enemyData() { return Data.enemy; }
	BOSS::DATA& bossData() { return Data.boss; }
	BULLETS::DATA& playerBulletData() { return Data.playerBullet; }
	BULLETS::DATA& enemyBulletData() { return Data.enemyBullet; }
	BULLETS::DATA& bossBulletData() { return Data.bossBullet; }
	HP_GAUGE::DATA& hpGaugeData() { return Data.hpGauge; }
	ITEM::DATA& itemData() { return Data.item; }
//�f�[�^��ǂݍ��ފ֐�
public:
	void load();				//���L��2�̊֐������s����B�Q�[�����[�v�ɓ���O�ɌĂяo�����
		void setData();			//�f�[�^�̐ݒ�
		void loadGraphic();		//�摜���������փ��[�h
//��ʂ̕��ƍ���
public:
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
	int getScreenWidth()const { return SCREEN_WIDTH; } //��ʂ̉�����Ԃ��Q�b�^�[�֐�
	int getScreenHeight() const { return SCREEN_HEIGHT; } //��ʂ̏c����Ԃ��Q�b�^�[�֐�
};

