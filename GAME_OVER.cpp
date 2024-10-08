#include "DxLib.h"
#include "GAME.h"
#include "CONTAINER.h"
#include "PLAYER.h"
#include "ENEMIES.h"
#include "BOSS.h"
#include "PLAYER_BULLETS.h"
#include "ENEMY_BULLETS.h"
#include "BOSS_BULLETS.h"
#include "GAME_OVER.h"

GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game) {
}
GAME_OVER::~GAME_OVER() {
}

void GAME_OVER::init() {
	GameOver = game()->container()->gameOverData();
}

void GAME_OVER::update() {
	game()->playerBulletsInst()->update();
	game()->enemyBulletsInst()->update();
	game()->enemiesInst()->move();		//発射(launch)と当たり判定(collision)は行わない。
	game()->bossInst()->move();			//同上
	game()->playerInst()->zoom();		//PLAYERを拡大させる
}

void GAME_OVER::draw() {
	ClearDrawScreen();
	game()->draw();
	DrawStringFToHandle(GameOver.pos.x, GameOver.pos.y, GameOver.endMessage,
		GameOver.textColor, GameOver.messageFont);
	ScreenFlip();
}

void GAME_OVER::nextScene() {
	if (CheckHitKey(KEY_INPUT_Z) && !ChangeStopFlag) {
		SetBackgroundColor(50, 50, 150, 128);			//TITLEの背景色
		game()->changeScene(GAME::STAGE_ID);
		ChangeStopFlag = true;
	}
	else if (!CheckHitKey(KEY_INPUT_Z)) {
		ChangeStopFlag = false;
	}
}