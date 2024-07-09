#include "DxLib.h"
#include "GAME.h"
#include "CONTAINER.h"
#include "STAGE.h"
#include "PLAYER.h"
#include "PLAYER_BULLETS.h"
#include "ENEMIES.h"
#include "ENEMY_BULLETS.h"
#include "BOSS.h"
#include "BOSS_BULLETS.h"
#include "ITEM.h"

STAGE::STAGE(class GAME* game) :
	SCENE(game) {
}
STAGE::~STAGE() {
}

void STAGE::init() {
	//�e�N���X�̏������֐����Ăяo��
	game()->playerBulletsInst()->init();
	game()->playerInst()->init();
	game()->enemyBulletsInst()->init();
	game()->enemiesInst()->init();
	game()->bossBulletsInst()->init();
	game()->bossInst()->init();
	game()->itemInst()->init();
	//�����̐ݒ�
	Stage = game()->container()->stageData();
}

void STAGE::update() {
	game()->playerBulletsInst()->update();
	game()->playerInst()->update();
	game()->bossBulletsInst()->update();
	game()->bossInst()->update();
	game()->enemyBulletsInst()->update();
	game()->enemiesInst()->update();
	game()->itemInst()->update();
}

void STAGE::nextScene() {
	if (game()->bossInst()->hp()<=0) {
		game()->changeScene(GAME::GAME_CLEAR_ID);
		ChangeStopFlag = true;
		game()->playerBulletsInst()->powerDownBullets();	//PLAYER�̒e��ʏ펞�ɐݒ�
		SetBackgroundColor(50, 100, 50, 128);	//���Ƃł�����
	}
	else if (!CheckHitKey(KEY_INPUT_Z)) {
		ChangeStopFlag = false;
	}
	if (game()->playerInst()->hp()<=0) {
		game()->changeScene(GAME::GAME_OVER_ID);
		ChangeStopFlag = true;
		game()->playerBulletsInst()->powerDownBullets();	//PLAYER�̒e��ʏ펞�ɐݒ�
		SetBackgroundColor(50, 100, 50, 128);
	}
}

void STAGE::draw() {
	ClearDrawScreen();
	WaterFallArt.perform();		//�w�i�̐���`��BDX���C�u�����̎d�l��A�w�i����`�ʂ���
	game()->draw();				//���̑��̕��̂�`�悷�鎖�ɂ���ă��C���[��ݒ肷��
	DrawStringFToHandle(Stage.pos.x, Stage.pos.y, Stage.moveMessage,
		Stage.textColor, Stage.messageFont);
	DrawStringFToHandle(Stage.pos.x, Stage.pos.y + Stage.textSize, Stage.shotMessage,
		Stage.textColor, Stage.messageFont);
	ScreenFlip();
}