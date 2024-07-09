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
	game()->enemiesInst()->move();		//”­ŽË(launch)‚Æ“–‚½‚è”»’è(collision)‚Ís‚í‚È‚¢B
	game()->bossInst()->move();			//“¯ã
	game()->playerInst()->zoom();		//PLAYER‚ðŠg‘å‚³‚¹‚é
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
		SetBackgroundColor(50, 50, 150, 128);			//TITLE‚Ì”wŒiF
		game()->changeScene(GAME::STAGE_ID);
		ChangeStopFlag = true;
	}
	else if (!CheckHitKey(KEY_INPUT_Z)) {
		ChangeStopFlag = false;
	}
}