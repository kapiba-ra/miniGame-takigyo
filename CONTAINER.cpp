#include "CONTAINER.h"
#include <string.h>

const int CONTAINER::SCREEN_HEIGHT = 480;
const int CONTAINER::SCREEN_WIDTH = 640;

void CONTAINER::load(){
	setData();
	loadGraphic();
}

void CONTAINER::setData(){
	//TITLEクラスの設定
	Data.title.textColor = GetColor(0, 0, 0);
	Data.title.textSize = 30;
	Data.title.pos.x = 240;
	Data.title.pos.y = 400;
	strcpy_s(Data.title.start, "Zでスタート");
	strcpy_s(Data.title.titleName, "滝行");
	Data.title.startFont = CreateFontToHandle("MS ゴシック", Data.title.textSize, 30);
	Data.title.titleNameFont = CreateFontToHandle("MS ゴシック", Data.title.textSize * 3, 30);
	Data.title.countTime = 0;

	//STAGEクラスの設定
	Data.stage.textColor = GetColor(255, 255, 255);
	Data.stage.textSize = 15;
	Data.stage.pos.x = 10;
	Data.stage.pos.y = 10;
	strcpy_s(Data.stage.moveMessage, "A,D : 移動");
	strcpy_s(Data.stage.shotMessage, "SPACE : 祈り玉を放つ");
	Data.stage.messageFont = CreateFontToHandle("MS ゴシック", Data.stage.textSize, 30);

	//GAME_CLEARクラスの設定
	Data.gameClear.textColor = GetColor(0, 0, 0);
	Data.gameClear.textSize = 30;
	Data.gameClear.pos.x = 200;
	Data.gameClear.pos.y = 200;
	Data.gameClear.messageFont = CreateFontToHandle("MS ゴシック", Data.gameClear.textSize, 30);
	strcpy_s(Data.gameClear.endMessage, "悟った！おめでとう");

	//GAME_OVERクラスの設定
	Data.gameOver.textColor = GetColor(0, 0, 0);
	Data.gameOver.textSize = 60;
	Data.gameOver.pos.x = 240;
	Data.gameOver.pos.y = 200;
	Data.gameOver.messageFont = CreateFontToHandle("MS ゴシック", Data.gameClear.textSize, 30);
	strcpy_s(Data.gameOver.endMessage, "再修業→Zキー");

	//PLAYERの弾
	Data.playerBullet.totalNum = 20;
	Data.playerBullet.curNum = 0;
	Data.playerBullet.advSpeed = 10;
	Data.playerBullet.angSpeed = 0;
	Data.playerBullet.bcRadius = 8;
	Data.playerBullet.exRate = 1.0;
	Data.playerBullet.angle = 0;
	Data.playerBullet.damage = 1;
	Data.playerBullet.sound.loadPlayerSound();
	
	//ENEMYの弾
	Data.enemyBullet.totalNum = 20;
	Data.enemyBullet.curNum = 0;
	Data.enemyBullet.advSpeed = 2;
	Data.enemyBullet.angSpeed = 0;
	Data.enemyBullet.bcRadius = 8;
	Data.enemyBullet.exRate = 1.0;
	Data.enemyBullet.angle = 0;
	Data.enemyBullet.damage = 1;

	//BOSSの弾
	Data.bossBullet.totalNum = 20;
	Data.bossBullet.curNum = 0;
	Data.bossBullet.advSpeed = 2;
	Data.bossBullet.angSpeed = 0;
	Data.bossBullet.bcRadius = 16;
	Data.bossBullet.exRate = 2.0;
	Data.bossBullet.damage = 2;

	//PLAYERクラスのデータ
	Data.player.angle = 0;
	Data.player.advSpeed = 5;
	Data.player.pos.x = SCREEN_WIDTH/2.0;
	Data.player.pos.y = SCREEN_HEIGHT*5.0/6.0;
	Data.player.exRate = 2.0;
	Data.player.limitW = 100;
	//PLAYERクラスで設定する弾に関するデータ
	Data.player.launchVec = VECTOR2(0, -1);
	Data.player.triggerErapsedTime = 0;
	Data.player.triggerInterval = 30.0f;
	Data.player.ofstLaunchDist = 8.0f;
	Data.player.bulletSE = playerBulletData().sound.pBulletSEget();
	//PLAYERの当たり判定
	Data.player.bcRadius = 14;
	Data.player.invincibleTime = 30.0f;
	Data.player.invincibleRestTime = 0;
	Data.player.hp = 5;
	Data.player.hpGaugeOfst = VECTOR2(0, 60);
	Data.player.hpColor = GetColor(0, 200, 0);

	//ENEMYクラスのデータ
	Data.enemy.totalNum = 1;					//デバック時に変更
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
	//ENEMYの当たり判定
	Data.enemy.bcRadius = 25;
	Data.enemy.invincibleTime = 10.0f;
	Data.enemy.initHp = 5;
	Data.enemy.hpGaugeOfst = VECTOR2(0, 30);
	Data.enemy.hpColor = GetColor(0, 200, 0);

	//BOSSクラスのデータ
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
	//BOSSの当たり判定
	Data.boss.bcRadius = 25;
	Data.boss.invincibleRestTime = 0;
	Data.boss.invincibleTime = 10.0f;
	Data.boss.hpGaugeOfst = VECTOR2(0, 30);
	Data.boss.hp = 3;
	Data.boss.hpColor = GetColor(0, 200, 0);
	
	
	//HPゲージ
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
