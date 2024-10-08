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
	//各クラスの初期化関数を呼び出す
	game()->playerBulletsInst()->init();
	game()->playerInst()->init();
	game()->enemyBulletsInst()->init();
	game()->enemiesInst()->init();
	game()->bossBulletsInst()->init();
	game()->bossInst()->init();
	game()->itemInst()->init();
	//文字の設定
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
		game()->playerBulletsInst()->powerDownBullets();	//PLAYERの弾を通常時に設定
		SetBackgroundColor(50, 100, 50, 128);	//あとでかえる
	}
	else if (!CheckHitKey(KEY_INPUT_Z)) {
		ChangeStopFlag = false;
	}
	if (game()->playerInst()->hp()<=0) {
		game()->changeScene(GAME::GAME_OVER_ID);
		ChangeStopFlag = true;
		game()->playerBulletsInst()->powerDownBullets();	//PLAYERの弾を通常時に設定
		SetBackgroundColor(50, 100, 50, 128);
	}
}

void STAGE::draw() {
	ClearDrawScreen();
	WaterFallArt.perform();		//背景の線を描画。DXライブラリの仕様上、背景から描写して
	game()->draw();				//その他の物体を描画する事によってレイヤーを設定する
	DrawStringFToHandle(Stage.pos.x, Stage.pos.y, Stage.moveMessage,
		Stage.textColor, Stage.messageFont);
	DrawStringFToHandle(Stage.pos.x, Stage.pos.y + Stage.textSize, Stage.shotMessage,
		Stage.textColor, Stage.messageFont);
	ScreenFlip();
}