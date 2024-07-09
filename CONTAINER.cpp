#include "CONTAINER.h"
#include <string.h>

const int CONTAINER::SCREEN_HEIGHT = 480;
const int CONTAINER::SCREEN_WIDTH = 640;

void CONTAINER::load(){
	setData();
	loadGraphic();
}

void CONTAINER::setData(){
	//TITLE�N���X�̐ݒ�
	Data.title.textColor = GetColor(0, 0, 0);
	Data.title.textSize = 30;
	Data.title.pos.x = 240;
	Data.title.pos.y = 400;
	strcpy_s(Data.title.start, "Z�ŃX�^�[�g");
	strcpy_s(Data.title.titleName, "��s");
	Data.title.startFont = CreateFontToHandle("MS �S�V�b�N", Data.title.textSize, 30);
	Data.title.titleNameFont = CreateFontToHandle("MS �S�V�b�N", Data.title.textSize * 3, 30);
	Data.title.countTime = 0;

	//STAGE�N���X�̐ݒ�
	Data.stage.textColor = GetColor(255, 255, 255);
	Data.stage.textSize = 15;
	Data.stage.pos.x = 10;
	Data.stage.pos.y = 10;
	strcpy_s(Data.stage.moveMessage, "A,D : �ړ�");
	strcpy_s(Data.stage.shotMessage, "SPACE : �F��ʂ����");
	Data.stage.messageFont = CreateFontToHandle("MS �S�V�b�N", Data.stage.textSize, 30);

	//GAME_CLEAR�N���X�̐ݒ�
	Data.gameClear.textColor = GetColor(0, 0, 0);
	Data.gameClear.textSize = 30;
	Data.gameClear.pos.x = 200;
	Data.gameClear.pos.y = 200;
	Data.gameClear.messageFont = CreateFontToHandle("MS �S�V�b�N", Data.gameClear.textSize, 30);
	strcpy_s(Data.gameClear.endMessage, "������I���߂łƂ�");

	//GAME_OVER�N���X�̐ݒ�
	Data.gameOver.textColor = GetColor(0, 0, 0);
	Data.gameOver.textSize = 60;
	Data.gameOver.pos.x = 240;
	Data.gameOver.pos.y = 200;
	Data.gameOver.messageFont = CreateFontToHandle("MS �S�V�b�N", Data.gameClear.textSize, 30);
	strcpy_s(Data.gameOver.endMessage, "�ďC�Ɓ�Z�L�[");

	//PLAYER�̒e
	Data.playerBullet.totalNum = 20;
	Data.playerBullet.curNum = 0;
	Data.playerBullet.advSpeed = 10;
	Data.playerBullet.angSpeed = 0;
	Data.playerBullet.bcRadius = 8;
	Data.playerBullet.exRate = 1.0;
	Data.playerBullet.angle = 0;
	Data.playerBullet.damage = 1;
	Data.playerBullet.sound.loadPlayerSound();
	
	//ENEMY�̒e
	Data.enemyBullet.totalNum = 20;
	Data.enemyBullet.curNum = 0;
	Data.enemyBullet.advSpeed = 2;
	Data.enemyBullet.angSpeed = 0;
	Data.enemyBullet.bcRadius = 8;
	Data.enemyBullet.exRate = 1.0;
	Data.enemyBullet.angle = 0;
	Data.enemyBullet.damage = 1;

	//BOSS�̒e
	Data.bossBullet.totalNum = 20;
	Data.bossBullet.curNum = 0;
	Data.bossBullet.advSpeed = 2;
	Data.bossBullet.angSpeed = 0;
	Data.bossBullet.bcRadius = 16;
	Data.bossBullet.exRate = 2.0;
	Data.bossBullet.damage = 2;

	//PLAYER�N���X�̃f�[�^
	Data.player.angle = 0;
	Data.player.advSpeed = 5;
	Data.player.pos.x = SCREEN_WIDTH/2.0;
	Data.player.pos.y = SCREEN_HEIGHT*5.0/6.0;
	Data.player.exRate = 2.0;
	Data.player.limitW = 100;
	//PLAYER�N���X�Őݒ肷��e�Ɋւ���f�[�^
	Data.player.launchVec = VECTOR2(0, -1);
	Data.player.triggerErapsedTime = 0;
	Data.player.triggerInterval = 30.0f;
	Data.player.ofstLaunchDist = 8.0f;
	Data.player.bulletSE = playerBulletData().sound.pBulletSEget();
	//PLAYER�̓����蔻��
	Data.player.bcRadius = 14;
	Data.player.invincibleTime = 30.0f;
	Data.player.invincibleRestTime = 0;
	Data.player.hp = 5;
	Data.player.hpGaugeOfst = VECTOR2(0, 60);
	Data.player.hpColor = GetColor(0, 200, 0);

	//ENEMY�N���X�̃f�[�^
	Data.enemy.totalNum = 1;					//�f�o�b�N���ɕύX
	Data.enemy.curNum = Data.enemy.totalNum;
	Data.enemy.majRadius = 250;
	Data.enemy.minRadius = 100;
	Data.enemy.exRate = 1.0;
	Data.enemy.angle = 0;
	Data.enemy.centerPos = VECTOR2(295, -200);
	Data.enemy.fallSpeed = 1;
	Data.enemy.targetPosY = 150;
	Data.enemy.refTheta = 0 ;
	Data.enemy.thetaSpeed = 0.01f;
	Data.enemy.triggerInterval= 40.0f;
	Data.enemy.ofstLaunchDist = 32.0f;
	//ENEMY�̓����蔻��
	Data.enemy.bcRadius = 25;
	Data.enemy.invincibleTime = 10.0f;
	Data.enemy.initHp = 5;
	Data.enemy.hpGaugeOfst = VECTOR2(0, 30);
	Data.enemy.hpColor = GetColor(0, 200, 0);

	//BOSS�N���X�̃f�[�^
	Data.boss.exRate = 1.0;
	Data.boss.angle = 0;
	Data.boss.pos.x = SCREEN_WIDTH / 2.0;
	Data.boss.pos.y = -100;
	Data.boss.xSpeed = 6;
	Data.boss.ySpeed = 1;
	Data.boss.targetPosY = 100;
	Data.boss.triggerErapsedTime = 0;
	Data.boss.triggerInterval = 30.0f;
	Data.boss.ofstLaunchDist = 32.0f;
	//BOSS�̓����蔻��
	Data.boss.bcRadius = 25;
	Data.boss.invincibleRestTime = 0;
	Data.boss.invincibleTime = 10.0f;
	Data.boss.hpGaugeOfst = VECTOR2(0, 30);
	Data.boss.hp = 3;
	Data.boss.hpColor = GetColor(0, 200, 0);
	
	
	//HP�Q�[�W
	Data.hpGauge.Color = 0;
	Data.hpGauge.safeColor = GetColor(0, 255, 0);
	Data.hpGauge.dangerColor = GetColor(255, 0, 0);
	Data.hpGauge.hpWidth = 10;
	Data.hpGauge.hpHeight = 5;
	
	//ITEM
	Data.item.active = true;
	Data.item.bcRadius = 14;
	Data.item.fallSpeed = 2;
	Data.item.limitW = 110;
	Data.item.pos.x = 0;
	Data.item.pos.y = -600;
	Data.item.exRate = 1;
	Data.item.angle = 0;
}

void CONTAINER::loadGraphic() {
	Data.player.img = LoadGraph("images\\player.png");
	Data.player.hitImg = LoadGraph("images\\hitPlayer.png");
	Data.player.awakenImg = LoadGraph("images\\awakenPlayer.png");
	Data.enemy.img = LoadGraph("images\\enemy.png");
	Data.boss.img = LoadGraph("images\\boss.png");
	Data.playerBullet.img = LoadGraph("images\\pBullet.png");
	Data.enemyBullet.img = LoadGraph("images\\eBullet.png");
	Data.bossBullet.img = LoadGraph("images\\bBullet.png");
	Data.item.img = LoadGraph("images\\item.png");
};
